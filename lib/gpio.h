#pragma once

#include "common.h"

enum GPIO_MODE {
	MODER_INPUT = 0,
	MODER_OUTPUT = 1,
	MODER_AF = 2,
	MODER_ANALOG = 3,
};

enum GPIO_AF {
	AF0 = 0,
	AF1 = 1,
	AF2 = 2,
	AF3 = 3,
	AF4 = 4,
	AF5 = 5,
	AF6 = 6,
	AF7 = 7,
	AF8 = 8,
	AF9 = 9,
	AF10 = 10,
	AF11 = 11,
	AF12 = 12,
	AF13 = 13,
	AF14 = 14,
	AF15 = 15,
};


/**
 * Enable GPIO in RCC
 * @param gpio GPIO base
 */
void gpio_enable(uint32_t gpio);

/**
 * Disable GPIO in RCC
 * @param gpio GPIO base
 */
void gpio_disable(uint32_t gpio);

/**
 * Set GPIO AF (writes MODER and AFR).
 * Also enables the port if disabled in RCC.
 * @param gpio GPIO base
 * @param pins pins bitmask
 * @param af alternate function 0..15
 */
void gpio_set_af(uint32_t gpio, uint32_t pins, enum GPIO_AF af);


/**
 * Set pins mode (writes MODER)
 * @param gpio GPIO base
 * @param pins pins bitmask
 * @param mode mode to set
 */
void gpio_set_mode(uint32_t gpio, uint32_t pins, enum GPIO_MODE mode);
