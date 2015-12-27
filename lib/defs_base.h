#pragma once

#include "common.h"

// AUTHOR : Ondrej Hruska
// DATE   : 12/2015
// DESCR  : Base library file. This file must be included before any other library
//          files. This file defines memory map and base addresses of peripherals.


#define FLASH_BASE            0x08000000                 // FLASH base address in the alias region
#define SRAM_BASE             0x20000000                 // SRAM base address in the alias region
#define PERIPH_BASE           0x40000000                 // Peripheral base address in the alias region

#define SRAM_BB_BASE          (SRAM_BASE   + 0x02000000) // SRAM base address in the bit-band region
#define PERIPH_BB_BASE        (PERIPH_BASE + 0x02000000) // Peripheral base address in the bit-band region


// ------------------------- System Config Blocks -----------------------------

#define _SCS_BASE             0xE000E000                 // System Control Space base
#define _SCB                  (_SCS_BASE + 0x0D00)       // System Control Block base
#define _NVIC                 (_SCS_BASE + 0x0100)       // Nested Interrupt Vector Controller base
#define _OB                   0x1FF80000                 // FLASH Option Bytes base address
#define _AES                  0x50060000                 // Encryption module
#define _FSMC                 0xA0000000                 // External Memory Control base
#define _DBGMCU               0xE0042000                 // Debug MCU registers base address


// ----------------------------- Peripherals ----------------------------------

// *** Peripheral bus bases ***
#define _APB1                  PERIPH_BASE               // Advanced Peripheral Bus 1 base
#define _APB2                 (PERIPH_BASE + 0x10000)    // Advanced Peripheral Bus 2 base
#define _AHB                  (PERIPH_BASE + 0x20000)    // Advanced High-speed Bus base

// *** Peripheral Bus 1 devices ***

#define _TIM2                 (_APB1 + 0x0000)           // Timer bases
#define _TIM3                 (_APB1 + 0x0400)
#define _TIM4                 (_APB1 + 0x0800)
#define _TIM5                 (_APB1 + 0x0C00)
#define _TIM6                 (_APB1 + 0x1000)
#define _TIM7                 (_APB1 + 0x1400)

#define _LCD                  (_APB1 + 0x2400)           // LCD controller base
#define _RTC                  (_APB1 + 0x2800)           // RTC base

#define _WWDG                 (_APB1 + 0x2C00)           // Window Watchdog base
#define _IWDG                 (_APB1 + 0x3000)           // Independent Watchdog base

#define _SPI2                 (_APB1 + 0x3800)           // SPI base
#define _SPI3                 (_APB1 + 0x3C00)

#define _USART2               (_APB1 + 0x4400)           // USART base
#define _USART3               (_APB1 + 0x4800)

#define _UART4                (_APB1 + 0x4C00)           // UART base (?)
#define _UART5                (_APB1 + 0x5000)

#define _I2C1                 (_APB1 + 0x5400)           // I2C base
#define _I2C2                 (_APB1 + 0x5800)

#define _PWR                  (_APB1 + 0x7000)           // Power Control block base
#define _DAC                  (_APB1 + 0x7400)           // D/A config base
#define _COMP                 (_APB1 + 0x7C00)           // Analog Comparator base
#define _RI                   (_APB1 + 0x7C04)           // Routing Interface base (analog pin connections)
#define _OPAMP                (_APB1 + 0x7C5C)           // OpAmp config base

#define _USB                  (_APB1 + 0x5C00)           // USB registers base

// *** Peripheral Bus 2 devices ***

#define _TIM9                 (_APB2 + 0x0800)           // Timer base
#define _TIM10                (_APB2 + 0x0C00)
#define _TIM11                (_APB2 + 0x1000)

#define _SYSCFG               (_APB2 + 0x0000)           // System config block base
#define _EXTI                 (_APB2 + 0x0400)           // External interrupt settings base

#define _ADC1                 (_APB2 + 0x2400)           // A/D 1
#define _ADCC                 (_APB2 + 0x2700)           // common A/D registers base

#define _SDIO                 (_APB2 + 0x2C00)           // SD host
#define _SPI1                 (_APB2 + 0x3000)           // SPI
#define _USART1               (_APB2 + 0x3800)



// *** High Speed Bus devices ***

#define _GPIO                 (_AHB + 0x0000)            // GPIO block base

#define _CRC                  (_AHB + 0x3000)            // CRC module base
#define _RCC                  (_AHB + 0x3800)            // Reset and Clock Config base

#define _DMA1                 (_AHB + 0x6000)            // DMA control base
#define _DMA2                 (_AHB + 0x6400)

#define _FLASH                (_AHB + 0x3C00)            // FLASH control base
