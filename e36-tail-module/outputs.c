/*
 * High-side drivers.
 *
 * ref: VNQ5050K-E datasheet
 */

#include <assert.h>

#include <adc.h>
#include <board.h>
#include <timer.h>

#include "defs.h"

#define NUM_OUTPUTS             4

// voltage levels in raw ADC counts
#define OUT_STUCK_THRESHOLD     200 // above this -> output shorted to power
#define OUT_OVERLOAD_THRESHOLD  800 // below this -> output in current-limit

static uint8_t  output_state[NUM_OUTPUTS];

static void     output_control(uint8_t output, bool on);
static bool     output_sense(uint8_t output);
static uint16_t output_voltage(uint8_t output);
static void     output_update(void);
static void     output_check(uint8_t output);

void
output_thread(struct pt *pt)
{
    static timer_t check_timer;
    pt_begin(pt);

    timer_register(&check_timer);

    adc_configure_direct(AI_OP_1);
    adc_configure_direct(AI_OP_2);
    adc_configure_direct(AI_OP_3);
    adc_configure_direct(AI_OP_4);

    while (pt_running(pt)) {
        timer_reset(check_timer, 2);
        pt_wait(pt, timer_expired(check_timer));
        output_check(0);

        timer_reset(check_timer, 2);
        pt_wait(pt, timer_expired(check_timer));
        output_check(1);

        timer_reset(check_timer, 2);
        pt_wait(pt, timer_expired(check_timer));
        output_check(2);

        timer_reset(check_timer, 2);
        pt_wait(pt, timer_expired(check_timer));
        output_check(3);
    }
    pt_end(pt);
}

void
output_request(uint8_t output, bool on)
{
    assert(output < NUM_OUTPUTS);

    // can't control faulted outputs
    if (output_state[output] < _OUT_STATE_PERMANENT_FAULT_STATES) {
        output_state[output] = on ? OUT_STATE_ON : OUT_STATE_OFF;
        output_update();
    }
}

uint8_t
output_status(uint8_t output)
{
    assert(output < NUM_OUTPUTS);
    return output_state[output];
}

static void
output_control(uint8_t output, bool on)
{
    assert(output < NUM_OUTPUTS);
    switch (output) {
    case 0: set_DO_HSD_1(on); break;
    case 1: set_DO_HSD_2(on); break;
    case 2: set_DO_HSD_3(on); break;
    case 3: set_DO_HSD_4(on); break;
    }
}

static bool
output_sense(uint8_t output)
{
    assert(output < NUM_OUTPUTS);
    switch (output) {
    case 0: return test_DI_CS_1();
    case 1: return test_DI_CS_2();
    case 2: return test_DI_CS_3();
    case 3: return test_DI_CS_4();
    }
    return false;
}

static uint16_t
output_voltage(uint8_t output)
{
    assert(output < NUM_OUTPUTS);
    switch (output) {
    case 0: return adc_sample_direct(AI_OP_1);
    case 1: return adc_sample_direct(AI_OP_2);
    case 2: return adc_sample_direct(AI_OP_3);
    case 3: return adc_sample_direct(AI_OP_4);
    }
    return false;
}

static void
output_update(void)
{
    for (uint8_t i = 0; i < NUM_OUTPUTS; i++) {
        output_control(i, output_state[i] == OUT_STATE_ON);
    }
}

// Refer to VNQ5050E-K datasheet, table 12 and figure 29.
//
static void
output_check(uint8_t output)
{
    // XXX might want to check for some conditions (e.g. short cleared)
    //     less often

    switch (output_state[output]) {
    case OUT_STATE_OFF:
        // check for short to power / stuck on
        if (output_voltage(output) > OUT_STUCK_THRESHOLD) {
            output_state[output] = OUT_STATE_STUCK;
        }
        // check for open-circuit
        output_control(output, true);
        time_wait_us(200);      // - wait tDOL
        if (!output_sense(output)) {
            // status low, open circuit
            output_state[output] = OUT_STATE_OPEN_CIRCUIT;
        }
        break;

    case OUT_STATE_ON:
        // check for over-current
        if (output_voltage(output) < OUT_OVERLOAD_THRESHOLD) {
            // current limiting in play
            output_state[output] = OUT_STATE_OVERLOAD;
        } else if (!output_sense(output)) {
            // turn off
            output_control(output, false);
            // wait tPOL
            time_wait_us(1000);
            if (output_sense(output)) {
                // sense has gone high, fault was open load
                output_state[output] = OUT_STATE_OPEN_CIRCUIT;
            } else {
                // sense has not gone high, fault is overtemp
                output_state[output] = OUT_STATE_OVERTEMP;
            }
        }
        break;

    case OUT_STATE_OPEN_CIRCUIT:
    case OUT_STATE_OVERLOAD:
    case OUT_STATE_OVERTEMP:
        // check for short removed and overtemp cleared by powering
        // output and checking voltage & status
        output_control(output, true);
        time_wait_us(200);      // wait for output to settle, tDOL
        if ((output_voltage(output) > OUT_OVERLOAD_THRESHOLD) &&
            (output_sense(output) == true)) {

            // condition has cleared
            output_state[output] = OUT_STATE_OFF;
        }
        break;

    case OUT_STATE_STUCK:
        // check for short removed
        if (output_voltage(output) < OUT_STUCK_THRESHOLD) {
            // voltage is appropriately low
            output_state[output] = OUT_STATE_OFF;
        }
        break;
    }

    // update the state of the output based on our assessment
    output_control(output, output_state[output] == OUT_STATE_ON);
}
