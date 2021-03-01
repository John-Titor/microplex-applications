/*
 * Light algorithms.
 */

#include <pt.h>
#include <timer.h>

#include "defs.h"

static light_state_t brake_light_requested;
static light_state_t tail_light_requested;
static light_state_t rain_light_requested;

void
brake_light_request(light_state_t state)
{
    brake_light_requested = state;
    if (state == LIGHT_OFF) {
        pt_reset(&pt_brakes);
    }
}

void
brake_thread(struct pt *pt)
{
    static timer_t brake_timer = { .delay_ms = 0 };

    pt_begin(pt);
    if (!timer_registered(brake_timer)) {
        timer_register(&brake_timer);
    }

    output_request(OUTPUT_BRAKE_L, false);
    output_request(OUTPUT_BRAKE_R, false);

    pt_wait(pt, brake_light_requested != LIGHT_OFF);

    output_request(OUTPUT_BRAKE_L, true);
    output_request(OUTPUT_BRAKE_R, true);
    pt_delay(pt, brake_timer, 200);

    output_request(OUTPUT_BRAKE_L, false);
    output_request(OUTPUT_BRAKE_R, true);
    pt_delay(pt, brake_timer, 200);

    output_request(OUTPUT_BRAKE_L, true);
    output_request(OUTPUT_BRAKE_R, false);
    pt_delay(pt, brake_timer, 200);

    output_request(OUTPUT_BRAKE_L, false);
    output_request(OUTPUT_BRAKE_R, true);
    pt_delay(pt, brake_timer, 200);

    output_request(OUTPUT_BRAKE_L, true);
    output_request(OUTPUT_BRAKE_R, false);
    pt_delay(pt, brake_timer, 200);

    output_request(OUTPUT_BRAKE_L, true);
    output_request(OUTPUT_BRAKE_R, true);

    pt_end(pt);
}

void
tail_light_request(light_state_t state)
{
    tail_light_requested = state;
    pt_reset(&pt_tails);
}

void
rain_light_request(light_state_t state)
{
    rain_light_requested = state;
    pt_reset(&pt_tails);
}

void
tails_thread(struct pt *pt)
{
    static timer_t tails_timer = { .delay_ms = 0 };

    pt_begin(pt);
    if (!timer_registered(tails_timer)) {
        timer_register(&tails_timer);
    }

    while (rain_light_requested == LIGHT_ON) {
        output_request(OUTPUT_TAILS, OUTPUT_STATE_ON);
        pt_delay(pt, tails_timer, 250);
        output_request(OUTPUT_TAILS, OUTPUT_STATE_OFF);
        pt_delay(pt, tails_timer, 250);
    }

    if (tail_light_requested == LIGHT_ON) {
        output_request(OUTPUT_TAILS, OUTPUT_STATE_ON);
    } else {
        output_request(OUTPUT_TAILS, OUTPUT_STATE_OFF);
    }

    pt_end(pt);
}
