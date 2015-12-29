#include <common.h>

#include "utils/usart.h"
#include "utils/timebase.h"
#include "utils/debounce.h"

#include "init.h"
#include "blink.h"


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

	register_periodic_task(green_toggle, 1000);
	register_periodic_task(blink_blue, 5000);
}


int main(void)
{
	while (1);
}
