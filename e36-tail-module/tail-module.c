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
struct pt pt_cas_jbe_emulator;
struct pt pt_brakes;
struct pt pt_tails;
struct pt pt_rains;
struct pt pt_output[_OUTPUT_ID_MAX];
struct pt pt_t15_check;

static void t15_check(struct pt *pt);

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
    putx16(_post_code);
    putchar(' ');
    putx8(SRS);
    puts(" E36 tail");
    POST(1);

    // start the timebase and timer callouts
    time_init();

    // configure analog monitors
    monitor_init();

    // main loop
    for (;;) {
        __RESET_WATCHDOG();                 // must be reset every 1s or better
        t15_check(&pt_t15_check);
        can_listen(&pt_can_listener);
        can_report_fuel(&pt_can_report_fuel);
        can_report_diags(&pt_can_report_diags);
        cas_jbe_emulator(&pt_cas_jbe_emulator);
        brake_thread(&pt_brakes);
        tails_thread(&pt_tails);
        rains_thread(&pt_rains);
        for (output_id_t x = 0; x < _OUTPUT_ID_MAX; x++) {
            output_thread(&pt_output[x], x);
        }
    }
}

void
t15_check(struct pt *pt)
{
    (void)pt;
    if (monitor_get(MON_T15_VOLTAGE) >= T15_MIN_VOLTAGE) {
        return;
    }
    puts("LVT");

    // low-voltage trap
    while (monitor_get(MON_T15_VOLTAGE) < T15_MIN_VOLTAGE) {
        // allow power-off if T15 falls low enough
        set_DO_POWER(false);
        set_CAN_STB_N(false);
        __RESET_WATCHDOG();
    }

    // voltage has recovered, let the watchdog reset us
    POST(0x8415);           // 'T'15
    for (;;);
}
