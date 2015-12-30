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

#define SCS_BASE             0xE000E000                 // System Control Space base
#define SCB                  (SCS_BASE + 0x0D00)       // System Control Block base
#define NVIC                 (SCS_BASE + 0x0100)       // Nested Interrupt Vector Controller base
#define OB_CTRL                   0x1FF80000                 // FLASH Option Bytes base address
#define AES_BASE                  0x50060000                 // Encryption module
#define FSMC_BASE                 0xA0000000                 // External Memory Control base
#define DBGMCU_BASE               0xE0042000                 // Debug MCU registers base address

#define INFO_BASE			(0x1ff00000U)

// ----------------------------- Peripherals ----------------------------------

// *** Peripheral bus bases ***
#define APB1_BASE                  PERIPH_BASE               // Advanced Peripheral Bus 1 base
#define APB2_BASE                 (PERIPH_BASE + 0x10000)    // Advanced Peripheral Bus 2 base
#define AHB_BASE                  (PERIPH_BASE + 0x20000)    // Advanced High-speed Bus base

// *** Peripheral Bus 1 devices ***

#define TIM2                 (APB1_BASE + 0x0000)           // Timer bases
#define TIM3                 (APB1_BASE + 0x0400)
#define TIM4                 (APB1_BASE + 0x0800)
#define TIM5                 (APB1_BASE + 0x0C00)
#define TIM6                 (APB1_BASE + 0x1000)
#define TIM7                 (APB1_BASE + 0x1400)

#define LCD                  (APB1_BASE + 0x2400)           // LCD controller base
#define RTC                  (APB1_BASE + 0x2800)           // RTC base

#define WWDG                 (APB1_BASE + 0x2C00)           // Window Watchdog base
#define IWDG                 (APB1_BASE + 0x3000)           // Independent Watchdog base

#define SPI2                 (APB1_BASE + 0x3800)           // SPI base
#define SPI3                 (APB1_BASE + 0x3C00)

#define USART2               (APB1_BASE + 0x4400)           // USART base
#define USART3               (APB1_BASE + 0x4800)

#define UART4                (APB1_BASE + 0x4C00)           // UART base (?)
#define UART5                (APB1_BASE + 0x5000)

#define I2C1                 (APB1_BASE + 0x5400)           // I2C base
#define I2C2                 (APB1_BASE + 0x5800)

#define PWR_CTRL                  (APB1_BASE + 0x7000)           // Power Control block base
#define DAC_BASE                  (APB1_BASE + 0x7400)           // D/A config base
#define COMP_BASE                 (APB1_BASE + 0x7C00)           // Analog Comparator base
#define RI_BASE                   (APB1_BASE + 0x7C04)           // Routing Interface base (analog pin connections)
#define OPAMP_BASE                (APB1_BASE + 0x7C5C)           // OpAmp config base

#define USB_BASE                  (APB1_BASE + 0x5C00)           // USB registers base

// *** Peripheral Bus 2 devices ***

#define TIM9                 (APB2_BASE + 0x0800)           // Timer base
#define TIM10                (APB2_BASE + 0x0C00)
#define TIM11                (APB2_BASE + 0x1000)

#define SYSCFG_BASE          (APB2_BASE + 0x0000)           // System config block base
#define EXTI_BASE            (APB2_BASE + 0x0400)           // External interrupt settings base

#define ADC1_BASE            (APB2_BASE + 0x2400)           // A/D 1
#define ADCC_BASE            (APB2_BASE + 0x2700)           // common A/D registers base

#define SDIO                 (APB2_BASE + 0x2C00)           // SD host
#define SPI1                 (APB2_BASE + 0x3000)           // SPI
#define USART1               (APB2_BASE + 0x3800)



// *** High Speed Bus devices ***

#define GPIO_BASE                 (AHB_BASE + 0x0000)            // GPIO block base

#define CRC_BASE                  (AHB_BASE + 0x3000)            // CRC module base
#define RCC_BASE                  (AHB_BASE + 0x3800)            // Reset and Clock Config base

#define DMA1                 (AHB_BASE + 0x6000)            // DMA control base
#define DMA2                 (AHB_BASE + 0x6400)

#define FLASH_CTRL                (AHB_BASE + 0x3C00)            // FLASH control base


/* MPU: Memory protection unit */
#define MPU_BASE                        (SCS_BASE + 0x0D90)

// ----

/* Device Electronic Signature */
#define DESIG_FLASH_SIZE_BASE		(INFO_BASE + 0x8004C)
#define DESIG_UNIQUE_ID_BASE		(INFO_BASE + 0x80050)
#define DESIG_UNIQUE_ID0		MMIO32(DESIG_UNIQUE_ID_BASE)
#define DESIG_UNIQUE_ID1		MMIO32(DESIG_UNIQUE_ID_BASE + 4)
#define DESIG_UNIQUE_ID2		MMIO32(DESIG_UNIQUE_ID_BASE + 0x14)

/* ST provided factory calibration values @ 3.0V */
//#define ST_VREFINT_CAL			MMIO16(0x1FF80078)
//#define ST_TSENSE_CAL1_30C		MMIO16(0x1FF8007A)
//#define ST_TSENSE_CAL2_110C		MMIO16(0x1FF8007E)
#define ST_VREFINT_CAL			MMIO16(0x1FF800F8)
#define ST_TSENSE_CAL1_30C		MMIO16(0x1FF800FA)
#define ST_TSENSE_CAL2_110C		MMIO16(0x1FF800FE)

// ---- ARMv7M+ only ----

#define PPBI_BASE                       (0xE0000000U)

/* STE: Software Trigger Interrupt Register */
#define STIR_BASE                       (SCS_BASE + 0x0F00)
/* ID: ID space */
#define ID_BASE                         (SCS_BASE + 0x0FD0)
/* ITR: Interrupt Type Register */
#define ITR_BASE                        (SCS_BASE + 0x0000)

/* ITM: Instrumentation Trace Macrocell */
#define ITM_BASE                        (PPBI_BASE + 0x0000)

/* DWT: Data Watchpoint and Trace unit */
#define DWT_BASE                        (PPBI_BASE + 0x1000)

/* FPB: Flash Patch and Breakpoint unit */
#define FPB_BASE                        (PPBI_BASE + 0x2000)

#define TPIU_BASE                       (PPBI_BASE + 0x40000)
