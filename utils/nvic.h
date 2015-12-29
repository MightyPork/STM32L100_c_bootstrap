#pragma once
#include "common.h"

// implementation stolen from libopencm3, originally under LGPL

void nvic_enable_irq(uint8_t irqn);

void nvic_disable_irq(uint8_t irqn);

uint8_t nvic_get_pending_irq(uint8_t irqn);

void nvic_set_pending_irq(uint8_t irqn);

void nvic_clear_pending_irq(uint8_t irqn);

uint8_t nvic_get_irq_enabled(uint8_t irqn);

void nvic_set_priority(uint8_t irqn, uint8_t priority);

void nvic_set_priority_arm(int8_t irqn, uint8_t priority); // negative numbers (ie SYSTICK)

uint8_t nvic_get_active_irq(uint8_t irqn);

void nvic_generate_software_interrupt(uint16_t irqn); // 0-239
