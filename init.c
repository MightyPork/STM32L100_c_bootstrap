#include "init.h"

#include "utils/gpio.h"
#include "utils/usart.h"
#include "utils/nvic.h"


void init_gpios(void)
{
	gpio_enable(GPIOA);
	gpio_enable(GPIOB);
	gpio_enable(GPIOC);

	// LEDs
	gpio_set_mode(GPIOC, BIT8 | BIT9, MODER_OUTPUT);
}



void init_clock(void)
{
	// Flash timing - 64-bit access, pre-fetch, latency = 1
	FLASH_ACR |= FLASH_ACR_ACC64; // Cannot write both at once
	FLASH_ACR |= FLASH_ACR_PRFTEN | FLASH_ACR_LATENCY;

	// Power on HSI (runs from MSI on start)
	RCC_CR |= RCC_CR_HSION;

	// Wait for HSIRDY
	while (!(RCC_CR & RCC_CR_HSIRDY));

	// Select HSI as the core clock source
	RCC_CFGR &= ~RCC_CFGR_SW;
	RCC_CFGR |= RCC_CFGR_SW_HSI;
}



void init_usart(void)
{
	gpio_set_af(GPIOA, BIT2 | BIT3, AF7);

	// USART at A2 (tx), A3 (rx)
	RCC_APB1ENR |= RCC_APB1ENR_USART2EN;

	// RATE 9600Bd 104.1875 (see datasheet for reference)
	//USART2_BRR = 0x00683; // 9600 @ 16MHz
	USART2_BRR = 0x0008A; // 115200 @ 16MHz

	// USART enable
	USART2_CR1 = USART_CR1_UE | USART_CR1_RE | USART_CR1_TE;

	// enable interrupt on data receive
	nvic_enable_irq(NVIC_USART2_IRQ);
	USART2_CR1 |= USART_CR1_RXNEIE;
}



void init_systick(void)
{
	SysTick_CSR = (SysTick_CSR & ~SysTick_CSR_CLKSOURCE) | SysTick_CSR_CLKSOURCE_CORE;
	SysTick_RELOAD = 16000; // 1ms interrupt @ 16MHz core clock
	SysTick_CSR |= SysTick_CSR_TICKINT | SysTick_CSR_ENABLE;
}


void init_adc(void)
{
	gpio_set_mode(GPIOB, BIT12, MODER_ANALOG);

	// TODO
}


























