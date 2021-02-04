/*
 * Analog to digital conversion.
 */

#include <math.h>
#include <stdint.h>

#define ADC_AVG_SAMPLES			8

// initialize the scale_factor channel state element
//#define ADC_SCALE_FACTOR(_fulL_scale_value)	((float)(_full_scale_value) / (1023 * 8))

typedef struct
{
	uint8_t		channel:5;
	uint8_t		index:3;
	uint16_t	scale_factor;
	uint16_t	samples[ADC_AVG_SAMPLES];
} adc_channel_state_t;

#define ADC_UNSCALED	4096

extern void		adc_init();
extern void		adc_configure(adc_channel_state_t *state);
extern void 	adc_update(adc_channel_state_t *state);
extern uint16_t adc_result(adc_channel_state_t *state);
extern uint16_t adc_result_unscaled(adc_channel_state_t *state);