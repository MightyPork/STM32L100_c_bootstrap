#pragma once
#include "common.h"

// RCC registers

#define RCC_CR              MMIO32(RCC_BASE + 0x00) // RCC clock control register,
#define RCC_ICSCR           MMIO32(RCC_BASE + 0x04) // RCC Internal clock sources calibration register,
#define RCC_CFGR            MMIO32(RCC_BASE + 0x08) // RCC Clock configuration register,
#define RCC_CIR             MMIO32(RCC_BASE + 0x0C) // RCC Clock interrupt register,
#define RCC_AHBRSTR         MMIO32(RCC_BASE + 0x10) // RCC AHB peripheral reset register,
#define RCC_APB2RSTR        MMIO32(RCC_BASE + 0x14) // RCC APB2 peripheral reset register,
#define RCC_APB1RSTR        MMIO32(RCC_BASE + 0x18) // RCC APB1 peripheral reset register,
#define RCC_AHBENR          MMIO32(RCC_BASE + 0x1C) // RCC AHB peripheral clock enable register,
#define RCC_APB2ENR         MMIO32(RCC_BASE + 0x20) // RCC APB2 peripheral clock enable register,
#define RCC_APB1ENR         MMIO32(RCC_BASE + 0x24) // RCC APB1 peripheral clock enable register,
#define RCC_AHBLPENR        MMIO32(RCC_BASE + 0x28) // RCC AHB peripheral clock enable in low power mode register,
#define RCC_APB2LPENR       MMIO32(RCC_BASE + 0x2C) // RCC APB2 peripheral clock enable in low power mode register,
#define RCC_APB1LPENR       MMIO32(RCC_BASE + 0x30) // RCC APB1 peripheral clock enable in low power mode register,
#define RCC_CSR             MMIO32(RCC_BASE + 0x34) // RCC Control/status register,



//****************************************************************************
//*
//*                       BIT MASKS AND DEFINITIONS
//*
//****************************************************************************


//*******************  Bit definition for RCC_CR register  *******************
#define RCC_CR_HSION                        0x00000001        // Internal High Speed clock enable
#define RCC_CR_HSIRDY                       0x00000002        // Internal High Speed clock ready flag

#define RCC_CR_MSION                        0x00000100        // Internal Multi Speed clock enable
#define RCC_CR_MSIRDY                       0x00000200        // Internal Multi Speed clock ready flag

#define RCC_CR_HSEON                        0x00010000        // External High Speed clock enable
#define RCC_CR_HSERDY                       0x00020000        // External High Speed clock ready flag
#define RCC_CR_HSEBYP                       0x00040000        // External High Speed clock Bypass

#define RCC_CR_PLLON                        0x01000000        // PLL enable
#define RCC_CR_PLLRDY                       0x02000000        // PLL clock ready flag
#define RCC_CR_CSSON                        0x10000000        // Clock Security System enable

#define RCC_CR_RTCPRE                       0x60000000        // RTC/LCD Prescaler

// prescaler levels
#define RCC_CR_RTCPRE_DIV2                     0x00000000
#define RCC_CR_RTCPRE_DIV4                     0x20000000
#define RCC_CR_RTCPRE_DIV8                     0x40000000
#define RCC_CR_RTCPRE_DIV16                    0x60000000

//*******************  Bit definition for RCC_ICSCR register  ****************
#define RCC_ICSCR_HSICAL                    0x000000FF        // Internal High Speed clock Calibration
#define RCC_ICSCR_HSITRIM                   0x00001F00        // Internal High Speed clock trimming

#define RCC_ICSCR_MSIRANGE                  0x0000E000        // Internal Multi Speed clock Range
#define RCC_ICSCR_MSIRANGE_0                0x00000000        // Internal Multi Speed clock Range 65.536 KHz
#define RCC_ICSCR_MSIRANGE_1                0x00002000        // Internal Multi Speed clock Range 131.072 KHz
#define RCC_ICSCR_MSIRANGE_2                0x00004000        // Internal Multi Speed clock Range 262.144 KHz
#define RCC_ICSCR_MSIRANGE_3                0x00006000        // Internal Multi Speed clock Range 524.288 KHz
#define RCC_ICSCR_MSIRANGE_4                0x00008000        // Internal Multi Speed clock Range 1.048 MHz
#define RCC_ICSCR_MSIRANGE_5                0x0000A000        // Internal Multi Speed clock Range 2.097 MHz
#define RCC_ICSCR_MSIRANGE_6                0x0000C000        // Internal Multi Speed clock Range 4.194 MHz
#define RCC_ICSCR_MSICAL                    0x00FF0000        // Internal Multi Speed clock Calibration
#define RCC_ICSCR_MSITRIM                   0xFF000000        // Internal Multi Speed clock trimming

//*******************  Bit definition for RCC_CFGR register  *****************
#define RCC_CFGR_SW                         0x00000003        // SW[1:0] bits (System clock Switch)

// SW configuration
#define RCC_CFGR_SW_MSI                     0x00000000        // MSI selected as system clock
#define RCC_CFGR_SW_HSI                     0x00000001        // HSI selected as system clock
#define RCC_CFGR_SW_HSE                     0x00000002        // HSE selected as system clock
#define RCC_CFGR_SW_PLL                     0x00000003        // PLL selected as system clock

#define RCC_CFGR_SWS                        0x0000000C        // SWS[1:0] bits (System Clock Switch Status)

// SWS configuration
#define RCC_CFGR_SWS_MSI                    0x00000000        // MSI oscillator used as system clock
#define RCC_CFGR_SWS_HSI                    0x00000004        // HSI oscillator used as system clock
#define RCC_CFGR_SWS_HSE                    0x00000008        // HSE oscillator used as system clock
#define RCC_CFGR_SWS_PLL                    0x0000000C        // PLL used as system clock

#define RCC_CFGR_HPRE                       0x000000F0        // HPRE[3:0] bits (AHB prescaler)

// HPRE configuration
#define RCC_CFGR_HPRE_DIV1                  0x00000000        // SYSCLK not divided
#define RCC_CFGR_HPRE_DIV2                  0x00000080        // SYSCLK divided by 2
#define RCC_CFGR_HPRE_DIV4                  0x00000090        // SYSCLK divided by 4
#define RCC_CFGR_HPRE_DIV8                  0x000000A0        // SYSCLK divided by 8
#define RCC_CFGR_HPRE_DIV16                 0x000000B0        // SYSCLK divided by 16
#define RCC_CFGR_HPRE_DIV64                 0x000000C0        // SYSCLK divided by 64
#define RCC_CFGR_HPRE_DIV128                0x000000D0        // SYSCLK divided by 128
#define RCC_CFGR_HPRE_DIV256                0x000000E0        // SYSCLK divided by 256
#define RCC_CFGR_HPRE_DIV512                0x000000F0        // SYSCLK divided by 512

#define RCC_CFGR_PPRE1                      0x00000700        // PRE1[2:0] bits (APB1 prescaler)

// PPRE1 configuration
#define RCC_CFGR_PPRE1_DIV1                 0x00000000        // HCLK not divided
#define RCC_CFGR_PPRE1_DIV2                 0x00000400        // HCLK divided by 2
#define RCC_CFGR_PPRE1_DIV4                 0x00000500        // HCLK divided by 4
#define RCC_CFGR_PPRE1_DIV8                 0x00000600        // HCLK divided by 8
#define RCC_CFGR_PPRE1_DIV16                0x00000700        // HCLK divided by 16

#define RCC_CFGR_PPRE2                      0x00003800        // PRE2[2:0] bits (APB2 prescaler)

// PPRE2 configuration
#define RCC_CFGR_PPRE2_DIV1                 0x00000000        // HCLK not divided
#define RCC_CFGR_PPRE2_DIV2                 0x00002000        // HCLK divided by 2
#define RCC_CFGR_PPRE2_DIV4                 0x00002800        // HCLK divided by 4
#define RCC_CFGR_PPRE2_DIV8                 0x00003000        // HCLK divided by 8
#define RCC_CFGR_PPRE2_DIV16                0x00003800        // HCLK divided by 16

// PLL entry clock source
#define RCC_CFGR_PLLSRC                     0x00010000        // PLL entry clock source

#define RCC_CFGR_PLLSRC_HSI                 0x00000000        // HSI as PLL entry clock source
#define RCC_CFGR_PLLSRC_HSE                 0x00010000        // HSE as PLL entry clock source


#define RCC_CFGR_PLLMUL                     0x003C0000        // PLLMUL[3:0] bits (PLL multiplication factor)

// PLLMUL configuration
#define RCC_CFGR_PLLMUL3                    0x00000000        // PLL input clock * 3
#define RCC_CFGR_PLLMUL4                    0x00040000        // PLL input clock * 4
#define RCC_CFGR_PLLMUL6                    0x00080000        // PLL input clock * 6
#define RCC_CFGR_PLLMUL8                    0x000C0000        // PLL input clock * 8
#define RCC_CFGR_PLLMUL12                   0x00100000        // PLL input clock * 12
#define RCC_CFGR_PLLMUL16                   0x00140000        // PLL input clock * 16
#define RCC_CFGR_PLLMUL24                   0x00180000        // PLL input clock * 24
#define RCC_CFGR_PLLMUL32                   0x001C0000        // PLL input clock * 32
#define RCC_CFGR_PLLMUL48                   0x00200000        // PLL input clock * 48

// PLLDIV configuration
#define RCC_CFGR_PLLDIV                     0x00C00000        // PLLDIV[1:0] bits (PLL Output Division)

// PLLDIV configuration
#define RCC_CFGR_PLLDIV1                    0x00000000        // PLL clock output = CKVCO / 1
#define RCC_CFGR_PLLDIV2                    0x00400000        // PLL clock output = CKVCO / 2
#define RCC_CFGR_PLLDIV3                    0x00800000        // PLL clock output = CKVCO / 3
#define RCC_CFGR_PLLDIV4                    0x00C00000        // PLL clock output = CKVCO / 4


#define RCC_CFGR_MCOSEL                     0x07000000        // MCO[2:0] bits (Microcontroller Clock Output)

// MCO configuration
#define RCC_CFGR_MCO_NOCLOCK                0x00000000        // No clock
#define RCC_CFGR_MCO_SYSCLK                 0x01000000        // System clock selected
#define RCC_CFGR_MCO_HSI                    0x02000000        // Internal 16 MHz RC oscillator clock selected
#define RCC_CFGR_MCO_MSI                    0x03000000        // Internal Medium Speed RC oscillator clock selected
#define RCC_CFGR_MCO_HSE                    0x04000000        // External 1-25 MHz oscillator clock selected
#define RCC_CFGR_MCO_PLL                    0x05000000        // PLL clock divided
#define RCC_CFGR_MCO_LSI                    0x06000000        // LSI selected
#define RCC_CFGR_MCO_LSE                    0x07000000        // LSE selected

#define RCC_CFGR_MCOPRE                     0x70000000        // MCOPRE[2:0] bits (Microcontroller Clock Output Prescaler)

// MCO Prescaler configuration
#define RCC_CFGR_MCO_DIV1                   0x00000000        // MCO Clock divided by 1
#define RCC_CFGR_MCO_DIV2                   0x10000000        // MCO Clock divided by 2
#define RCC_CFGR_MCO_DIV4                   0x20000000        // MCO Clock divided by 4
#define RCC_CFGR_MCO_DIV8                   0x30000000        // MCO Clock divided by 8
#define RCC_CFGR_MCO_DIV16                  0x40000000        // MCO Clock divided by 16

// ******************  Bit definition for RCC_CIR register  *******************
#define RCC_CIR_LSIRDYF                     0x00000001        // LSI Ready Interrupt flag
#define RCC_CIR_LSERDYF                     0x00000002        // LSE Ready Interrupt flag
#define RCC_CIR_HSIRDYF                     0x00000004        // HSI Ready Interrupt flag
#define RCC_CIR_HSERDYF                     0x00000008        // HSE Ready Interrupt flag
#define RCC_CIR_PLLRDYF                     0x00000010        // PLL Ready Interrupt flag
#define RCC_CIR_MSIRDYF                     0x00000020        // MSI Ready Interrupt flag
#define RCC_CIR_LSECSS                      0x00000040        // LSE CSS Interrupt flag
#define RCC_CIR_CSSF                        0x00000080        // Clock Security System Interrupt flag

#define RCC_CIR_LSIRDYIE                    0x00000100        // LSI Ready Interrupt Enable
#define RCC_CIR_LSERDYIE                    0x00000200        // LSE Ready Interrupt Enable
#define RCC_CIR_HSIRDYIE                    0x00000400        // HSI Ready Interrupt Enable
#define RCC_CIR_HSERDYIE                    0x00000800        // HSE Ready Interrupt Enable
#define RCC_CIR_PLLRDYIE                    0x00001000        // PLL Ready Interrupt Enable
#define RCC_CIR_MSIRDYIE                    0x00002000        // MSI Ready Interrupt Enable
#define RCC_CIR_LSECSSIE                    0x00004000        // LSE CSS Interrupt Enable

#define RCC_CIR_LSIRDYC                     0x00010000        // LSI Ready Interrupt Clear
#define RCC_CIR_LSERDYC                     0x00020000        // LSE Ready Interrupt Clear
#define RCC_CIR_HSIRDYC                     0x00040000        // HSI Ready Interrupt Clear
#define RCC_CIR_HSERDYC                     0x00080000        // HSE Ready Interrupt Clear
#define RCC_CIR_PLLRDYC                     0x00100000        // PLL Ready Interrupt Clear
#define RCC_CIR_MSIRDYC                     0x00200000        // MSI Ready Interrupt Clear
#define RCC_CIR_LSECSSC                     0x00400000        // LSE CSS Interrupt Clear
#define RCC_CIR_CSSC                        0x00800000        // Clock Security System Interrupt Clear


//****************  Bit definition for RCC_AHBRSTR register  *****************
#define RCC_AHBRSTR_GPIOARST                0x00000001        // GPIO port A reset
#define RCC_AHBRSTR_GPIOBRST                0x00000002        // GPIO port B reset
#define RCC_AHBRSTR_GPIOCRST                0x00000004        // GPIO port C reset
#define RCC_AHBRSTR_GPIODRST                0x00000008        // GPIO port D reset
#define RCC_AHBRSTR_GPIOERST                0x00000010        // GPIO port E reset
#define RCC_AHBRSTR_GPIOHRST                0x00000020        // GPIO port H reset
#define RCC_AHBRSTR_GPIOFRST                0x00000040        // GPIO port F reset
#define RCC_AHBRSTR_GPIOGRST                0x00000080        // GPIO port G reset
#define RCC_AHBRSTR_CRCRST                  0x00001000        // CRC reset
#define RCC_AHBRSTR_FLITFRST                0x00008000        // FLITF reset
#define RCC_AHBRSTR_DMA1RST                 0x01000000        // DMA1 reset
#define RCC_AHBRSTR_DMA2RST                 0x02000000        // DMA2 reset
#define RCC_AHBRSTR_AESRST                  0x08000000        // AES reset
#define RCC_AHBRSTR_FSMCRST                 0x40000000        // FSMC reset

//****************  Bit definition for RCC_APB2RSTR register  ****************
#define RCC_APB2RSTR_SYSCFGRST              0x00000001        // System Configuration SYSCFG reset
#define RCC_APB2RSTR_TIM9RST                0x00000004        // TIM9 reset
#define RCC_APB2RSTR_TIM10RST               0x00000008        // TIM10 reset
#define RCC_APB2RSTR_TIM11RST               0x00000010        // TIM11 reset
#define RCC_APB2RSTR_ADC1RST                0x00000200        // ADC1 reset
#define RCC_APB2RSTR_SDIORST                0x00000800        // SDIO reset
#define RCC_APB2RSTR_SPI1RST                0x00001000        // SPI1 reset
#define RCC_APB2RSTR_USART1RST              0x00004000        // USART1 reset

//****************  Bit definition for RCC_APB1RSTR register  ****************
#define RCC_APB1RSTR_TIM2RST                0x00000001        // Timer 2 reset
#define RCC_APB1RSTR_TIM3RST                0x00000002        // Timer 3 reset
#define RCC_APB1RSTR_TIM4RST                0x00000004        // Timer 4 reset
#define RCC_APB1RSTR_TIM5RST                0x00000008        // Timer 5 reset
#define RCC_APB1RSTR_TIM6RST                0x00000010        // Timer 6 reset
#define RCC_APB1RSTR_TIM7RST                0x00000020        // Timer 7 reset
#define RCC_APB1RSTR_LCDRST                 0x00000200        // LCD reset
#define RCC_APB1RSTR_WWDGRST                0x00000800        // Window Watchdog reset
#define RCC_APB1RSTR_SPI2RST                0x00004000        // SPI 2 reset
#define RCC_APB1RSTR_SPI3RST                0x00008000        // SPI 3 reset
#define RCC_APB1RSTR_USART2RST              0x00020000        // USART 2 reset
#define RCC_APB1RSTR_USART3RST              0x00040000        // USART 3 reset
#define RCC_APB1RSTR_UART4RST               0x00080000        // UART 4 reset
#define RCC_APB1RSTR_UART5RST               0x00100000        // UART 5 reset
#define RCC_APB1RSTR_I2C1RST                0x00200000        // I2C 1 reset
#define RCC_APB1RSTR_I2C2RST                0x00400000        // I2C 2 reset
#define RCC_APB1RSTR_USBRST                 0x00800000        // USB reset
#define RCC_APB1RSTR_PWRRST                 0x10000000        // Power interface reset
#define RCC_APB1RSTR_DACRST                 0x20000000        // DAC interface reset
#define RCC_APB1RSTR_COMPRST                0x80000000        // Comparator interface reset

//*****************  Bit definition for RCC_AHBENR register  *****************
#define RCC_AHBENR_GPIOAEN                  0x00000001        // GPIO port A clock enable
#define RCC_AHBENR_GPIOBEN                  0x00000002        // GPIO port B clock enable
#define RCC_AHBENR_GPIOCEN                  0x00000004        // GPIO port C clock enable
#define RCC_AHBENR_GPIODEN                  0x00000008        // GPIO port D clock enable
#define RCC_AHBENR_GPIOEEN                  0x00000010        // GPIO port E clock enable
#define RCC_AHBENR_GPIOHEN                  0x00000020        // GPIO port H clock enable
#define RCC_AHBENR_GPIOFEN                  0x00000040        // GPIO port F clock enable
#define RCC_AHBENR_GPIOGEN                  0x00000080        // GPIO port G clock enable
#define RCC_AHBENR_CRCEN                    0x00001000        // CRC clock enable
#define RCC_AHBENR_FLITFEN                  0x00008000        // FLITF clock enable (has effect only when the Flash memory is in power down mode)
#define RCC_AHBENR_DMA1EN                   0x01000000        // DMA1 clock enable
#define RCC_AHBENR_DMA2EN                   0x02000000        // DMA2 clock enable
#define RCC_AHBENR_AESEN                    0x08000000        // AES clock enable
#define RCC_AHBENR_FSMCEN                   0x40000000        // FSMC clock enable


//*****************  Bit definition for RCC_APB2ENR register  ****************
#define RCC_APB2ENR_SYSCFGEN                0x00000001         // System Configuration SYSCFG clock enable
#define RCC_APB2ENR_TIM9EN                  0x00000004         // TIM9 interface clock enable
#define RCC_APB2ENR_TIM10EN                 0x00000008         // TIM10 interface clock enable
#define RCC_APB2ENR_TIM11EN                 0x00000010         // TIM11 Timer clock enable
#define RCC_APB2ENR_ADC1EN                  0x00000200         // ADC1 clock enable
#define RCC_APB2ENR_SDIOEN                  0x00000800         // SDIO clock enable
#define RCC_APB2ENR_SPI1EN                  0x00001000         // SPI1 clock enable
#define RCC_APB2ENR_USART1EN                0x00004000         // USART1 clock enable


//****************  Bit definition for RCC_APB1ENR register  *****************
#define RCC_APB1ENR_TIM2EN                  0x00000001        // Timer 2 clock enabled
#define RCC_APB1ENR_TIM3EN                  0x00000002        // Timer 3 clock enable
#define RCC_APB1ENR_TIM4EN                  0x00000004        // Timer 4 clock enable
#define RCC_APB1ENR_TIM5EN                  0x00000008        // Timer 5 clock enable
#define RCC_APB1ENR_TIM6EN                  0x00000010        // Timer 6 clock enable
#define RCC_APB1ENR_TIM7EN                  0x00000020        // Timer 7 clock enable
#define RCC_APB1ENR_LCDEN                   0x00000200        // LCD clock enable
#define RCC_APB1ENR_WWDGEN                  0x00000800        // Window Watchdog clock enable
#define RCC_APB1ENR_SPI2EN                  0x00004000        // SPI 2 clock enable
#define RCC_APB1ENR_SPI3EN                  0x00008000        // SPI 3 clock enable
#define RCC_APB1ENR_USART2EN                0x00020000        // USART 2 clock enable
#define RCC_APB1ENR_USART3EN                0x00040000        // USART 3 clock enable
#define RCC_APB1ENR_UART4EN                 0x00080000        // UART 4 clock enable
#define RCC_APB1ENR_UART5EN                 0x00100000        // UART 5 clock enable
#define RCC_APB1ENR_I2C1EN                  0x00200000        // I2C 1 clock enable
#define RCC_APB1ENR_I2C2EN                  0x00400000        // I2C 2 clock enable
#define RCC_APB1ENR_USBEN                   0x00800000        // USB clock enable
#define RCC_APB1ENR_PWREN                   0x10000000        // Power interface clock enable
#define RCC_APB1ENR_DACEN                   0x20000000        // DAC interface clock enable
#define RCC_APB1ENR_COMPEN                  0x80000000        // Comparator interface clock enable

//*****************  Bit definition for RCC_AHBLPENR register  ***************
#define RCC_AHBLPENR_GPIOALPEN              0x00000001        // GPIO port A clock enabled in sleep mode
#define RCC_AHBLPENR_GPIOBLPEN              0x00000002        // GPIO port B clock enabled in sleep mode
#define RCC_AHBLPENR_GPIOCLPEN              0x00000004        // GPIO port C clock enabled in sleep mode
#define RCC_AHBLPENR_GPIODLPEN              0x00000008        // GPIO port D clock enabled in sleep mode
#define RCC_AHBLPENR_GPIOELPEN              0x00000010        // GPIO port E clock enabled in sleep mode
#define RCC_AHBLPENR_GPIOHLPEN              0x00000020        // GPIO port H clock enabled in sleep mode
#define RCC_AHBLPENR_GPIOFLPEN              0x00000040        // GPIO port F clock enabled in sleep mode
#define RCC_AHBLPENR_GPIOGLPEN              0x00000080        // GPIO port G clock enabled in sleep mode
#define RCC_AHBLPENR_CRCLPEN                0x00001000        // CRC clock enabled in sleep mode
#define RCC_AHBLPENR_FLITFLPEN              0x00008000        // Flash Interface clock enabled in sleep mode (has effect only when the Flash memory is in power down mode)
#define RCC_AHBLPENR_SRAMLPEN               0x00010000        // SRAM clock enabled in sleep mode
#define RCC_AHBLPENR_DMA1LPEN               0x01000000        // DMA1 clock enabled in sleep mode
#define RCC_AHBLPENR_DMA2LPEN               0x02000000        // DMA2 clock enabled in sleep mode
#define RCC_AHBLPENR_AESLPEN                0x08000000        // AES clock enabled in sleep mode
#define RCC_AHBLPENR_FSMCLPEN               0x40000000        // FSMC clock enabled in sleep mode

//*****************  Bit definition for RCC_APB2LPENR register  **************
#define RCC_APB2LPENR_SYSCFGLPEN            0x00000001         // System Configuration SYSCFG clock enabled in sleep mode
#define RCC_APB2LPENR_TIM9LPEN              0x00000004         // TIM9 interface clock enabled in sleep mode
#define RCC_APB2LPENR_TIM10LPEN             0x00000008         // TIM10 interface clock enabled in sleep mode
#define RCC_APB2LPENR_TIM11LPEN             0x00000010         // TIM11 Timer clock enabled in sleep mode
#define RCC_APB2LPENR_ADC1LPEN              0x00000200         // ADC1 clock enabled in sleep mode
#define RCC_APB2LPENR_SDIOLPEN              0x00000800         // SDIO clock enabled in sleep mode
#define RCC_APB2LPENR_SPI1LPEN              0x00001000         // SPI1 clock enabled in sleep mode
#define RCC_APB2LPENR_USART1LPEN            0x00004000         // USART1 clock enabled in sleep mode

//****************  Bit definition for RCC_APB1LPENR register  ***************
#define RCC_APB1LPENR_TIM2LPEN              0x00000001        // Timer 2 clock enabled in sleep mode
#define RCC_APB1LPENR_TIM3LPEN              0x00000002        // Timer 3 clock enabled in sleep mode
#define RCC_APB1LPENR_TIM4LPEN              0x00000004        // Timer 4 clock enabled in sleep mode
#define RCC_APB1LPENR_TIM5LPEN              0x00000008        // Timer 5 clock enabled in sleep mode
#define RCC_APB1LPENR_TIM6LPEN              0x00000010        // Timer 6 clock enabled in sleep mode
#define RCC_APB1LPENR_TIM7LPEN              0x00000020        // Timer 7 clock enabled in sleep mode
#define RCC_APB1LPENR_LCDLPEN               0x00000200        // LCD clock enabled in sleep mode
#define RCC_APB1LPENR_WWDGLPEN              0x00000800        // Window Watchdog clock enabled in sleep mode
#define RCC_APB1LPENR_SPI2LPEN              0x00004000        // SPI 2 clock enabled in sleep mode
#define RCC_APB1LPENR_SPI3LPEN              0x00008000        // SPI 3 clock enabled in sleep mode
#define RCC_APB1LPENR_USART2LPEN            0x00020000        // USART 2 clock enabled in sleep mode
#define RCC_APB1LPENR_USART3LPEN            0x00040000        // USART 3 clock enabled in sleep mode
#define RCC_APB1LPENR_UART4LPEN             0x00080000        // UART 4 clock enabled in sleep mode
#define RCC_APB1LPENR_UART5LPEN             0x00100000        // UART 5 clock enabled in sleep mode
#define RCC_APB1LPENR_I2C1LPEN              0x00200000        // I2C 1 clock enabled in sleep mode
#define RCC_APB1LPENR_I2C2LPEN              0x00400000        // I2C 2 clock enabled in sleep mode
#define RCC_APB1LPENR_USBLPEN               0x00800000        // USB clock enabled in sleep mode
#define RCC_APB1LPENR_PWRLPEN               0x10000000        // Power interface clock enabled in sleep mode
#define RCC_APB1LPENR_DACLPEN               0x20000000        // DAC interface clock enabled in sleep mode
#define RCC_APB1LPENR_COMPLPEN              0x80000000        // Comparator interface clock enabled in sleep mode

//******************  Bit definition for RCC_CSR register  *******************
#define RCC_CSR_LSION                      0x00000001        // Internal Low Speed oscillator enable
#define RCC_CSR_LSIRDY                     0x00000002        // Internal Low Speed oscillator Ready

#define RCC_CSR_LSEON                      0x00000100        // External Low Speed oscillator enable
#define RCC_CSR_LSERDY                     0x00000200        // External Low Speed oscillator Ready
#define RCC_CSR_LSEBYP                     0x00000400        // External Low Speed oscillator Bypass
#define RCC_CSR_LSECSSON                   0x00000800        // External Low Speed oscillator CSS Enable
#define RCC_CSR_LSECSSD                    0x00001000        // External Low Speed oscillator CSS Detected

#define RCC_CSR_RTCSEL                     0x00030000        // RTCSEL[1:0] bits (RTC clock source selection)
#define RCC_CSR_RTCSEL_0                   0x00010000        // Bit 0
#define RCC_CSR_RTCSEL_1                   0x00020000        // Bit 1

// RTC congiguration
#define RCC_CSR_RTCSEL_NOCLOCK             0x00000000        // No clock
#define RCC_CSR_RTCSEL_LSE                 0x00010000        // LSE oscillator clock used as RTC clock
#define RCC_CSR_RTCSEL_LSI                 0x00020000        // LSI oscillator clock used as RTC clock
#define RCC_CSR_RTCSEL_HSE                 0x00030000        // HSE oscillator clock divided by 2, 4, 8 or 16 by RTCPRE used as RTC clock

#define RCC_CSR_RTCEN                      0x00400000        // RTC clock enable
#define RCC_CSR_RTCRST                     0x00800000        // RTC reset

#define RCC_CSR_RMVF                       0x01000000        // Remove reset flag
#define RCC_CSR_OBLRSTF                    0x02000000        // Option Bytes Loader reset flag
#define RCC_CSR_PINRSTF                    0x04000000        // PIN reset flag
#define RCC_CSR_PORRSTF                    0x08000000        // POR/PDR reset flag
#define RCC_CSR_SFTRSTF                    0x10000000        // Software Reset flag
#define RCC_CSR_IWDGRSTF                   0x20000000        // Independent Watchdog reset flag
#define RCC_CSR_WWDGRSTF                   0x40000000        // Window watchdog reset flag
#define RCC_CSR_LPWRRSTF                   0x80000000        // Low-Power reset flag
