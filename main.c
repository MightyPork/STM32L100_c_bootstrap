#include <common.h>

#include <stdio.h>

#include "utils/usart.h"
#include "utils/timebase.h"
#include "utils/debounce.h"
#include "utils/str_utils.h"

#include "init.h"
#include "blink.h"

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
		
		// echo
		usart_tx_char(USART2, c);

		USART2_SR ^= USART_SR_RXNE;
	}
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
}


int main(void)
{
	usart_tx_string(USART2, "Hello.\n");

	while (1) {
		delay_ms(500);
		green_toggle();
	}
}
