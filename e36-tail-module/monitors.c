/*
 * Input monitoring.
 */

#include <assert.h>

#include <adc.h>
#include <timer.h>

#include "defs.h"

// Table here must monitor_channel_t
static
adc_channel_state_t adc_cfg[] = {
    // fast-polled channels
    // XXX 70us channel * 9 channels = ~650us, need to be careful not to
    //     run over the 1000us max callout time - maybe split this into
    //     two groups.
    { .channel = AI_KL15, .scale_factor = ADC_SCALE_FACTOR_KL15 },
    { .channel = AI_OP_1, .scale_factor = ADC_SCALE_FACTOR_DO_V },
    { .channel = AI_OP_2, .scale_factor = ADC_SCALE_FACTOR_DO_V },
    { .channel = AI_OP_3, .scale_factor = ADC_SCALE_FACTOR_DO_V },
    { .channel = AI_OP_4, .scale_factor = ADC_SCALE_FACTOR_DO_V },
    { .channel = AI_CS_1, .scale_factor = ADC_SCALE_FACTOR_DO_I },
    { .channel = AI_CS_2, .scale_factor = ADC_SCALE_FACTOR_DO_I },
    { .channel = AI_CS_3, .scale_factor = ADC_SCALE_FACTOR_DO_I },
    { .channel = AI_CS_4, .scale_factor = ADC_SCALE_FACTOR_DO_I },

    // slow-polled channels
    { .channel = AI_1,    .scale_factor = ADC_SCALE_FACTOR_10V  },
    { .channel = AI_3,    .scale_factor = ADC_SCALE_FACTOR_30V  },
    { .channel = AI_TEMP, .scale_factor = ADC_SCALE_FACTOR_TEMP },
};
static const uint8_t num_adc_fast_cfg = 9;
static const uint8_t num_adc_cfg = sizeof(adc_cfg) / sizeof(adc_cfg[0]);
//static_assert(_MON_ID_MAX == (sizeof(adc_cfg) / sizeof(adc_cfg[0]),
//              "monitor_channel_t / adc_cfg mismatch");

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

    if (phase++ >= 20) {
        phase = 0;
    }
}
#pragma restore

timer_call_t monitor_call = {
    .delay_ms = 1,
    .period_ms = 5,
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
