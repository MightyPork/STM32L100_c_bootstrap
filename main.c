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
void USART3_IRQHandler(void)
{
	if (USART3_SR & USART_SR_ORE) {
		USART3_SR &= ~USART_SR_ORE;
		return;
	}

	blue_blink();

	char c = usart_rx_char(USART3);
	usart_tx_char(USART3, c);

	USART3_SR ^= USART_SR_RXNE;
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
