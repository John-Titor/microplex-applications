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


class ReplyError(Exception):
    pass


class TXMessage(can.Message):
    def __init__(self, arbitration_id, *args):
        super().__init__(arbitration_id=arbitration_id,
                         is_extended_id=True,
                         dlc=struct.calcsize(self._format),
                         data=struct.pack(self._format, *args))


class MSG_ping(TXMessage):
    _format = '>H'

    def __init__(self):
        super().__init__(CMD_ID, 0)


class MSG_select(TXMessage):
    _format = '>HBBH'

    def __init__(self, module_id):
        super().__init__(CMD_ID,
                         0x2010,
                         0,
                         0,
                         module_id)


class MSG_read_info(TXMessage):
    _format = '>HHB'

    def __init__(self, address, count):
        super().__init__(CMD_ID,
                         0x2003,
                         address,
                         count)


class RXMessage(object):
    def __init__(self, expected_id, raw):
        if raw.arbitration_id != expected_id:
            raise ReplyError(f'expected reply with ID 0x{expected_id:x} '
                             f'but got 0x{raw.arbitration_id:x}')
        if raw.dlc != struct.calcsize(self._format):
            raise ReplyError(f'expected reply with length {expected_dlc} '
                             f'but got {raw.dlc}')
        self._data = raw.data

    def unpack(self):
        values = struct.unpack(self._format, self._data)
        for (index, (check, value)) in enumerate(self._filter):
            if check and value != values[index]:
                raise ReplyError(f'reply field {index} is 0x{values[index]:x} '
                                 f'but expected 0x{value:x}')
        return values


class MSG_ack(RXMessage):
    _format = '>BBBHBH'
    _filter = [(True, 0),
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
    _format = '>HBBHBB'
    _filter = [(True, 0x2110),
               (True, 0),
               (True, 0),
               (False, 0),
               (True, 0),
               (True, 0)]

    def __init__(self, raw):
        super().__init__(expected_id=RSP_ID,
                         raw=raw)
        (_, _, _, self.module_id, _, _) = self.unpack()


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
        if self._verbose:
            print(self._bus.state)

    def send(self, message):
        if self._verbose:
            print(f'CAN TX: {message}')
        self._bus.send(message, 1)

    def recv(self, timeout=10):
        try:
            msg = self._bus.recv(timeout)
            if self._verbose:
                print(f'CAN RX: {msg}')
        except can.CanError as e:
            return None
        return msg


class MRSUploader(object):

    class UploadError(Exception):
        pass

    def __init__(self, interface, args):
        self._interface = interface
        self._verbose = args.verbose

    def _scan(self):
        self._interface.send(MSG_ping())
        ids = list()
        while True:
            rsp = self._interface.recv(1)
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

    def _cmd(self, message):
        self._interface.send(message)
        rsp = self._interface.recv()
        if rsp is None:
            raise self.UploadError(f'sent 0x{arbid:x}:{data} '
                                   f'but timed out waiting for a reply')
        return rsp

    def _read_info(self, address, length):
        result = bytearray()
        while length > 0:
            amount = length if length <= 8 else 8
            rsp = self._cmd(MSG_read_info(address, amount))
            length -= amount
            address += amount
            result += rsp.data
        return result

    def _identify(self, module_id):

        rsp = self._cmd(MSG_select(module_id))
        sel = MSG_selected(rsp)
        if (sel.module_id != module_id):
            raise CanError('wrong module responded to selection')

        product_name = self._read_info(0x20, 20).decode('ascii')
        module_name = self._read_info(0x7f, 30).decode('ascii')
        module_version = self._read_info(0x6b, 20).decode('ascii')
        sw_version = struct.unpack('>H', self._read_info(0x53, 2))[0]
        print(f'{module_id:<6} {product_name:20} {module_name:30} '
              f' {module_version:20}')

    def scan(self):
        ids = self._scan()
        if len(ids) > 0:
            print('ID     TYPE                 NAME'
                  '                            VERSION')
            for module_id in ids:
                self._identify(module_id)


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
parser.add_argument('--module_id',
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

args = parser.parse_args()

interface = CANInterface(args)
uploader = MRSUploader(interface, args)
uploader.scan()
if args.upload is not None:
    uploader.upload(args.upload)
