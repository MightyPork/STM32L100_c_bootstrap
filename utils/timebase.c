#include "timebase.h"

volatile uint32_t TIME_MS;



// --- time scheduler ---
#define PERIODIC_TASK_COUNT 5

typedef struct {
	/** User callback */
	void (*callback)(void);
	/** Callback interval */
	uint32_t interval_ms;
	/** Counter, when reaches interval_ms, is cleared and callback is called. */
	uint32_t countup;
} periodic_task_t;

static int periodic_task_n = 0;
static periodic_task_t periodic_tasks[PERIODIC_TASK_COUNT];



// --- future calls ---
#define FUTURE_TASK_COUNT 5
typedef struct {
	/** 1 for active tasks */
	bool active;
	/** User callback */
	void (*callback)(void);
	/** Counter, when reaches 0ms, callback is called and the task is removed */
	uint32_t countdown_ms;
} future_task_t;

static future_task_t future_tasks[FUTURE_TASK_COUNT];



bool register_periodic_task(void (*callback)(void), uint32_t interval_ms)
{
	if (periodic_task_n >= PERIODIC_TASK_COUNT) return false;

	// add the task
	periodic_task_t *task = &periodic_tasks[periodic_task_n++];
	task->callback = callback;
	task->countup = 0;
	task->interval_ms = interval_ms;

	return true;
}



bool schedule_task(void (*callback)(void), uint32_t delay_ms)
{
	for (int i = 0; i < FUTURE_TASK_COUNT; i++) {
		future_task_t *task = &future_tasks[i];
		if (task->active) continue;

		task->callback = callback;
		task->countdown_ms = delay_ms;
		task->active = true;
	}

	return false;
}



/** IRQ */
void SysTick_Handler(void)
{
	TIME_MS++;

	// run scheduled tasks
	for (int i = 0; i < periodic_task_n; i++) {
		periodic_task_t *task = &periodic_tasks[i];
		if (task->countup++ >= task->interval_ms) {
			task->callback();
			task->countup = 0;
		}
	}

	// run future tasks
	for (int i = 0; i < FUTURE_TASK_COUNT; i++) {
		future_task_t *task = &future_tasks[i];
		if (!task->active) continue;

		if (task->countdown_ms-- == 0) {
			task->callback();
			task->active = 0;
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
