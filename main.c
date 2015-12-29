#include <common.h>

#include "utils/usart.h"
#include "utils/timebase.h"

#include "init.h"

void blink_green(void)
{
	GPIOC_ODR ^= BIT9;
}


// --- async delayed blue blink ---

bool blue_blink_pending = false;

void blue_off(void)
{
	GPIOC_ODR &= ~BIT8;
	blue_blink_pending = false;
}

void blink_blue(void)
{
	GPIOC_ODR |= BIT8;
	register_future_task(blue_off, 200);
}


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

	register_periodic_task(blink_green, 500);
	register_periodic_task(say_hello, 1000);
}


int main(void)
{
	int btn_c = 0;
	while (1) {
		bool btn = GPIOA_IDR & BIT0;
		if (btn) {
			if (btn_c++ > 20 && !blue_blink_pending) {
				blue_blink_pending = true;
				register_future_task(blink_blue, 1000);
			}
		} else {
			btn_c = 0;
		}

		delay_ms(1);
	}
}
