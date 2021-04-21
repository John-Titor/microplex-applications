/*
 * Light algorithms.
 */

#include <assert.h>

#include <pt.h>
#include <timer.h>

#include "defs.h"

light_state_t brake_light_requested;
light_state_t tail_light_requested;
light_state_t rain_light_requested;

void
brake_light_request(light_state_t state)
{
    assert(state < _LIGHT_STATE_MAX);

    // Requests are repeated regularly with the current
    // state; only do something if we see a different
    // state requested.
    //
    if (state != brake_light_requested) {

        // Update new requested state.
        //
        brake_light_requested = state;

        // Restart the thread.
        //
        pt_reset(&pt_brakes);
    }
}

void
brake_thread(struct pt *pt)
{
    static timer_t brake_timer = { .delay_ms = 0 };
    static timer_t brake_reset_timer = { .delay_ms = 0 };

    pt_begin(pt);

    // Lazy timer registration.
    //
    if (!timer_registered(brake_timer)) {
        timer_register(&brake_timer);
        timer_register(&brake_reset_timer);
    }

    
    // Turn lights off
    //
    if (brake_light_requested == LIGHT_OFF) {
        output_request(OUTPUT_BRAKE_L, OUTPUT_STATE_OFF);
        output_request(OUTPUT_BRAKE_R, OUTPUT_STATE_OFF);

        // Set a timer to detect whether we stay off for
        // more than 4s.
        //
        timer_reset(brake_reset_timer, 4000);
    }

    // If we have been off for > 4s, do the brake-on
    // animation.
    //
    else if (brake_light_requested == LIGHT_ON) {
        if (timer_expired(brake_reset_timer)) {

            output_request(OUTPUT_BRAKE_L, OUTPUT_STATE_ON);
            output_request(OUTPUT_BRAKE_R, OUTPUT_STATE_ON);
            pt_delay(pt, brake_timer, 200);

            output_request(OUTPUT_BRAKE_L, OUTPUT_STATE_OFF);
            output_request(OUTPUT_BRAKE_R, OUTPUT_STATE_ON);
            pt_delay(pt, brake_timer, 100);

            output_request(OUTPUT_BRAKE_L, OUTPUT_STATE_ON);
            output_request(OUTPUT_BRAKE_R, OUTPUT_STATE_OFF);
            pt_delay(pt, brake_timer, 100);

            output_request(OUTPUT_BRAKE_L, OUTPUT_STATE_OFF);
            output_request(OUTPUT_BRAKE_R, OUTPUT_STATE_ON);
            pt_delay(pt, brake_timer, 100);

            output_request(OUTPUT_BRAKE_L, OUTPUT_STATE_ON);
            output_request(OUTPUT_BRAKE_R, OUTPUT_STATE_OFF);
            pt_delay(pt, brake_timer, 100);
        }

        // Lights stay on now until thread is reset.
        //
        output_request(OUTPUT_BRAKE_L, OUTPUT_STATE_ON);
        output_request(OUTPUT_BRAKE_R, OUTPUT_STATE_ON);
    }

    // Lights alternate left/right while in fault state.
    //
    else if (brake_light_requested == LIGHT_FAULT) {
        for (;;) {
            output_request(OUTPUT_BRAKE_L, OUTPUT_STATE_OFF);
            output_request(OUTPUT_BRAKE_R, OUTPUT_STATE_ON);
            pt_delay(pt, brake_timer, 400);

            output_request(OUTPUT_BRAKE_L, OUTPUT_STATE_ON);
            output_request(OUTPUT_BRAKE_R, OUTPUT_STATE_OFF);
            pt_delay(pt, brake_timer, 400);
        }
    }

    pt_end(pt);
}


void
tail_light_request(light_state_t state)
{
    assert(state < LIGHT_FAULT);

    // If we are not in rain light mode, and this is a change
    // of state for the tail lights, update the requested state
    // and reset the thread to make it so.
    //
    if ((rain_light_requested != LIGHT_ON) &&
        (tail_light_requested != state)) {

        tail_light_requested = state;
        pt_reset(&pt_tails);
    }
}

void
rain_light_request(light_state_t state)
{
    assert(state < LIGHT_FAULT);

    // If this is a change of state for the rain lights, update
    // the requested state and reset the thread to make it so.
    //
    if (rain_light_requested != state) {
        rain_light_requested = state;
        pt_reset(&pt_tails);
    }
}

void
tails_thread(struct pt *pt)
{
    static timer_t tails_timer = { .delay_ms = 0 };

    pt_begin(pt);
 
    // Lazy timer registration.
    //
    if (!timer_registered(tails_timer)) {
        timer_register(&tails_timer);
    }

    // If rain light requested, blink lights at 2Hz.
    //
    while (rain_light_requested == LIGHT_ON) {
        output_request(OUTPUT_TAILS, OUTPUT_STATE_ON);
        pt_delay(pt, tails_timer, 250);
        output_request(OUTPUT_TAILS, OUTPUT_STATE_OFF);
        pt_delay(pt, tails_timer, 250);
    }

    // Set tail lights on/off as requested.
    //
    if (tail_light_requested == LIGHT_ON) {
        output_request(OUTPUT_TAILS, OUTPUT_STATE_ON);
    } else {
        output_request(OUTPUT_TAILS, OUTPUT_STATE_OFF);
    }

    pt_end(pt);
}
