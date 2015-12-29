#include "nvic.h"

// implementation stolen from libopencm3, originally under LGPL

void nvic_enable_irq(uint8_t irqn)
{
	NVIC_ISER(irqn / 32) = (1 << (irqn % 32));
}


void nvic_disable_irq(uint8_t irqn)
{
	NVIC_ICER(irqn / 32) = (1 << (irqn % 32));
}


uint8_t nvic_get_pending_irq(uint8_t irqn)
{
	return NVIC_ISPR(irqn / 32) & (1 << (irqn % 32)) ? 1 : 0;
}


void nvic_set_pending_irq(uint8_t irqn)
{
	NVIC_ISPR(irqn / 32) = (1 << (irqn % 32));
}


void nvic_clear_pending_irq(uint8_t irqn)
{
	NVIC_ICPR(irqn / 32) = (1 << (irqn % 32));
}


uint8_t nvic_get_irq_enabled(uint8_t irqn)
{
	return NVIC_ISER(irqn / 32) & (1 << (irqn % 32)) ? 1 : 0;
}


void nvic_set_priority(uint8_t irqn, uint8_t priority)
{
	NVIC_IPR(irqn) = priority;
}


void nvic_set_priority_arm(int8_t irqn, uint8_t priority)
{
	SCS_SHPR((irqn & 0xF) - 4) = priority; // maybe wrong
}


uint8_t nvic_get_active_irq(uint8_t irqn)
{
	return NVIC_IABR(irqn / 32) & (1 << (irqn % 32)) ? 1 : 0;
}


void nvic_generate_software_interrupt(uint16_t irqn)
{
	if (irqn <= 239) {
		NVIC_STIR |= irqn;
	}
}
