#include "timebase.h"

volatile uint32_t TIME_MS;

#define TASK_COUNT 10

// --- time scheduler system ---
typedef struct {
	/** User callback */
	void (*callback) (void);
	/** Callback interval */
	uint32_t interval_ms;
	/** Counter, when reaches interval_ms, is cleared and callback is called. */
	uint32_t countup;
} timebase_cb_t;

static uint8_t scheduled_task_n = 0;
static timebase_cb_t scheduled_tasks[TASK_COUNT];


bool schedule_timed_task(void (*callback) (void), uint32_t interval_ms)
{
	if (scheduled_task_n >= TASK_COUNT) return false;

	// add the task
	timebase_cb_t *task = &scheduled_tasks[scheduled_task_n++];
	task->callback = callback;
	task->countup = 0;
	task->interval_ms = interval_ms;

	return true;
}


/** IRQ */
void SysTick_Handler(void)
{
	TIME_MS++;

	// run scheduled tasks
	for (int i = 0; i < scheduled_task_n; i++) {
		timebase_cb_t *task = &scheduled_tasks[i];
		if (task->countup++ >= task->interval_ms) {
			task->callback();
			task->countup = 0;
		}
	}
}


void delay_ms(uint32_t ms)
{
	uint32_t last_ms = TIME_MS;

	while (ms-- != 0) {
		while (TIME_MS == last_ms);
		last_ms = TIME_MS;
	}
}



void delay_s(uint32_t s)
{
	while (s-- != 0) {
		delay_ms(1000);
	}
}
