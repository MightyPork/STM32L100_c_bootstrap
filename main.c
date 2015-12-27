#include <common.h>
#include <gpio.h>
#include <systick.h>


static void init_gpios(void)
{
	gpio_enable(GPIOA);
	gpio_enable(GPIOB);
	gpio_enable(GPIOC);

	gpio_set_mode(GPIOC, BIT8 | BIT9, MODER_OUTPUT);
}


static void init_clock(void)
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


static void init_usart(void)
{
	gpio_set_af(GPIOC, BIT10 | BIT11, AF7);

	// USART at C11, C12
	RCC_APB1ENR |= RCC_APB1ENR_USART3EN;

	// RATE 9600Bd 104.1875 (see datasheet for reference)8.6875
	// 0x00683 ... 9600
	USART3_BRR = 0x0008A;  // 115200

	// USART enable
	USART3_CR1 = USART_CR1_UE | USART_CR1_RE | USART_CR1_TE;
}


/** Called before main() */
void SystemInit(void)
{
	init_clock();
	systick_setup(16000);
	init_gpios();
	init_usart();
}



static uint32_t time = 0;

/** IRQ */
void SysTick_Handler(void)
{
	time++;
	if (time == 500) {
		time = 0;
		GPIOC_ODR ^= BIT9;
	}
}



void delay(void)
{
	for (int i = 0; i < 100000; i++) {
		__asm__("nop");
	}
}


int main(void)
{
	while (1) {
		delay();
		GPIOC_ODR ^= BIT8;
	}
}
