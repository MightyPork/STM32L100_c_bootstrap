#pragma once
#include "common.h"

// don't forget to implement the handler:
// void SysTick_Handler(void)


/**
 * Set up and start systick
 * @param prescaller divider (eg. for 1ms @ 16MHz: 16000)
 */
void systick_setup(uint32_t prescaller);


/** Enable (start) systick */
void systick_enable(void);


/** Disable (stop) systick */
void systick_disable(void);
