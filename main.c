#include <common.h>

#include "utils/usart.h"
#include "utils/timebase.h"

#include "init.h"


void blink(void) {
	GPIOC_ODR ^= BIT9;
}



/** Called before main() */
void SystemInit(void)
{
	init_clock();
	init_systick();
	init_gpios();
	init_usart();

	schedule_timed_task(blink, 500);
}


int main(void)
{
	while (1) {
		delay_ms(1000);
		GPIOC_ODR ^= BIT8;

		usart_tx_string(USART3, "HELLO\r\n");
	}
}
