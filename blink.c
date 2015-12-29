#include "blink.h"

#include "utils/timebase.h"

void green_toggle(void) { GPIOC_ODR ^= BIT9; }
void green_off(void) { GPIOC_ODR &= ~BIT9; }
void green_on(void) { GPIOC_ODR |= BIT9; }
void blue_toggle(void) { GPIOC_ODR ^= BIT8; }
void blue_on(void) { GPIOC_ODR |= BIT8; }
void blue_off(void) { GPIOC_ODR &= ~BIT8; }

void blink_green(void)
{
	green_on();
	schedule_task(green_off, 250);
}

void blink_blue(void)
{
	blue_on();
	schedule_task(blue_off, 250);
}
