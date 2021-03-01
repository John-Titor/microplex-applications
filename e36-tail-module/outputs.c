/*
 * High-side drivers.
 *
 * ref: VNQ5050AK-E datasheet
 */

#include <assert.h>

#include <board.h>
#include <timer.h>

#include "defs.h"

#define SENSE_OPEN_CURRENT      50      // mA: below this, output is open
#define SENSE_OVERLOAD_CURRENT  2500    // mA: over this, output is overloaded
#define SENSE_STUCK_VOLTAGE     2000    // mV: over this, output is stuck/shorted to +12

static output_state_t   output_state[_OUTPUT_ID_MAX];
uint8_t                 output_state_requested;

static uint16_t output_voltage(uint8_t output);
static uint16_t output_current(uint8_t output);
static void     output_control(uint8_t output, bool on);
static void     output_check(uint8_t output);

void
output_thread(struct pt *pt)
{
    static timer_t check_timer = { .delay_ms = 0 };
    pt_begin(pt);

    timer_register(&check_timer);

    for (;;) {

        // check outputs / timeout ticks every 50ms
        timer_reset(check_timer, 50);
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

/*
 * Client request for output on/off.
 */
void
output_request(uint8_t output, output_state_t state)
{
    assert(output < _OUTPUT_ID_MAX);

    switch (state) {
    case OUTPUT_STATE_OFF:
        output_state[output] = OUTPUT_STATE_OFF;
        output_control(output, false);
        output_state_requested &= ~((uint8_t)1 << output);
        break;
    case OUTPUT_STATE_ON:
        if (output_state[output] == OUTPUT_STATE_OFF) {
            output_control(output, true);
            output_state[output] = OUTPUT_STATE_ON;
        }
        output_state_requested |= (uint8_t)1 << output;
        break;
    default:
        assert(false);
    }

}

static uint16_t
output_voltage(uint8_t output)
{
    switch (output) {
    case 0: return monitor_get(MON_OUT_V_1);
    case 1: return monitor_get(MON_OUT_V_2);
    case 2: return monitor_get(MON_OUT_V_3);
    case 3: return monitor_get(MON_OUT_V_4);
    default: assert(false); return (0);
    }
}

static uint16_t
output_current(uint8_t output)
{
    switch (output) {
    case 0: return monitor_get(MON_OUT_I_1);
    case 1: return monitor_get(MON_OUT_I_2);
    case 2: return monitor_get(MON_OUT_I_3);
    case 3: return monitor_get(MON_OUT_I_4);
    default: assert(false); return (0);
    }
}

static void
output_control(uint8_t output, bool on)
{
    switch (output) {
    case 0: set_DO_HSD_1(on); break;
    case 1: set_DO_HSD_2(on); break;
    case 2: set_DO_HSD_3(on); break;
    case 3: set_DO_HSD_4(on); break;
    default: assert(false);
    }
}

// Refer to VNQ5050AE-K datasheet
//
//                                         +---------------------+
//                                         v                     |
// Output status state machine. >>->off<->on-(overload)->timeout-+
//                                         ^      ^
//                                         v      |
//                                       open-----+
//

static void
output_check(uint8_t output)
{
    const uint16_t output_mV = output_voltage(output);
    const uint16_t output_mA = output_current(output);
//    debug("%u: %umV %umA", output, output_mV, output_mA);

    // transitions from / actions in specific states
    //
    switch (output_state[output]) {

    case OUTPUT_STATE_OFF:
        break;

    case OUTPUT_STATE_ON:
        if (output_mA < SENSE_OPEN_CURRENT) {
            output_state[output] = OUTPUT_STATE_OPEN;
        }
        break;

    case OUTPUT_STATE_OPEN_TRIGGER:
        fault_set_output(output, OUT_FAULT_OPEN);
        break;

    case OUTPUT_STATE_OPEN_MAX:
        break;

    case OUTPUT_STATE_TIMEOUT_MAX:
        output_state[output] = OUTPUT_STATE_ON;
        output_control(output, true);
        break;

    default:
        assert(((output_state[output] >= OUTPUT_STATE_OPEN) &&
                (output_state[output] < OUTPUT_STATE_OPEN_MAX)) ||
               ((output_state[output] >= OUTPUT_STATE_TIMEOUT) &&
                (output_state[output] < OUTPUT_STATE_TIMEOUT_MAX)));
        output_state[output]++;
        break;
    }

    // transitions from general on/off states
    //
    if (output_state[output] < OUTPUT_STATE_ON) {

        // check for stuck-on or shorted to battery
        if (output_mV > SENSE_STUCK_VOLTAGE) {
            fault_set_output(output, OUT_FAULT_STUCK);
        } else {
            fault_clear_output(output, OUT_FAULT_STUCK);
        }
    }

    // if output is on (requested)
    if (output_state[output] >= OUTPUT_STATE_ON) {

        // check for open-load
        if (output_mA > SENSE_OPEN_CURRENT) {
            output_state[output] = OUTPUT_STATE_ON;
            fault_clear_output(output, OUT_FAULT_OPEN);
        }

        // check for over-current
        if (output_mA > SENSE_OVERLOAD_CURRENT) {
            fault_set_output(output, OUT_FAULT_OVERLOAD);
            output_control(output, false);
            output_state[output] = OUTPUT_STATE_TIMEOUT;
        } else {
            fault_clear_output(output, OUT_FAULT_OVERLOAD);
        }
    }
}
