#include "systick.h"

void systick_setup(uint32_t prescaller)
{
	SysTick_CSR = (SysTick_CSR & ~SysTick_CSR_CLKSOURCE) | SysTick_CSR_CLKSOURCE_CORE;
	SysTick_RELOAD = prescaller;
	SysTick_CSR |= SysTick_CSR_TICKINT | SysTick_CSR_ENABLE;
}


void systick_enable(void)
{
	SysTick_CSR |= SysTick_CSR_ENABLE;
}


void systick_disable(void)
{
	SysTick_CSR &= ~SysTick_CSR_ENABLE;
}
