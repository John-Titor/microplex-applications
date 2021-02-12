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

struct pt pt_can_listener = pt_init();
struct pt pt_can_reporter = pt_init();
struct pt pt_output_manager = pt_init();
struct pt pt_brakes = pt_init();

void
main()
{
    __RESET_WATCHDOG();

    // configure pins, etc.
    board_init();

    //CAN_init(CAN_BR_500, CAN_FM_NONE, NULL);
    CAN_init(CAN_BR_125, CAN_FM_NONE, NULL);
    puts("tail module");

    // start the timebase and timer callouts
    time_init();

    // configure analog monitors
    monitor_init();

    // main loop
    for (;;) {
        __RESET_WATCHDOG();
        can_listen(&pt_can_listener);
        can_report(&pt_can_reporter);
        output_thread(&pt_output_manager);
        brake_thread(&pt_brakes);
    }
}

