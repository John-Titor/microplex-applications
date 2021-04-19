#!/usr/bin/env python3
#
# Functional tests
#
# Test setup:
#
# - 5A power supply
# - programmer/probe connected
# - DO_1 programmable load
# - DO_2 LED to ground
# - DO_3 open
# - DO_4 open
# - AI_1 some value 0-5V
# - AI_3 T30
# - KL15 on relay

import argparse
import struct
import time
import can
import curses

# colours we use
RED = 1
GREEN = 2
CYAN = 3

# message IDs
ACK_ID = 0x1ffffff0
CONSOLE_ID = 0x1ffffffe
MJS_POWER_ID = 0x0fffffff
LIGHT_CTRL_ID = 0x21a
BRAKE_CTRL_ID = 0x0a8


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


class MSG_mjs_power(TXMessage):
    """mjs adapter power control message"""
    _format = 'B'

    def __init__(self, t30_state, t15_state):
        if not t30_state:
            arg = 0x00
        elif not t15_state:
            arg = 0x01
        else:
            arg = 0x03
        super().__init__(MJS_POWER_ID, arg)


class MSG_brake(TXMessage):
    """BMW brake (etc.) status message"""
    _format = 'BHHBBB'

    def __init__(self, brake_state):
        super().__init__(BRAKE_CTRL_ID,
                         0x54,              # magic
                         0,                 # actual torque
                         0,                 # rounded torque
                         240,               # clutch not depressed
                         0x0f,              # magic
                         32 if brake_state else 3)


class MSG_lights(TXMessage):
    """BMW light control message"""
    _format = 'BBB'

    def __init__(self, brake_light, tail_light, rain_light):
        super().__init__(LIGHT_CTRL_ID,
                         ((0x80 if brake_light else 0) |
                          (0x04 if tail_light else 0) |
                          (0x01 if rain_light else 0)),
                         0,
                         0xf7)


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
                               f'but got {raw}')
        expected_dlc = struct.calcsize(self._format)
        if raw.dlc != expected_dlc:
            raise MessageError(f'expected reply with length {expected_dlc} '
                               f'but got {raw}')

        self._data = raw.data
        self._values = struct.unpack(self._format, self._data)
        for (index, (check, value)) in enumerate(self._filter):
            if check and value != self._values[index]:
                raise MessageError(f'reply field {index} is '
                                   f'0x{self._values[index]:x} '
                                   f'but expected 0x{value:x}')

    @classmethod
    def len(self):
        return struct.calcsize(self._format)


class MSG_ack(RXMessage):
    """broadcast message sent by module on power-up, reboot or crash"""
    _format = '>BBBHBH'
    _filter = [(False, 0),
               (True, 0),
               (True, 0),
               (False, 0),
               (False, 0),
               (False, 0)]
    REASON_MAP = {
        0x00: 'power-on',
        0x01: 'reset',
        0x11: 'low-voltage reset',
        0x21: 'clock lost',
        0x31: 'address error',
        0x41: 'illegal opcode',
        0x51: 'watchdog timeout'
    }
    STATUS_MAP = {
        0: 'OK',
        4: 'NO PROG'
    }

    def __init__(self, raw):
        super().__init__(expected_id=ACK_ID,
                         raw=raw)
        (self.reason_code, _, _,
         self.module_id, self.status_code, self.sw_version) = self._values
        try:
            self.reason = self.REASON_MAP[self.reason_code]
        except KeyError:
            self.reason = 'unknown'
        try:
            self.status = self.STATUS_MAP[self.status_code]
        except KeyError:
            self.status = "unknown"


class MSG_status_system(RXMessage):
    """firmware system status message"""
    _format = "<HHBBBB"
    _filter = [(False, 0),
               (False, 0),
               (False, 0),
               (False, 0),
               (False, 0),
               (True, 0)]

    def __init__(self, raw):
        super().__init__(expected_id=0x0f00000,
                         raw=raw)
        (self.t30_voltage,
         self.t15_voltage,
         self.temperature,
         self.fuel_level,
         self.output_request, _) = self._values


class MSG_status_voltage_current(RXMessage):
    """firmware voltage/current report"""
    _format = "<BBBBBBBB"
    _filter = [(False, 0),
               (False, 0),
               (False, 0),
               (False, 0),
               (False, 0),
               (False, 0),
               (False, 0),
               (False, 0)]

    def __init__(self, raw):
        super().__init__(expected_id=0x0f00001,
                         raw=raw)
        self.output_voltage = self._values[0:4]
        self.output_current = self._values[4:8]


class MSG_status_faults(RXMessage):
    """firmware fault status report"""
    _format = "<BBBBBBBB"
    _filter = [(False, 0),
               (False, 0),
               (False, 0),
               (False, 0),
               (True, 0),
               (True, 0),
               (True, 0),
               (False, 0)]

    def __init__(self, raw):
        super().__init__(expected_id=0x0f00002,
                         raw=raw)
        self.output_faults = self._values[0:4]
        self.system_faults = self._values[7]


class CANInterface(object):
    def __init__(self, args):
        self._bus = can.interface.Bus(bustype=args.interface_type,
                                      channel=args.interface,
                                      bitrate=args.can_speed,
                                      sleep_after_open=0.2)

    def send(self, message):
        """send the message"""
        self._bus.send(message, 1)

    def recv(self, timeout=2):
        """
        wait for a message

        Note the can module will barf if a bad message is received, so we need
        to catch this and retry
        """
        deadline = time.time() + timeout
        while time.time() < deadline:
            wait_time = deadline - time.time()
            try:
                return self._bus.recv(wait_time)
            except Exception:
                pass
        return None

    def set_power_off(self):
        self.send(MSG_mjs_power(False, False))

    def set_power_t30(self):
        self.send(MSG_mjs_power(True, False))

    def set_power_t30_t15(self):
        self.send(MSG_mjs_power(True, True))

    def detect(self):
        """
        Power on the module and listen for it to sign on.
        Returns the ID of the detected module.
        """
        self.set_power_off()
        while self.recv(0.25) is not None:
            # drain buffered messages
            pass
        self.set_power_t30()
        while True:
            rsp = self.recv(2)
            if rsp is None:
                raise ModuleError('no power-on message from module')
            try:
                signon = MSG_ack(rsp)
                break
            except MessageError as e:
                raise ModuleError(f'unexpected power-on message '
                                  'from module: {rsp}')
        return signon.module_id


class ModuleState(object):

    def __init__(self, win):
        self._win = win
        self._can_in_timeout = False
        self._can_did_timeout = False
        self.module_resets = 0
        self.message_errors = 0
        self._reset()

    def _reset(self):
        self.status_system = None
        self.status_v_i = None
        self.status_faults = None

    def update(self, msg):
        try:
            self.status_system = MSG_status_system(msg)
        except MessageError:
            try:
                self.status_v_i = MSG_status_voltage_current(msg)
            except MessageError:
                try:
                    self.status_faults = MSG_status_faults(msg)
                except MessageError:
                    self.message_errors += 1
        self._can_in_timeout = False

    def timeout(self):
        self._can_in_timeout = True
        self._can_did_timeout = True
        self._reset()

    def module_reset(self):
        self.module_resets += 1

    def _text_attr(self, text, val, index):
        if val & (0x01 << index):
            return (text, curses.color_pair(RED))
        if val & (0x10 << index):
            return (text, curses.color_pair(CYAN))
        return ('-' * len(text), curses.A_DIM)

    def print_attr(self, y, x, attr, len=8, index=None):
        for obj in [self, self.status_system, self.status_v_i, self.status_faults]:
            val = None
            try:
                val = getattr(obj, attr)
                break
            except AttributeError as e:
                pass
        if val is None:
            self._win.addstr(y, x, 'X', curses.color_pair(RED))
            return

        elif attr in ['t30_voltage', 't15_voltage']:
            self._win.addstr(y, x, f' {val / 1000.0:2.3f}', curses.A_BOLD)

        elif attr == 'temperature':
            self._win.addstr(y, x, f'{val:3}', curses.A_BOLD)

        elif attr == 'fuel_level':
            self._win.addstr(y, x, f'{val:3}', curses.A_BOLD)

        elif attr == 'output_request':
            if val & (1 << index):
                self._win.addstr(y, x, 'ON ', curses.color_pair(GREEN))
            else:
                self._win.addstr(y, x, 'OFF', curses.A_BOLD)

        elif attr == 'output_voltage':
            self._win.addstr(y, x, f'{val[index] / 1000.0:2.3f}', curses.A_BOLD)

        elif attr == 'output_current':
            self._win.addstr(y, x, f'{val[index] / 1000.0:2.3f}', curses.A_BOLD)

        elif attr == 'output_faults':
            self._win.addstr(y, x, *self._text_attr('OPEN', val[index], index))
            self._win.addstr(y, x + 5, *self._text_attr('STUCK', val[index], index))
            self._win.addstr(y, x + 11, *self._text_attr('OVERLOAD', val[index], index))

        elif attr == 'system_faults':
            self._win.addstr(y, x, *self._text_attr('T30', val, 0))
            self._win.addstr(y, x + 4, *self._text_attr('T15', val, 1))
            self._win.addstr(y, x + 8, *self._text_attr('CAN', val, 2))
            self._win.addstr(y, x + 12, *self._text_attr('TEMP', val, 3))

        elif attr == 'module_faults':
            if self._can_in_timeout:
                self._win.addstr(y, x, 'CAN', curses.color_pair(RED))
            if self._can_did_timeout:
                self._win.addstr(y, x, 'CAN', curses.color_pair(CYAN))
            self._win.addstr(y, x, '---', curses.A_DIM)

        elif attr in ['module_resets', 'message_errors']:
            color = curses.A_DIM if val == 0 else curses.color_pair(RED)
            self._win.addstr(y, x, f'{val:{len}}', color)

        else:
            raise RuntimeError(f'cannot present \'{attr}\'')


class Logger(object):
    def __init__(self, win, args):
        self._win = win
        self._verbose = args.verbose
        self._win.addstr(0, 0, "initializing...\n")
        self._win.idlok(True)
        self._win.scrollok(True)
        self._win.refresh()
        self._cons_buf = ""

    def log_can(self, msg):
        if msg.arbitration_id == CONSOLE_ID:
            for idx in range(0, msg.dlc):
                if msg.data[idx] == 0:
                    self._win.addstr(f"CONS: {self._cons_buf}\n")
                    self._cons_buf = ""
                else:
                    self._cons_buf += chr(msg.data[idx])
        elif self._verbose:
            self._win.addstr(f"CAN: {msg}\n")
        self._win.refresh()


# Live monitoring mode for testing, etc.
#
# Monitor Status ----------------------------------------------
# Resets: xxx
# Faults: CAN
#
# Module Status -----------------------------------------------
# T30 [  x.xxxV]  T15 [  x.xxxV]  Temp [    xx°C]   CAN
# Faults: T30 T15 CAN TEMP
#
# Output    Status  Voltage     Current     Faults
#   0       ON      [  x.xxxV]  [  x.xxxA]  OPEN STUCK OVERLOAD
#   1       --      [  x.xxxV]  [  x.xxxA]  OPEN STUCK OVERLOAD
#   2       --      [  x.xxxV]  [  x.xxxA]  OPEN STUCK OVERLOAD
#   3       --      [  x.xxxV]  [  x.xxxA]  OPEN STUCK OVERLOAD
#
# [T]15 OFF [B]rake OFF  [L]ights OFF  [R]ain light OFF  [Q]uit
#
# Fault text is red if the fault is current, cyan if saved,
# dashed out otherwise.
#
def do_monitor(stdscr, interface, args):

    module_id = interface.detect()


    sw_t15 = False
    sw_brake = False
    sw_lights = False
    sw_rain = False
    sw_can = False
    tx_toggle = False

    curses.curs_set(False)
    curses.start_color()
    stdscr.nodelay(True)
    stdscr.clear()
    stdscr.refresh()

    curses.init_pair(RED, curses.COLOR_RED, curses.COLOR_BLACK)
    curses.init_pair(GREEN, curses.COLOR_GREEN, curses.COLOR_BLACK)
    curses.init_pair(CYAN, curses.COLOR_CYAN, curses.COLOR_BLACK)

    statwin = curses.newwin(18, 80, 0, 0)
    state = ModuleState(statwin)

    statwin.addstr(1, 1, '-- Monitor Status -------------------------------------')
    statwin.addstr(2, 1, 'Resets:           Message Errors:')
    statwin.addstr(3, 1, 'Faults:')

    statwin.addstr(5, 1, '-- Module Status --------------------------------------')
    statwin.addstr(6, 1, 'T30      V  T15      V  Temp    °C')
    statwin.addstr(7, 1, 'Faults:')

    statwin.addstr(9, 1, 'Output    Status  Voltage     Current     Faults')
    statwin.addstr(10, 4, '1                   V           A')
    statwin.addstr(11, 4, '2                   V           A')
    statwin.addstr(12, 4, '3                   V           A')
    statwin.addstr(13, 4, '4                   V           A')

    statwin.addstr(15, 1, '[T]15      [B]rake      [L]ights      [R]ain      [C]AN')
    statwin.addstr(16, 1, '[Q]uit')
    statwin.refresh()

    maxy, maxx = stdscr.getmaxyx()
    logwin = curses.newwin(maxy - 18, maxx, 18, 0)
    logger = Logger(logwin, args)

    def status_flag(x, flag):
        if flag:
            statwin.addstr(15, x, 'ON ', curses.color_pair(GREEN))
        else:
            statwin.addstr(15, x, 'OFF', curses.A_BOLD)

    last_send_time = 0

    spindex = 0
    while True:
        statwin.refresh()
        msg = interface.recv(0.2)
        if msg is None:
            #state.timeout()
            pass
        else:
            logger.log_can(msg)
            # XXX handle module-reset message?
            state.update(msg)
            spindex = 0 if spindex == 3 else spindex + 1

        state.print_attr(2, 9, 'module_resets')
        state.print_attr(2, 35, 'message_errors')
        state.print_attr(3, 9, 'module_faults')

        state.print_attr(6, 4, 't30_voltage')
        state.print_attr(6, 16, 't15_voltage')
        state.print_attr(6, 30, 'temperature')

        for channel in range(0, 4):
            state.print_attr(10 + channel, 12, 'output_request', len=3, index=channel)
            state.print_attr(10 + channel, 19, 'output_voltage', index=channel)
            state.print_attr(10 + channel, 31, 'output_current', index=channel)
            state.print_attr(10 + channel, 43, 'output_faults', len=19, index=channel)

        status_flag(7, sw_t15)
        status_flag(20, sw_brake)
        status_flag(34, sw_lights)
        status_flag(46, sw_rain)
        status_flag(57, sw_can)

        statwin.addstr(1, 1, '/-\\-'[spindex])

        if sw_can:
            if tx_toggle:
                msg = MSG_brake(sw_brake)
            else:
                msg = MSG_lights(False, sw_lights, sw_rain)
                # msg = MSG_lights(sw_brake, sw_lights, sw_rain)
            logger.log_can(msg)
            interface.send(msg)
            tx_toggle = not tx_toggle

        try:
            ch = stdscr.getkey()
            if ch == 't' or ch == 'T':
                sw_t15 = not sw_t15
                if sw_t15:
                    interface.set_power_t30_t15()
                else:
                    interface.set_power_t30()
            if ch == 'b' or ch == 'B':
                sw_brake = not sw_brake
            if ch == 'l' or ch == 'L':
                sw_lights = not sw_lights
            if ch == 'r' or ch == 'R':
                sw_rain = not sw_rain
            if ch == 'c' or ch == 'C':
                sw_can = not sw_can
            if ch == 'q' or ch == 'Q':
                return
        except Exception:
            pass


parser = argparse.ArgumentParser(description='E36 tail module tester')
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
parser.add_argument('--verbose',
                    action='store_true',
                    help='print verbose progress information')
actiongroup = parser.add_mutually_exclusive_group(required=True)
actiongroup.add_argument('--monitor',
                         action='store_true',
                         help='monitor operation')

args = parser.parse_args()
try:
    interface = CANInterface(args)
    if args.monitor:
        curses.wrapper(do_monitor, interface, args)
except KeyboardInterrupt:
    pass
if interface is not None:
    interface.set_power_off()
