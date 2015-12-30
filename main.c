#include <common.h>

#include "utils/usart.h"
#include "utils/timebase.h"
#include "utils/debounce.h"

#include "init.h"
#include "blink.h"

void say_hello(void)
{
	usart_tx_string(USART3, "HELLO\r\n");
}


/** IRQ */
void USART2_IRQHandler(void)
{
	// RXIE enables also ORE - must handle ORE.
	if (USART2_SR & USART_SR_ORE) {
		USART2_SR &= ~USART_SR_ORE;
	}

	if (USART2_SR & USART_SR_RXNE) {
		blue_blink();

		char c = usart_rx_char(USART2);
		usart_tx_char(USART2, c);

		USART2_SR ^= USART_SR_RXNE;
	}
}



/** Called by startup script, before main() */
void SystemInit(void)
{
	init_clock();
	init_systick();
	init_gpios();
	init_usart();
	init_adc();

	register_periodic_task(green_toggle, 1000);
}


int main(void)
{
	while (1);
}
