/*
 * Tail module for the Hello Kitty E36.
 *
 * Responsible for brake / rain / running lights,
 * also reading and reporting the fuel level from
 * a 0-5V fuel level sender.
 */

#include <stdio.h>
#include <stdlib.h>

#include <adc.h>
#include <board.h>
#include <mscan.h>
#include <pt.h>
#include <pwm.h>
#include <timer.h>

#include "defs.h"

// Handler for nonexistent vector 32 is patched in at
// fixup time as the default handler for vectors that
// aren't assigned.
void default_handler() __interrupt(32)
{
    // try to send a panic message
    puts("!badirq\n");

    // let the watchdog reset us
    for (;;);
}

struct pt pt_can_listener;
struct pt pt_can_report_fuel;
struct pt pt_can_report_diags;
struct pt pt_console_report;
struct pt pt_cas_jbe_emulator;
struct pt pt_output_manager;
struct pt pt_brakes;
struct pt pt_tails;

// Filters
// 0x0a8 (DDE brake lights)
// 0x21a (BMW lighting)
// 0x6f1 (Protool)
// -
// -
//
static const CAN_filters can_filters = {
    .filter_16 = {
        .accept = {
            (uint16_t)0x0a8 << 5,
            (uint16_t)0x21a << 5,
            (uint16_t)0x6f1 << 5,
            (uint16_t)0x0000
        },
        .mask = {
            ~((uint16_t)0x7ff << 5),     // precise match
            ~((uint16_t)0x7ff << 5),     // precise match
            ~((uint16_t)0x7ff << 5),     // precise match
            0
        },
    }
};

void
main()
{
    __RESET_WATCHDOG();

    // configure pins, etc.
    board_init();

    // stay awake even if KL15 is not present
    set_DO_POWER(true);

    //CAN_init(CAN_BR_500, CAN_FM_4x16, &can_filters);
    CAN_init(CAN_BR_125, CAN_FM_4x16, &can_filters);
    LOG("E36 tail module");

    // start the timebase and timer callouts
    time_init();

    // configure analog monitors
    monitor_init();

    // main loop
    for (;;) {
        __RESET_WATCHDOG();                 // must be reset every 1s or better
        can_listen(&pt_can_listener);
        can_report_fuel(&pt_can_report_fuel);
        can_report_diags(&pt_can_report_diags);
        console_report(&pt_console_report);
        cas_jbe_emulator(&pt_cas_jbe_emulator);
        output_thread(&pt_output_manager);
        brake_thread(&pt_brakes);
        tails_thread(&pt_tails);
    }
}
