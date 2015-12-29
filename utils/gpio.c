#include "common.h"
#include "gpio.h"

static uint32_t rcc_gpio_mask(uint32_t gpio)
{
	switch (gpio) {
		case GPIOA:
			return RCC_AHBENR_GPIOAEN;
		case GPIOB:
			return RCC_AHBENR_GPIOBEN;
		case GPIOC:
			return RCC_AHBENR_GPIOCEN;
		case GPIOD:
			return RCC_AHBENR_GPIODEN;
		case GPIOE:
			return RCC_AHBENR_GPIOEEN;
		case GPIOF:
			return RCC_AHBENR_GPIOFEN;
		case GPIOG:
			return RCC_AHBENR_GPIOGEN;
		case GPIOH:
			return RCC_AHBENR_GPIOHEN;
		default:
			return 0;
	}
}


void gpio_enable(uint32_t gpio)
{
	RCC_AHBENR |= rcc_gpio_mask(gpio);
}


void gpio_disable(uint32_t gpio)
{
	RCC_AHBENR &= ~rcc_gpio_mask(gpio);
}


void gpio_set_af(uint32_t gpio, uint32_t pins, enum GPIO_AF af)
{
	gpio_enable(gpio);
	gpio_set_mode(gpio, pins, MODER_AF);

	io32_t afrl = P_REG(gpio, GPIO_AFRL_offs);
	io32_t afrh = P_REG(gpio, GPIO_AFRH_offs);

	BitFieldLoop(i, m, 16) {
		if (pins & m) {
			if (i < 8) {
				*afrl &= ~(0xF << i * 4);
				*afrl |= af << i * 4;
			} else {
				*afrh &= ~(0xF << (i - 8) * 4);
				*afrh |= af << (i - 8) * 4;
			}
		}
	};
}


void gpio_set_mode(uint32_t gpio, uint32_t pins, enum GPIO_MODE mode)
{
	io32_t moder = P_REG(gpio, GPIO_MODER_offs);

	BitFieldLoop(i, m, 16) {
		if (pins & m) {
			*moder &= ~(0b11 << i * 2);
			*moder |= mode << i * 2;
		}
	};
}
