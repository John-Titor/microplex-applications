#!python3
#
# Flash an MRS Microplex 7* device over CAN.
#

import argparse
import struct
from pathlib import Path
import can

ACK_ID = 0x1ffffff0
CMD_ID = 0x1ffffff1
RSP_ID = 0x1ffffff2
SREC_ID = 0x1ffffff3
DATA_ID = 0x1ffffff4

EEPROM_MAP = {
    'label_line_1': (0x08, 12),
    'part_number': (0x14, 12),
    'product_name': (0x20, 20),
    'label_line_2': (0x34, 8),
    'date': (0x3c, 10),
    'user_version': (0x6b, 20),
    'user_name': (0x7f, 30)
}


class MessageError(Exception):
    """a received message was not as expected"""
    pass


class ModuleError(Exception):
    """the module did something unexpected"""
    pass


class TXMessage(can.Message):
    """
    Abstract for messages that will be sent.

    Concrete classes set self._format and pass args to struct.pack()
    that format to __init__.
    """
    def __init__(self, arbitration_id, *args):
        super().__init__(arbitration_id=arbitration_id,
                         is_extended_id=True,
                         dlc=struct.calcsize(self._format),
                         data=struct.pack(self._format, *args))


class MSG_ping(TXMessage):
    """all-call message, solicits 'ack' from every module"""
    _format = '>H'

    def __init__(self):
        super().__init__(CMD_ID, 0)


class MSG_select(TXMessage):
    """selects a specific module for subsequent non-addressed commands"""
    _format = '>HBBH'

    def __init__(self, module_id):
        super().__init__(CMD_ID,
                         0x2010,
                         0,
                         0,
                         module_id)


class MSG_read_eeprom(TXMessage):
    """requests data from (probably) the EEPROM"""
    _format = '>HHB'

    def __init__(self, address, count):
        super().__init__(CMD_ID,
                         0x2003,
                         address,
                         count)


class MSG_program(TXMessage):
    """commands the selected device to enter programming mode"""
    _format = '>H'

    def __init__(self):
        super().__init__(CMD_ID, 0x2000)


class MSG_erase(TXMessage):
    """commands the selected device to erase the flash"""
    _format = '>H'

    def __init__(self):
        super().__init__(CMD_ID, 0x0202)


class RXMessage(object):
    """
    Abstract for messages that have been received.

    Concretes set self._format to struct.unpack() received bytes,
    and self._filter to a list of tuple-per-unpacked-item with each
    tuple containing True/False and, if True, the required value.
    """
    def __init__(self, expected_id, raw):
        if raw.arbitration_id != expected_id:
            raise MessageError(f'expected reply with ID 0x{expected_id:x} '
                               f'but got 0x{raw.arbitration_id:x}')
        if raw.dlc != struct.calcsize(self._format):
            raise MessageError(f'expected reply with length {expected_dlc} '
                               f'but got {raw.dlc}')
        self._data = raw.data

    def unpack(self):
        values = struct.unpack(self._format, self._data)
        for (index, (check, value)) in enumerate(self._filter):
            if check and value != values[index]:
                raise MessageError(f'reply field {index} is '
                                   f'0x{values[index]:x} '
                                   f'but expected 0x{value:x}')
        return values


class MSG_boot(RXMessage):
    """unsolicited broadcast sent by module at power-on"""
    _format = '>BBBHBH'
    _filter = [(True, 0x01),
               (True, 0),
               (True, 0),
               (False, 0),
               (True, 0),
               (False, 0)]

    def __init__(self, raw):
        super().__init__(expected_id=ACK_ID,
                         raw=raw)
        (_, _, _, self.module_id, _, self.sw_version) = self.unpack()


class MSG_reboot(RXMessage):
    """unsolicited broadcast sent by module when rebooting"""
    _format = '>BBBHBH'
    _filter = [(True, 0x41),
               (True, 0),
               (True, 0),
               (False, 0),
               (True, 0),
               (False, 0)]

    def __init__(self, raw):
        super().__init__(expected_id=ACK_ID,
                         raw=raw)
        (_, _, _, self.module_id, _, self.sw_version) = self.unpack()


class MSG_ack(RXMessage):
    """response to MSG_ping sent by every module"""
    _format = '>BBBHBH'
    _filter = [(True, 0x00),
               (True, 0),
               (True, 0),
               (False, 0),
               (True, 0),
               (False, 0)]

    def __init__(self, raw):
        super().__init__(expected_id=ACK_ID,
                         raw=raw)
        (_, _, _, self.module_id, _, self.sw_version) = self.unpack()


class MSG_selected(RXMessage):
    """
    Response to MSG_select confirming selection.

    self.sw_version appears to be 0 if the app is running,
    or !0 if in program mode
    """
    _format = '>HBBHH'
    _filter = [(True, 0x2110),
               (True, 0),
               (True, 0),
               (False, 0),
               (False, 0)]

    def __init__(self, raw):
        super().__init__(expected_id=RSP_ID,
                         raw=raw)
        (_, _, _, self.module_id, self.sw_version) = self.unpack()


class MSG_program_nak(RXMessage):
    """
    Response sent to MSG_program when the app is running.
    Module reboots after sending this message (and sends MSG_boot),
    apparently into the bootloader.
    """
    _format = '>HBBHH'
    _filter = [(True, 0x2fff),
               (True, 0),
               (True, 0),
               (False, 0),
               (False, 0)]

    def __init__(self, raw):
        super().__init__(expected_id=RSP_ID,
                         raw=raw)
        (_, _, _, self.module_id, _) = self.unpack()


class MSG_program_ack(RXMessage):
    """response sent to MSG_program when running the bootloader"""
    _format = '>HBBHH'
    _filter = [(True, 0x2100),
               (True, 0),
               (True, 0),
               (False, 0),
               (False, 0)]

    def __init__(self, raw):
        super().__init__(expected_id=RSP_ID,
                         raw=raw)
        (_, _, _, self.module_id, _) = self.unpack()


class MSG_progress(RXMessage):
    """
    Sent in a stream after MSG_erase; self.progress counts from
    zero to self.limit.
    """
    _format = '>BBBB'
    _filter = [(True, 0),
               (False, 0),
               (False, 0),
               (True, 0)]

    def __init__(self, raw):
        super().__init__(expected_id=RSP_ID,
                         raw=raw)
        (_, self.progress, self.limit, _) = self.unpack()


class CANInterface(object):
    def __init__(self, args):
        self._bus = can.interface.Bus(bustype=args.interface_type,
                                      channel=args.interface,
                                      bitrate=args.can_speed)
        self._verbose = args.verbose

        self._bus.set_filters([
            {"can_id": ACK_ID,  "can_mask": (1 << 29) - 1, "extended": True},
            {"can_id": CMD_ID,  "can_mask": (1 << 29) - 1, "extended": True},
            {"can_id": SREC_ID, "can_mask": (1 << 29) - 1, "extended": True},
            {"can_id": RSP_ID,  "can_mask": (1 << 29) - 1, "extended": True},
            {"can_id": DATA_ID, "can_mask": (1 << 29) - 1, "extended": True}
        ])
        while self._bus.recv(0) is not None:
            pass
        log(self._bus.state)

    def send(self, message):
        log(f'CAN TX: {message}')
        self._bus.send(message, 1)

    def recv(self, timeout=10):
        try:
            msg = self._bus.recv(timeout)
            log(f'CAN RX: {msg}')
        except can.CanError as e:
            return None
        return msg

    def scan(self):
        self.send(MSG_ping())
        ids = list()
        while True:
            rsp = self.recv(1)
            if rsp is not None:
                try:
                    ack = MSG_ack(rsp)
                except CanError as e:
                    raise CanError('unexpected programming traffic '
                                   'on CAN bus during scan')
                ids.append(ack.module_id)
            else:
                break
        return ids


class Srecords(object):
    def __init__(self, path, args):
        try:
            with path.open() as f:
                lines = f.readlines()
        except Exception as e:
            raise RuntimeError(f'could not read S-records from {path}')
        self.lines = list()
        for line in lines:
            if line[0] != 'S':
                raise RuntimeError(f'malformed S-record: {line}')
            elif line[1] == '0':
                # discard S0 records, they don't do anything
                continue
            elif line[1] == '1':
                # verify that the address range is writable
                count = int(f'0x{line[2:4]}', 16) - 3
                address = int(f'0x{line[4:8]}', 16)
                end = address + count
                if (address >= 0x2200) and (end <= 0xaf7b):
                    pass
                elif (address >= 0xaf80) and (end <= 0xbdff):
                    pass
                else:
                    continue
            elif line[1] == '9':
                # pass S9 records
                pass
            else:
                # ignore everything else
                continue
            self.lines.append(line.strip())


class Module(object):
    def __init__(self, interface, module_id, args):
        self._interface = interface
        self._module_id = module_id
        self._verbose = args.verbose

    def _cmd(self, message):
        self._interface.send(message)
        rsp = self._interface.recv()
        if rsp is None:
            raise ModuleError(f'sent 0x{arbid:x}:{data} '
                              f'but timed out waiting for a reply')
        return rsp

    def _select(self):
        rsp = self._cmd(MSG_select(self._module_id))
        sel = MSG_selected(rsp)
        if (sel.module_id != self._module_id):
            raise CanError('wrong module responded to selection')
        return sel.sw_version

    def _read_eeprom(self, address, length):
        result = bytearray()
        while length > 0:
            amount = length if length <= 8 else 8
            rsp = self._cmd(MSG_read_eeprom(address, amount))
            length -= amount
            address += amount
            result += rsp.data
        return result

    def identify(self):
        self._select()
        result = dict()
        for key, extent in EEPROM_MAP.items():
            result[key] = self._read_eeprom(extent[0], extent[1]).decode('ascii')
        return result

    def _wait_for_boot(self, timeout):
        while True:
            rsp = self._interface.recv(timeout)
            if rsp is None:
                raise ModuleError('did not see module reboot message')
            try:
                boot_message = MSG_reboot(rsp)
                break
            except MessageError:
                pass

    def _enter_flash_mode(self):
        self._select()
        rsp = self._cmd(MSG_program())
        try:
            will_reboot = MSG_program_nak(rsp)
            self._wait_for_boot(2)
            self._select()
            rsp = self._cmd(MSG_program())
        except MessageError:
            pass
        ready = MSG_program_ack(rsp)

    def _erase(self):
        print("ERASE...")
        self._cmd(MSG_erase())
        while True:
            rsp = self._interface.recv(2)
            if rsp is None:
                raise ModuleError('did not see expected module '
                                  'progress message')
            try:
                progress = MSG_progress(rsp)
            except MessageError as e:
                raise ModuleError(f'got unexpected message {rsp} '
                                  f'instead of progress')
            bar = '#' * progress.progress + ' ' * (progress.limit -
                                                   progress.progress)
            print(f'\r[{bar}]', end='')
        print('\n')

    def upload(self, srecords):
        self._enter_flash_mode()
        #self._erase()

    def get_eeprom(self):
        self._select()
        return self._read_eeprom(0, 0x800)


def find_module_id(interface, args):
    if args.module_id is not None:
        return args.module_id
    ids = interface.scan()
    if len(ids) == 0:
        raise RuntimeError('no modules detected')
    elif len(ids) > 1:
        raise RuntimeError('more than one module detected, '
                           'must supply --module-id')
    else:
        return ids[0]


def do_scan(interface, args):
    if args.module_id is None:
        ids = interface.scan()
        if len(ids) > 0:
            print('ID     TYPE                 NAME'
                  '                           VERSION')
    else:
        ids = [args.module_id]

    if len(ids) > 0:
        for module_id in ids:
            info = Module(interface, module_id, args).identify()

            print(f'{module_id:<6} '
                  f'{info["product_name"]:20} '
                  f'{info["user_name"]:30} '
                  f'{info["user_version"]:20}')


def do_upload(interface, args):
    module_id = find_module_id(interface, args)
    module = Module(interface, module_id, args)
    srecords = Srecords(args.upload, args)
    module.upload(srecords)


def do_eeprom_dump(interface, args):
    module_id = find_module_id(interface, args)
    module = Module(interface, module_id, args)
    contents = module.get_eeprom()
    print(contents)


parser = argparse.ArgumentParser(description='MRS Microplex 7* CAN flasher')
parser.add_argument('--interface',
                    type=str,
                    required=True,
                    metavar='INTERFACE_NAME',
                    help='interface name or path')
parser.add_argument('--interface-type',
                    type=str,
                    metavar='INTERFACE_TYPE',
                    default='slcan',
                    help='interface type')
parser.add_argument('--can-speed',
                    type=int,
                    default=125000,
                    metavar='BITRATE',
                    help='CAN bitrate')
parser.add_argument('--module-id',
                    type=int,
                    metavar='MODULE_ID',
                    help='specific module ID to program')
parser.add_argument('--verbose',
                    action='store_true',
                    help='print verbose progress information')

actiongroup = parser.add_mutually_exclusive_group(required=True)
actiongroup.add_argument('--upload',
                         type=Path,
                         metavar='SRECORD_FILE',
                         help='S-record file to upload')
actiongroup.add_argument('--scan',
                         action='store_true',
                         help='scan for connected modules')
actiongroup.add_argument('--dump-eeprom',
                         action='store_true',
                         help='dump the contents of the module EEPROM')


args = parser.parse_args()
if args.verbose:
    def log(msg):
        print(msg)
else:
    def log(msg):
        pass

interface = CANInterface(args)
if args.scan:
    do_scan(interface, args)
elif args.dump_eeprom:
    do_eeprom_dump(interface, args)
elif args.upload is not None:
    do_upload(interface, args)
