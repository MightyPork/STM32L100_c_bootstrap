#pragma once
#include <common.h>

extern volatile uint32_t TIME_MS;

void delay_ms(uint32_t ms);
void delay_s(uint32_t s);

/** Schedule a periodic task (like a cron job). Returns success. */
bool register_periodic_task(void (*callback) (void), uint32_t interval_ms);

/** Schedule a future one-off task. Returns success. */
bool register_future_task(void (*callback)(void), uint32_t delay_ms);
