#pragma once
#include <common.h>

/** Global millisecond time base */
extern volatile uint32_t TIME_MS;

/** Millisecond delay */
void delay_ms(uint32_t ms);

/** Second delay */
void delay_s(uint32_t s);

/** Schedule a periodic task (like a cron job). Returns success. */
bool register_periodic_task(void (*callback) (void), uint32_t interval_ms);

/** Schedule a future one-off task. Returns success. */
bool schedule_task(void (*callback)(void), uint32_t delay_ms);
