#include "debounce.h"
#include "timebase.h"

static bool task_registered = false;
void debo_task(void);

// ms debounce time
#define DEBO_TIME 20
#define DEBO_PIN_COUNT 10

typedef struct {
	uint32_t gpio;
	uint32_t bit_n;
	void (*falling_cb)(void);
	void (*rising_cb)(void);
	uint32_t counter_0;
	uint32_t counter_1;
	bool status;
} debo_entry_t;

int debo_pin_n = 0;
debo_entry_t debo_pins[DEBO_PIN_COUNT];



bool register_debounced_pin(uint32_t gpio, uint8_t n, void (*rising_cb)(void), void (*falling_cb)(void))
{
	if (!task_registered) {
		register_periodic_task(debo_task, 1);
	}

	if (debo_pin_n >= DEBO_PIN_COUNT) return false;

	// add the task
	debo_entry_t *pin = &debo_pins[debo_pin_n++];
	pin->bit_n = n;
	pin->gpio = gpio;
	pin->falling_cb = falling_cb;
	pin->rising_cb = rising_cb;
	pin->counter_0 = 0;
	pin->counter_1 = 0;

	io32_t IDR = P_REG(pin->gpio, GPIO_IDR_offs);
	pin->status = *IDR & BIT(pin->bit_n);

	return true;
}



void debo_task(void)
{
	io32_t IDR;
	bool status;

	for (int i = 0; i < debo_pin_n; i++) {
		debo_entry_t *pin = &debo_pins[i];

		IDR = P_REG(pin->gpio, GPIO_IDR_offs);

		status = *IDR & BIT(pin->bit_n);
		if (pin->status != status) {
			if (status == 0) {
				// falling

				if (pin->counter_0++ == DEBO_TIME) {
					pin->status = 0;

					if (pin->falling_cb != NULL) {
						pin->falling_cb();
					}
				}
			} else {
				// rising

				if (pin->counter_1++ == DEBO_TIME) {
					pin->status = 1;

					if (pin->rising_cb != NULL) {
						pin->rising_cb();
					}
				}
			}
		} else {
			// rewind counters
			pin->counter_0 = 0;
			pin->counter_1 = 0;
		}
	}
}
