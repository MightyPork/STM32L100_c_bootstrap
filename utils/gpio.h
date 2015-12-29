#pragma once

#include "common.h"

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
