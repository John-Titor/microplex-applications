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
struct pt pt_can_reporter;
struct pt pt_cas_jbe_emulator;
struct pt pt_output_manager;
struct pt pt_brakes;
struct pt pt_tails;

// Filters
// 0x0a8 (DDE brake lights)
// 0x6f1 (Protool)
// -
// -
//
static const CAN_filters can_filters = {
    .filter_16 = {
        .accept = {
            (uint16_t)0x0a8 << 5,
                            (uint16_t)0x6f1 << 5,
                            (uint16_t)0x0001,
                            (uint16_t)0x0001
        },
        .mask = {
            (uint16_t)0xfffe,
            (uint16_t)0xfffe,
            (uint16_t)0x0000,
            (uint16_t)0x0000
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

    //CAN_init(CAN_BR_500, CAN_FM_NONE, NULL);
    CAN_init(CAN_BR_125, CAN_FM_4x16, &can_filters);
    puts("tail module");

    // start the timebase and timer callouts
    time_init();

    // configure analog monitors
    monitor_init();

    // main loop
    for (;;) {
        __RESET_WATCHDOG();                 // must be reset every 1s or better
        can_listen(&pt_can_listener);
        can_report(&pt_can_reporter);
        cas_jbe_emulator(&pt_cas_jbe_emulator);
        output_thread(&pt_output_manager);
        brake_thread(&pt_brakes);
        tails_thread(&pt_tails);
    }
}

