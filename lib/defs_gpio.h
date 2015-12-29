#pragma once
#include "common.h"

// AUTHOR : Ondrej Hruska
// DATE   : 10/2015
// DESCR  : Control registers and bit masks for GPIO

enum GPIO_MODE {
	MODER_INPUT = 0,
	MODER_OUTPUT = 1,
	MODER_AF = 2,
	MODER_ANALOG = 3,
};

enum GPIO_AF {
	AF0 = 0,
	AF1 = 1,
	AF2 = 2,
	AF3 = 3,
	AF4 = 4,
	AF5 = 5,
	AF6 = 6,
	AF7 = 7,
	AF8 = 8,
	AF9 = 9,
	AF10 = 10,
	AF11 = 11,
	AF12 = 12,
	AF13 = 13,
	AF14 = 14,
	AF15 = 15,
};


// offsets
#define GPIO_MODER_offs    0x00  // GPIO pin mode register,
#define GPIO_OTYPER_offs   0x04  // GPIO output type register,
#define GPIO_OSPEEDR_offs  0x08  // GPIO output speed register,
#define GPIO_PUPDR_offs    0x0C  // GPIO pull-up/pull-down register,
#define GPIO_IDR_offs      0x10  // GPIO input data register,
#define GPIO_ODR_offs      0x14  // GPIO output data register,
#define GPIO_BSRR_offs     0x18  // GPIO bit set/reset register,
#define GPIO_LCKR_offs     0x1C  // GPIO configuration lock register,
#define GPIO_AFRL_offs     0x20  // GPIO alternate function register,
#define GPIO_AFRH_offs     0x24  // GPIO alternate function register,
#define GPIO_BRR_offs      0x28  // GPIO bit reset register,

#define GPIOA              (GPIO_BASE + 0x0000)
#define GPIOB              (GPIO_BASE + 0x0400)
#define GPIOC              (GPIO_BASE + 0x0800)
#define GPIOD              (GPIO_BASE + 0x0C00)
#define GPIOE              (GPIO_BASE + 0x1000)
#define GPIOH              (GPIO_BASE + 0x1400)
#define GPIOF              (GPIO_BASE + 0x1800)
#define GPIOG              (GPIO_BASE + 0x1C00)

#define GPIOA_MODER         MMIO32(GPIOA + 0x00)              // GPIOA pin mode register,
#define GPIOA_OTYPER        MMIO32(GPIOA + 0x04)              // GPIOA output type register,
#define GPIOA_OSPEEDR       MMIO32(GPIOA + 0x08)              // GPIOA output speed register,
#define GPIOA_PUPDR         MMIO32(GPIOA + 0x0C)              // GPIOA pull-up/pull-down register,
#define GPIOA_IDR           MMIO32(GPIOA + 0x10)              // GPIOA input data register,
#define GPIOA_ODR           MMIO32(GPIOA + 0x14)              // GPIOA output data register,
#define GPIOA_BSRR          MMIO32(GPIOA + 0x18)              // GPIOA bit set/reset register,
#define GPIOA_LCKR          MMIO32(GPIOA + 0x1C)              // GPIOA configuration lock register,
#define GPIOA_AFRL          MMIO32(GPIOA + 0x20)              // GPIOA alternate function register,
#define GPIOA_AFRH          MMIO32(GPIOA + 0x24)              // GPIOA alternate function register,
#define GPIOA_BRR           MMIO32(GPIOA + 0x28)              // GPIOA bit reset register,

#define GPIOB_MODER         MMIO32(GPIOB + 0x00)              // GPIOB pin mode register,
#define GPIOB_OTYPER        MMIO32(GPIOB + 0x04)              // GPIOB output type register,
#define GPIOB_OSPEEDR       MMIO32(GPIOB + 0x08)              // GPIOB output speed register,
#define GPIOB_PUPDR         MMIO32(GPIOB + 0x0C)              // GPIOB pull-up/pull-down register,
#define GPIOB_IDR           MMIO32(GPIOB + 0x10)              // GPIOB input data register,
#define GPIOB_ODR           MMIO32(GPIOB + 0x14)              // GPIOB output data register,
#define GPIOB_BSRR          MMIO32(GPIOB + 0x18)              // GPIOB bit set/reset register,
#define GPIOB_LCKR          MMIO32(GPIOB + 0x1C)              // GPIOB configuration lock register,
#define GPIOB_AFRL          MMIO32(GPIOB + 0x20)              // GPIOB alternate function register,
#define GPIOB_AFRH          MMIO32(GPIOB + 0x24)              // GPIOB alternate function register,
#define GPIOB_BRR           MMIO32(GPIOB + 0x28)              // GPIOB bit reset register,

#define GPIOC_MODER         MMIO32(GPIOC + 0x00)              // GPIOC pin mode register,
#define GPIOC_OTYPER        MMIO32(GPIOC + 0x04)              // GPIOC output type register,
#define GPIOC_OSPEEDR       MMIO32(GPIOC + 0x08)              // GPIOC output speed register,
#define GPIOC_PUPDR         MMIO32(GPIOC + 0x0C)              // GPIOC pull-up/pull-down register,
#define GPIOC_IDR           MMIO32(GPIOC + 0x10)              // GPIOC input data register,
#define GPIOC_ODR           MMIO32(GPIOC + 0x14)              // GPIOC output data register,
#define GPIOC_BSRR          MMIO32(GPIOC + 0x18)              // GPIOC bit set/reset register,
#define GPIOC_LCKR          MMIO32(GPIOC + 0x1C)              // GPIOC configuration lock register,
#define GPIOC_AFRL          MMIO32(GPIOC + 0x20)              // GPIOC alternate function register,
#define GPIOC_AFRH          MMIO32(GPIOC + 0x24)              // GPIOC alternate function register,
#define GPIOC_BRR           MMIO32(GPIOC + 0x28)              // GPIOC bit reset register,

#define GPIOD_MODER         MMIO32(GPIOD + 0x00)              // GPIOD pin mode register,
#define GPIOD_OTYPER        MMIO32(GPIOD + 0x04)              // GPIOD output type register,
#define GPIOD_OSPEEDR       MMIO32(GPIOD + 0x08)              // GPIOD output speed register,
#define GPIOD_PUPDR         MMIO32(GPIOD + 0x0C)              // GPIOD pull-up/pull-down register,
#define GPIOD_IDR           MMIO32(GPIOD + 0x10)              // GPIOD input data register,
#define GPIOD_ODR           MMIO32(GPIOD + 0x14)              // GPIOD output data register,
#define GPIOD_BSRR          MMIO32(GPIOD + 0x18)              // GPIOD bit set/reset register,
#define GPIOD_LCKR          MMIO32(GPIOD + 0x1C)              // GPIOD configuration lock register,
#define GPIOD_AFRL          MMIO32(GPIOD + 0x20)              // GPIOD alternate function register,
#define GPIOD_AFRH          MMIO32(GPIOD + 0x24)              // GPIOD alternate function register,
#define GPIOD_BRR           MMIO32(GPIOD + 0x28)              // GPIOD bit reset register,

#define GPIOE_MODER         MMIO32(GPIOE + 0x00)              // GPIOE pin mode register,
#define GPIOE_OTYPER        MMIO32(GPIOE + 0x04)              // GPIOE output type register,
#define GPIOE_OSPEEDR       MMIO32(GPIOE + 0x08)              // GPIOE output speed register,
#define GPIOE_PUPDR         MMIO32(GPIOE + 0x0C)              // GPIOE pull-up/pull-down register,
#define GPIOE_IDR           MMIO32(GPIOE + 0x10)              // GPIOE input data register,
#define GPIOE_ODR           MMIO32(GPIOE + 0x14)              // GPIOE output data register,
#define GPIOE_BSRR          MMIO32(GPIOE + 0x18)              // GPIOE bit set/reset register,
#define GPIOE_LCKR          MMIO32(GPIOE + 0x1C)              // GPIOE configuration lock register,
#define GPIOE_AFRL          MMIO32(GPIOE + 0x20)              // GPIOE alternate function register,
#define GPIOE_AFRH          MMIO32(GPIOE + 0x24)              // GPIOE alternate function register,
#define GPIOE_BRR           MMIO32(GPIOE + 0x28)              // GPIOE bit reset register,

#define GPIOF_MODER         MMIO32(GPIOF + 0x00)              // GPIOF pin mode register,
#define GPIOF_OTYPER        MMIO32(GPIOF + 0x04)              // GPIOF output type register,
#define GPIOF_OSPEEDR       MMIO32(GPIOF + 0x08)              // GPIOF output speed register,
#define GPIOF_PUPDR         MMIO32(GPIOF + 0x0C)              // GPIOF pull-up/pull-down register,
#define GPIOF_IDR           MMIO32(GPIOF + 0x10)              // GPIOF input data register,
#define GPIOF_ODR           MMIO32(GPIOF + 0x14)              // GPIOF output data register,
#define GPIOF_BSRR          MMIO32(GPIOF + 0x18)              // GPIOF bit set/reset register,
#define GPIOF_LCKR          MMIO32(GPIOF + 0x1C)              // GPIOF configuration lock register,
#define GPIOF_AFRL          MMIO32(GPIOF + 0x20)              // GPIOF alternate function register,
#define GPIOF_AFRH          MMIO32(GPIOF + 0x24)              // GPIOF alternate function register,
#define GPIOF_BRR           MMIO32(GPIOF + 0x28)              // GPIOF bit reset register,

#define GPIOG_MODER         MMIO32(GPIOG + 0x00)              // GPIOG pin mode register,
#define GPIOG_OTYPER        MMIO32(GPIOG + 0x04)              // GPIOG output type register,
#define GPIOG_OSPEEDR       MMIO32(GPIOG + 0x08)              // GPIOG output speed register,
#define GPIOG_PUPDR         MMIO32(GPIOG + 0x0C)              // GPIOG pull-up/pull-down register,
#define GPIOG_IDR           MMIO32(GPIOG + 0x10)              // GPIOG input data register,
#define GPIOG_ODR           MMIO32(GPIOG + 0x14)              // GPIOG output data register,
#define GPIOG_BSRR          MMIO32(GPIOG + 0x18)              // GPIOG bit set/reset register,
#define GPIOG_LCKR          MMIO32(GPIOG + 0x1C)              // GPIOG configuration lock register,
#define GPIOG_AFRL          MMIO32(GPIOG + 0x20)              // GPIOG alternate function register,
#define GPIOG_AFRH          MMIO32(GPIOG + 0x24)              // GPIOG alternate function register,
#define GPIOG_BRR           MMIO32(GPIOG + 0x28)              // GPIOG bit reset register,

#define GPIOH_MODER         MMIO32(GPIOH + 0x00)              // GPIOH pin mode register,
#define GPIOH_OTYPER        MMIO32(GPIOH + 0x04)              // GPIOH output type register,
#define GPIOH_OSPEEDR       MMIO32(GPIOH + 0x08)              // GPIOH output speed register,
#define GPIOH_PUPDR         MMIO32(GPIOH + 0x0C)              // GPIOH pull-up/pull-down register,
#define GPIOH_IDR           MMIO32(GPIOH + 0x10)              // GPIOH input data register,
#define GPIOH_ODR           MMIO32(GPIOH + 0x14)              // GPIOH output data register,
#define GPIOH_BSRR          MMIO32(GPIOH + 0x18)              // GPIOH bit set/reset register,
#define GPIOH_LCKR          MMIO32(GPIOH + 0x1C)              // GPIOH configuration lock register,
#define GPIOH_AFRL          MMIO32(GPIOH + 0x20)              // GPIOH alternate function register,
#define GPIOH_AFRH          MMIO32(GPIOH + 0x24)              // GPIOH alternate function register,
#define GPIOH_BRR           MMIO32(GPIOH + 0x28)              // GPIOH bit reset register,
