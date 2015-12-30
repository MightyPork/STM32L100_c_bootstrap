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

	gpio_set_mode(GPIOC, BIT11, MODER_INPUT);
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
	//SysTick_CSR = (SysTick_CSR & ~SysTick_CSR_CLKSOURCE) | (1 << __CTZ(SysTick_CSR_CLKSOURCE));

	patch_register(SysTick_CSR, SysTick_CSR_CLKSOURCE, 1); // 1 - core, 0 - div 8

	SysTick_RELOAD = 16000; // 1ms interrupt @ 16MHz core clock
	SysTick_CSR |= SysTick_CSR_TICKINT | SysTick_CSR_ENABLE;
}


void init_adc(void)
{
	// B1 ... AN9   Vcc o--[330R]--(B1)--[?R]--| GND
	// B0 ... AN8   fototransistor
	// B12 .. AN18  "angle" potentiometer
	// C5 ... AN15

	gpio_set_mode(GPIOB, BIT1 | BIT0 | BIT12, MODER_ANALOG);
	//gpio_set_mode(GPIOC, BIT5, MODER_ANALOG);

	// enable clock for ADC
	RCC_APB2ENR |= RCC_APB2ENR_ADC1EN;

	// 12-bit, right aligned
	ADC1_CR1 = 0;
	ADC1_CR2 = 0;

	// enable internal temperature sensor (16) & voltage reference (17)
	ADC_CCR |= ADC_CCR_TSVREFE;

	ADC1_SMPR3 = 0b100; // sample time

	// turn ADC on
	ADC1_CR2 |= ADC_CR2_ADON;
	// Wait for ADONS
	while (!(ADC1_SR & ADC_SR_ADONS));
}


void init_dac(void)
{
	RCC_APB1ENR |= RCC_APB1ENR_DACEN; // enable DAC

	gpio_set_mode(GPIOA, BIT4, MODER_ANALOG); // PA4 - DAC CH1 out

	DAC_CR |= DAC_CR_EN1; // enable first channel

	DAC_DHR12R1 = 0; // reset value
}


void init_pwm1(void)
{
	// enable clock for the timer
	RCC_APB1ENR |= RCC_APB1ENR_TIM3EN;

	// using timer 3, channel 1
	gpio_set_af(GPIOA, BIT6, AF2);

	patch_register(TIM3_CCMR1, TIM_CCMR1_OC1M, TIM_OCM_PWM1); // set PWM1 mode

	TIM3_CCMR1 |= TIM_CCMR1_OC1PE; // preload enable
	TIM3_CR1 |= TIM_CR1_ARPE; // auto reload is buffered
	TIM3_CCER |= TIM_CCER_CC1E; // enable output compare (PWM output)

	patch_register(TIM3_CR1, TIM_CR1_CMS, TIM_CMS_EDGE); // centering mode
	patch_register(TIM3_CR1, TIM_CR1_DIR, 0); // count upwards only

	// frequency set to 16 kHz

	TIM3_PSC = 0; // prescaller
	TIM3_ARR = 1000; // sets frequency
	TIM3_CCR1 = 0; // duty cycle

	// generate update event to latch the value registers
	TIM3_EGR |= TIM_EGR_UG;

	TIM3_CR1 |= TIM_CR1_CEN; // enable timer.
}












