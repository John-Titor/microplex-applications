/*
 * Brake light algorithms.
 */

#include <pt.h>
#include <timer.h>

#include "defs.h"

static bool brake_light_requested;

void
brake_light_request(bool on)
{
    brake_light_requested = on;
}

void
brake_thread(struct pt *pt)
{
    static timer_t brake_timer = { .delay_ms = 0 };

    pt_begin(pt);
    timer_register(&brake_timer);

    output_request(OUTPUT_BRAKE_L, true);
    output_request(OUTPUT_BRAKE_R, true);

    for (;;) {
        pt_yield(pt);
    }

    pt_end(pt);
}

