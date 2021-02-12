/*
 * Input monitoring.
 */

#include <adc.h>
#include <assert.h>
#include <timer.h>

#include "defs.h"

static
adc_channel_state_t adc_cfg[] = {
    // fast-polled channels
    {
        // T15 input - clamps to 11V
        .channel = AI_KL15,
        .scale_factor = ADC_SCALE_FACTOR_KL15
    },

    // slow-polled channels
    {
        // fuel level sensor
        .channel = AI_1,
        .scale_factor = ADC_SCALE_FACTOR_10V
    },
};
static const uint8_t num_adc_fast_cfg = 1;
static const uint8_t num_adc_cfg = sizeof(adc_cfg) / sizeof(adc_cfg[0]);

#pragma save
#pragma nooverlay
static void
monitor_sample(void)
{
    static uint8_t phase;

    // all channels if phase == 0, only fast channels otherwise
    const uint8_t count = (phase == 0) ? num_adc_cfg : num_adc_fast_cfg;

    for (uint8_t i = 0; i < count; i++) {
        adc_update(&adc_cfg[i]);
    }

    if (phase++ >= 10) {
        phase = 0;
    }
}
#pragma restore

timer_call_t monitor_call = {
    .delay_ms = 100,
    .period_ms = 10,
    .callback = monitor_sample
};

void
monitor_init()
{
    // basic ADC init
    adc_init();

    // configure ADC channels
    for (uint8_t i = 0; i < num_adc_cfg; i++) {
        adc_configure(&adc_cfg[i]);
    }

    // set fuel level sensor to 10V mode
    set_DO_30V_10V_1(AI_MODE_10V);

    // register timer callback
    timer_call_register(&monitor_call);
}

uint16_t
monitor_get(uint8_t channel)
{
    assert(channel < num_adc_cfg);
    return adc_result(&adc_cfg[channel]);
}
