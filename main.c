#include <common.h>

#include <stdio.h>

#include "utils/usart.h"
#include "utils/timebase.h"
#include "utils/debounce.h"
#include "utils/str_utils.h"

#include "init.h"
#include "blink.h"
#include "capture.h"

// Gate state
static bool gate_closed = false;
static uint32_t gate_cnt = 0;

static float exposure_out, exposure_accum;
static uint32_t exposure_cnt;

static uint32_t pwm2_f = 50;

/** IRQ */
void USART2_IRQHandler(void)
{
	// RXIE enables also ORE - must handle ORE.
	if (USART2_SR & USART_SR_ORE) {
		USART2_SR &= ~USART_SR_ORE;
	}

	if (USART2_SR & USART_SR_RXNE) {
		blue_blink();

		// handle incoming char.
		char c = usart_rx_char(USART2);

		uint32_t pwm2_f_old = pwm2_f;

		switch (c) {
			case 'g': // nulovat pocitadlo preruseni
				gate_cnt = 0;
				break;

			case 'm': // zvysit DAC hodnotu
				if (DAC_DHR12R1 < 4095) DAC_DHR12R1 += 117;
				break;

			case 'n': // snizit DAC hodnotu
				if (DAC_DHR12R1 > 0) DAC_DHR12R1 -= 117;
				break;

			case 'b': // zvysit PWM stridu
				if (TIM3_CCR1 < 1000) TIM3_CCR1 += 50;
				break;

			case 'd': // snizit PWM stridu
				if (TIM3_CCR1 > 0) TIM3_CCR1 -= 50;
				break;

			case 'f': // zvysit PWM stridu
				if (pwm2_f < 20000) pwm2_f += 10;
				break;

			case 's': // snizit PWM stridu
				if (pwm2_f > 20) pwm2_f -= 10;
				break;

			case 'F': // zvysit PWM stridu
				if (pwm2_f < 20000-100) pwm2_f += 100;
				break;

			case 'S': // snizit PWM stridu
				if (pwm2_f > 100) {
					pwm2_f -= 100;
				} else {
					pwm2_f = 20;
				}

				if (pwm2_f < 20) pwm2_f = 20;

				break;

			default:
				break;
		}

		if (pwm2_f_old != pwm2_f) {
			pwm2_set_frequency(pwm2_f);
		}

		USART2_SR ^= USART_SR_RXNE;
	}
}



// Gate close handler
void gate_close(void)
{
	gate_closed = 1;
	gate_cnt++;
}

// Gate open handler
void gate_open(void)
{
	gate_closed = 0;
}


/** Init peripherals; Called by startup script, before main() */
void SystemInit(void)
{
	init_clock();
	init_systick();
	init_gpios();
	init_usart();
	init_adc();
	init_dac();
	init_pwm1();
	init_pwm2();

	pwm2_set_frequency(50);

	register_periodic_task(green_toggle, 1000); // indicate running state

	register_debounced_pin(GPIOB, 11, gate_close, gate_open); // gate handler
}



int main(void)
{
	char buf[200];

	usart_tx_string(USART2, "DAQ system started.\n");
	delay_ms(100);

	bool first = true;
	while (1) {
		float cels = measure_temp();
		float angle = measure_angle();
		float resis = measure_resistance();
		float expos = measure_exposure();

		// --- exposure averaging
		exposure_accum += expos;
		exposure_cnt++;

		if (exposure_cnt >= 5) {
			exposure_out = exposure_accum / exposure_cnt;
			exposure_accum = 0;
			exposure_cnt = 0;
		}

		if (first) {
			exposure_out = expos; // pretend it's averaged
		}
		// ---


		buf_reset(buf);
		buf_append_str(buf, "T ");
		buf_append_flt(buf, cels, 1);
		buf_append_str(buf, "°C | ");

		buf_append_str(buf, "An ");
		buf_append_flt(buf, angle, 1);
		buf_append_str(buf, "° | ");

		buf_append_str(buf, "R ");
		buf_append_flt(buf, resis, 1);
		buf_append_str(buf, " | ");

		buf_append_str(buf, "L ");
		buf_append_flt(buf, exposure_out, 1);
		buf_append_str(buf, "% | ");

		buf_append_str(buf, "G ");
		buf_append_str(buf, gate_closed ? "1" : "0");
		buf_append_str(buf, ", #");
		buf_append_int(buf, gate_cnt);
		buf_append_str(buf, " | ");

		buf_append_str(buf, "DA ");
		buf_append_int(buf, DAC_DHR12R1);
		buf_append_str(buf, " | ");

		buf_append_str(buf, "PWM ");
		buf_append_int(buf, TIM3_CCR1);

		buf_append_str(buf, "\n");

		usart_tx_string(USART2, buf);

		delay_ms(100);
		first = false;
	}
}
