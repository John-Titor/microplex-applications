/*
 * ADC
 */

#include <adc.h>
#include <timer.h>

#include <mc9s08dz60.h>

void
adc_init()
{
    ADCCFG_ADICLK = 0;  // bus clock (20MHz)
    ADCCFG_MODE = 2;    // 10-bit mode
    ADCCFG_ADLSMP = 1;  // long sample time
    ADCCFG_ADIV = 2;    // /4 -> 5MHz ADCCLK

    // configure for manual conversion trigger
    ADCSC2 = 0;
}

void
adc_configure(adc_channel_state_t *state)
{
    if (state->channel < 8) {
        APCTL1 |= (1 << state->channel);
    } else if (state->channel < 16) {
        APCTL2 |= (1 << (state->channel - 8));
    } else if (state->channel < 24) {
        APCTL3 |= (1 << (state->channel - 16));
    } else {
        // channels above 24 are not assigned to pins
    }

    // prime the channel with samples
    for (uint8_t i = 0; i < ADC_AVG_SAMPLES; i++) {
        adc_update(state);
    }
}

void
adc_update(adc_channel_state_t *state)
{
    ADCSC1_ADCH = state->channel;
    // wait for completion
    while (!ADCSC1_COCO) {
    }
    state->samples[state->index++] = ADCR;
}

// 44us unscaled
// 290us scaled
uint16_t
adc_result(adc_channel_state_t *state)
{
    uint16_t accum = 0;

    // interrupt-safe loop accumulates samples
    for (uint8_t i = 0; i < ADC_AVG_SAMPLES; i++) {
        uint16_t v;
        __critical v = state->samples[i];
        accum += v;
    }
    if (state->scale_factor == ADC_UNSCALED) {
        return accum >> 8;
    } else {
        return (uint16_t)(accum * state->scale_factor);
    }
}
