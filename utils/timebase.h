#pragma once
#include <common.h>

extern volatile uint32_t TIME_MS;

void delay_ms(uint32_t ms);
void delay_s(uint32_t s);

/** Schedule a timed task (like a cron job) */
bool schedule_timed_task(void (*callback) (void), uint32_t interval_ms);
