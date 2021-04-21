/*
 * Console logging
 */

#include <timer.h>

#include "defs.h"

static unsigned count;

void
console_report(struct pt *pt)
{
    static volatile timer_t console_report_timer = {
        .delay_ms = CONSOLE_REPORT_INTERVAL
    };
    static uint8_t live_counter;

    pt_begin(pt);
    timer_register(&console_report_timer);

    for (;;) {
        pt_wait(pt, timer_expired(console_report_timer));

#if (CONSOLE_REPORT_INTERVAL > 0)
//        uint16_t mon_val;



#endif // (CONSOLE_REPORT_INTERVAL > 0)
        timer_reset(console_report_timer, CONSOLE_REPORT_INTERVAL);
    }
    pt_end(pt);
}
