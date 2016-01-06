#include "capture.h"
#include "utils/timebase.h"
#include <math.h>

uint16_t adc_measure(uint8_t channel)
{
	ADC1_SQR5 = channel; // select n-th channel
	ADC1_SQR1 = 0; // sets length to 1 (0000)

	ADC1_CR2 |= ADC_CR2_SWSTART; // start conversion

	// wait for end of conversion
	while (!(ADC1_SR & ADC_SR_EOC));
	return ADC1_DR;
}


float measure_angle(void)
{
	uint16_t d = adc_measure(18);
	return -135 + 270 * (d / 4095.0f);
}


float measure_exposure(void)
{
	uint16_t d = adc_measure(8);
	float alpha = d / 4095.0f;
	return alpha * 100; // %
}


float measure_resistance(void)
{
	uint16_t d = adc_measure(9);

	float alpha = d / 4095.0f;
	float ref_r = 330;

	return (ref_r * alpha) / (1 - alpha);
}


float measure_temp(void)
{
	uint16_t ts_data = adc_measure(ADC_CH_TEMP);

	// temperature calibration constants for L100 are undocumented,
	// probably because the sensor is broken.

	// Temperature sensor is unstable and unreliable.

	uint16_t ts_cal1 = MMIO16(0x1FF800FA);
	uint16_t ts_cal2 = MMIO16(0x1FF800FE);

	return ((80.0f / (ts_cal2 - ts_cal1)) * (ts_data - ts_cal1) + 30.0f);
}


void pwm2_set_frequency(float hz)
{
	float core_clk = 16000000 / 2.0f; // prescaller

	float cnt = core_clk / hz;

	uint32_t div = (uint32_t)cnt;

	if (hz < 150) {
		div /= 8;
		TIM2_PSC = 15;
	} else {
		TIM2_PSC = 1;
	}

	TIM2_ARR = div; // sets frequency
	TIM2_CCR2 = TIM2_ARR/2; // duty cycle
}
