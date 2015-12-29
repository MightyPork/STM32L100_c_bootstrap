#include <common.h>

#include "utils/usart.h"
#include "utils/timebase.h"
#include "utils/debounce.h"

#include "init.h"

void blink_green(void)
{
	GPIOC_ODR ^= BIT9;
}

void blink_blue(void)
{
	GPIOC_ODR ^= BIT8;
}

void blue_on(void) { GPIOC_ODR |= BIT8; }
void blue_off(void) { GPIOC_ODR &= ~BIT8; }

// called every 1s

void say_hello(void)
{
	usart_tx_string(USART3, "HELLO\r\n");
}


/** Called before main() */
void SystemInit(void)
{
	init_clock();
	init_systick();
	init_gpios();
	init_usart();

	register_periodic_task(blink_green, 1000);
	//register_periodic_task(blink_blue, 1000);
	register_periodic_task(say_hello, 1000);

	register_debounced_pin(GPIOA, 0, blue_on, blue_off);
}


int main(void)
{
	while (1);
}
