#pragma once
#include <common.h>

// Debouncer requires that you setup SysTick first.

bool register_debounced_pin(uint32_t gpio, uint8_t n, void (*rising_cb)(void), void (*falling_cb)(void));
