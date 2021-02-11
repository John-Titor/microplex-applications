/*
 * High-side drivers.
 *
 * ref: VNQ5050K-E datasheet
 *
 * Theory of operation:
 *
 * Output state changes are requested by a call to output_request(),
 * which sets the target state for the output.
 *
 * The output thread updates the output state, and then after 2ms
 * evaluates the state of the output.  
 *
 * Outputs that are off are checked for stuck-on conditions, and
 * fault status updated as appropriate.
 * XXX TODO: add open-load check
 *
 * Outputs that are on are checked for over-current, over-temperature
 * and open-circuit conditions, and fault status update as appropriate.
 * Over-current and over-temperature conditions will also result in the
 * output being turned off. 
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

static bool     output_state[NUM_OUTPUTS];

static void     output_set_requested();
static bool     output_sense(uint8_t output);
static uint16_t output_voltage(uint8_t output);
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
        // set outputs
        output_set_requested();

        // check outputs
        timer_reset(check_timer, 2);
        pt_wait(pt, timer_expired(check_timer));
        output_check(0);
        pt_yield(pt);
        output_check(1);
        pt_yield(pt);
        output_check(2);
        pt_yield(pt);
        output_check(3);
    }
    pt_end(pt);
}

void
output_request(uint8_t output, bool on)
{
    assert(output < NUM_OUTPUTS);

    output_state[output] = on;
}

static void
output_set_requested()
{
    set_DO_HSD_1(output_state[0]);
    set_DO_HSD_2(output_state[1]);
    set_DO_HSD_3(output_state[2]);
    set_DO_HSD_4(output_state[3]);
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
output_control(uint8_t output, bool on)
{
    switch (output) {
    case 0: set_DO_HSD_1(on); break;
    case 1: set_DO_HSD_2(on); break;
    case 2: set_DO_HSD_3(on); break;
    case 3: set_DO_HSD_4(on); break;
    }
}

// Refer to VNQ5050E-K datasheet, table 12 and figure 29.
//
static void
output_check(uint8_t output)
{
    // XXX might want to check for some conditions (e.g. short cleared)
    //     less often?

    if (output_state[output]) {
        // output is on

        // check for over-current
        if (output_voltage(output) < OUT_OVERLOAD_THRESHOLD) {
            // current limiting in play, need to disable output
            fault_set_output(output, OUT_FAULT_OVERLOAD);
            output_state[output] = false;
        } else if (!output_sense(output)) {
            __critical {
                // turn the output off
                output_control(output, false);
                // wait ~1/2 the min tPOL
                time_wait_us(100);
                if (output_sense(output)) {
                    // sense has gone high, fault was overtemp, turn off
                    fault_set_system(SYS_FAULT_OVERTEMP);
                    output_state[output] = false;
                } else {
                    // sense has not gone high, fault is open load
                    // turn the output back on, as it may come good
                    fault_set_output(output, OUT_FAULT_OPEN);
                    output_control(output, true);
                }
            }
        } else {
            // output seems OK
            fault_clear_output(output, OUT_FAULT_OPEN);
            fault_clear_output(output, OUT_FAULT_OVERLOAD);
        }

    } else {
        // output is off

        // check for short to power / stuck on
        if (output_voltage(output) > OUT_STUCK_THRESHOLD) {
            fault_set_output(output, OUT_FAULT_STUCK);
        } else {
            // output seems OK
            fault_clear_output(output, OUT_FAULT_STUCK);
        }
        // XXX TODO: check for open-circuit
    }
}
