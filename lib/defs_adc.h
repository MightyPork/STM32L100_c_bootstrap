#pragma once
#include "common.h"

// AUTHOR : Ondrej Hruska
// DATE   : 12/2015
// DESCR  : Control registers and bit masks for ADC


//****************************************************************************
//*
//*                               REGISTERS
//*
//****************************************************************************


// ADC common config

#define ADC_CSR         MMIO32(ADCC_BASE + 0x000) // ADC common status register,
#define ADC_CCR         MMIO32(ADCC_BASE + 0x004) // ADC common control register,

// ADC1

// internal channels
#define ADC_CH_TEMP	16
#define ADC_CH_VREF	17

#define ADC1_SR          MMIO32(ADC1_BASE + 0x00) // ADC status register,
#define ADC1_CR1         MMIO32(ADC1_BASE + 0x04) // ADC control register 1,
#define ADC1_CR2         MMIO32(ADC1_BASE + 0x08) // ADC control register 2,
#define ADC1_SMPR1       MMIO32(ADC1_BASE + 0x0C) // ADC sample time register 1,
#define ADC1_SMPR2       MMIO32(ADC1_BASE + 0x10) // ADC sample time register 2,
#define ADC1_SMPR3       MMIO32(ADC1_BASE + 0x14) // ADC sample time register 3,
#define ADC1_JOFR1       MMIO32(ADC1_BASE + 0x18) // ADC injected channel data offset register 1,
#define ADC1_JOFR2       MMIO32(ADC1_BASE + 0x1C) // ADC injected channel data offset register 2,
#define ADC1_JOFR3       MMIO32(ADC1_BASE + 0x20) // ADC injected channel data offset register 3,
#define ADC1_JOFR4       MMIO32(ADC1_BASE + 0x24) // ADC injected channel data offset register 4,
#define ADC1_HTR         MMIO32(ADC1_BASE + 0x28) // ADC watchdog higher threshold register,
#define ADC1_LTR         MMIO32(ADC1_BASE + 0x2C) // ADC watchdog lower threshold register,
#define ADC1_SQR1        MMIO32(ADC1_BASE + 0x30) // ADC regular sequence register 1,
#define ADC1_SQR2        MMIO32(ADC1_BASE + 0x34) // ADC regular sequence register 2,
#define ADC1_SQR3        MMIO32(ADC1_BASE + 0x38) // ADC regular sequence register 3,
#define ADC1_SQR4        MMIO32(ADC1_BASE + 0x3C) // ADC regular sequence register 4,
#define ADC1_SQR5        MMIO32(ADC1_BASE + 0x40) // ADC regular sequence register 5,
#define ADC1_JSQR        MMIO32(ADC1_BASE + 0x44) // ADC injected sequence register,
#define ADC1_JDR1        MMIO32(ADC1_BASE + 0x48) // ADC injected data register 1,
#define ADC1_JDR2        MMIO32(ADC1_BASE + 0x4C) // ADC injected data register 2,
#define ADC1_JDR3        MMIO32(ADC1_BASE + 0x50) // ADC injected data register 3,
#define ADC1_JDR4        MMIO32(ADC1_BASE + 0x54) // ADC injected data register 4,
#define ADC1_DR          MMIO32(ADC1_BASE + 0x58) // ADC regular data register,
#define ADC1_SMPR0       MMIO32(ADC1_BASE + 0x5C) // ADC sample time register 0,


//****************************************************************************
//*
//*                       BIT MASKS AND DEFINITIONS
//*
//****************************************************************************


//*******************  Bit definition for ADC_SR register  *******************
#define ADC_SR_AWD                          0x00000001        // Analog watchdog flag
#define ADC_SR_EOC                          0x00000002        // End of conversion
#define ADC_SR_JEOC                         0x00000004        // Injected channel end of conversion
#define ADC_SR_JSTRT                        0x00000008        // Injected channel Start flag
#define ADC_SR_STRT                         0x00000010        // Regular channel Start flag
#define ADC_SR_OVR                          0x00000020        // Overrun flag
#define ADC_SR_ADONS                        0x00000040        // ADC ON status
#define ADC_SR_RCNR                         0x00000100        // Regular channel not ready flag
#define ADC_SR_JCNR                         0x00000200        // Injected channel not ready flag

//******************  Bit definition for ADC_CR1 register  *******************
#define ADC_CR1_AWDCH                       0x0000001F        // AWDCH[4:0] bits (Analog watchdog channel select bits)
#define ADC_CR1_AWDCH_0                     0x00000001        // Bit 0
#define ADC_CR1_AWDCH_1                     0x00000002        // Bit 1
#define ADC_CR1_AWDCH_2                     0x00000004        // Bit 2
#define ADC_CR1_AWDCH_3                     0x00000008        // Bit 3
#define ADC_CR1_AWDCH_4                     0x00000010        // Bit 4

#define ADC_CR1_EOCIE                       0x00000020        // Interrupt enable for EOC
#define ADC_CR1_AWDIE                       0x00000040        // Analog Watchdog interrupt enable
#define ADC_CR1_JEOCIE                      0x00000080        // Interrupt enable for injected channels
#define ADC_CR1_SCAN                        0x00000100        // Scan mode
#define ADC_CR1_AWDSGL                      0x00000200        // Enable the watchdog on a single channel in scan mode
#define ADC_CR1_JAUTO                       0x00000400        // Automatic injected group conversion
#define ADC_CR1_DISCEN                      0x00000800        // Discontinuous mode on regular channels
#define ADC_CR1_JDISCEN                     0x00001000        // Discontinuous mode on injected channels

#define ADC_CR1_DISCNUM                     0x0000E000        // DISCNUM[2:0] bits (Discontinuous mode channel count)
#define ADC_CR1_DISCNUM_0                   0x00002000        // Bit 0
#define ADC_CR1_DISCNUM_1                   0x00004000        // Bit 1
#define ADC_CR1_DISCNUM_2                   0x00008000        // Bit 2

#define ADC_CR1_PDD                         0x00010000        // Power Down during Delay phase
#define ADC_CR1_PDI                         0x00020000        // Power Down during Idle phase

#define ADC_CR1_JAWDEN                      0x00400000        // Analog watchdog enable on injected channels
#define ADC_CR1_AWDEN                       0x00800000        // Analog watchdog enable on regular channels

#define ADC_CR1_RES                         0x03000000        // RES[1:0] bits (Resolution)
#define ADC_CR1_RES_0                       0x01000000        // Bit 0
#define ADC_CR1_RES_1                       0x02000000        // Bit 1

#define ADC_CR1_OVRIE                       0x04000000        // Overrun interrupt enable

//******************  Bit definition for ADC_CR2 register  *******************
#define ADC_CR2_ADON                        0x00000001        // A/D Converter ON / OFF
#define ADC_CR2_CONT                        0x00000002        // Continuous Conversion
#define ADC_CR2_CFG                         0x00000004        // ADC Configuration

#define ADC_CR2_DELS                        0x00000070        // DELS[2:0] bits (Delay selection)
#define ADC_CR2_DELS_0                      0x00000010        // Bit 0
#define ADC_CR2_DELS_1                      0x00000020        // Bit 1
#define ADC_CR2_DELS_2                      0x00000040        // Bit 2

#define ADC_CR2_DMA                         0x00000100        // Direct Memory access mode
#define ADC_CR2_DDS                         0x00000200        // DMA disable selection (Single ADC)
#define ADC_CR2_EOCS                        0x00000400        // End of conversion selection
#define ADC_CR2_ALIGN                       0x00000800        // Data Alignment

#define ADC_CR2_JEXTSEL                     0x000F0000        // JEXTSEL[3:0] bits (External event select for injected group)
#define ADC_CR2_JEXTSEL_0                   0x00010000        // Bit 0
#define ADC_CR2_JEXTSEL_1                   0x00020000        // Bit 1
#define ADC_CR2_JEXTSEL_2                   0x00040000        // Bit 2
#define ADC_CR2_JEXTSEL_3                   0x00080000        // Bit 3

#define ADC_CR2_JEXTEN                      0x00300000        // JEXTEN[1:0] bits (External Trigger Conversion mode for injected channels)
#define ADC_CR2_JEXTEN_0                    0x00100000        // Bit 0
#define ADC_CR2_JEXTEN_1                    0x00200000        // Bit 1

#define ADC_CR2_JSWSTART                    0x00400000        // Start Conversion of injected channels

#define ADC_CR2_EXTSEL                      0x0F000000        // EXTSEL[3:0] bits (External Event Select for regular group)
#define ADC_CR2_EXTSEL_0                    0x01000000        // Bit 0
#define ADC_CR2_EXTSEL_1                    0x02000000        // Bit 1
#define ADC_CR2_EXTSEL_2                    0x04000000        // Bit 2
#define ADC_CR2_EXTSEL_3                    0x08000000        // Bit 3

#define ADC_CR2_EXTEN                       0x30000000        // EXTEN[1:0] bits (External Trigger Conversion mode for regular channels)
#define ADC_CR2_EXTEN_0                     0x10000000        // Bit 0
#define ADC_CR2_EXTEN_1                     0x20000000        // Bit 1

#define ADC_CR2_SWSTART                     0x40000000        // Start Conversion of regular channels

//*****************  Bit definition for ADC_SMPR1 register  ******************
#define ADC_SMPR1_SMP20                     0x00000007        // SMP20[2:0] bits (Channel 20 Sample time selection)
#define ADC_SMPR1_SMP20_0                   0x00000001        // Bit 0
#define ADC_SMPR1_SMP20_1                   0x00000002        // Bit 1
#define ADC_SMPR1_SMP20_2                   0x00000004        // Bit 2

#define ADC_SMPR1_SMP21                     0x00000038        // SMP21[2:0] bits (Channel 21 Sample time selection)
#define ADC_SMPR1_SMP21_0                   0x00000008        // Bit 0
#define ADC_SMPR1_SMP21_1                   0x00000010        // Bit 1
#define ADC_SMPR1_SMP21_2                   0x00000020        // Bit 2

#define ADC_SMPR1_SMP22                     0x000001C0        // SMP22[2:0] bits (Channel 22 Sample time selection)
#define ADC_SMPR1_SMP22_0                   0x00000040        // Bit 0
#define ADC_SMPR1_SMP22_1                   0x00000080        // Bit 1
#define ADC_SMPR1_SMP22_2                   0x00000100        // Bit 2

#define ADC_SMPR1_SMP23                     0x00000E00        // SMP23[2:0] bits (Channel 23 Sample time selection)
#define ADC_SMPR1_SMP23_0                   0x00000200        // Bit 0
#define ADC_SMPR1_SMP23_1                   0x00000400        // Bit 1
#define ADC_SMPR1_SMP23_2                   0x00000800        // Bit 2

#define ADC_SMPR1_SMP24                     0x00007000        // SMP24[2:0] bits (Channel 24 Sample time selection)
#define ADC_SMPR1_SMP24_0                   0x00001000        // Bit 0
#define ADC_SMPR1_SMP24_1                   0x00002000        // Bit 1
#define ADC_SMPR1_SMP24_2                   0x00004000        // Bit 2

#define ADC_SMPR1_SMP25                     0x00038000        // SMP25[2:0] bits (Channel 25 Sample time selection)
#define ADC_SMPR1_SMP25_0                   0x00008000        // Bit 0
#define ADC_SMPR1_SMP25_1                   0x00010000        // Bit 1
#define ADC_SMPR1_SMP25_2                   0x00020000        // Bit 2

#define ADC_SMPR1_SMP26                     0x001C0000        // SMP26[2:0] bits (Channel 26 Sample time selection)
#define ADC_SMPR1_SMP26_0                   0x00040000        // Bit 0
#define ADC_SMPR1_SMP26_1                   0x00080000        // Bit 1
#define ADC_SMPR1_SMP26_2                   0x00100000        // Bit 2

#define ADC_SMPR1_SMP27                     0x00E00000        // SMP27[2:0] bits (Channel 27 Sample time selection)
#define ADC_SMPR1_SMP27_0                   0x00200000        // Bit 0
#define ADC_SMPR1_SMP27_1                   0x00400000        // Bit 1
#define ADC_SMPR1_SMP27_2                   0x00800000        // Bit 2

#define ADC_SMPR1_SMP28                     0x07000000        // SMP28[2:0] bits (Channel 28 Sample time selection)
#define ADC_SMPR1_SMP28_0                   0x01000000        // Bit 0
#define ADC_SMPR1_SMP28_1                   0x02000000        // Bit 1
#define ADC_SMPR1_SMP28_2                   0x04000000        // Bit 2

#define ADC_SMPR1_SMP29                     0x38000000        // SMP29[2:0] bits (Channel 29 Sample time selection)
#define ADC_SMPR1_SMP29_0                   0x08000000        // Bit 0
#define ADC_SMPR1_SMP29_1                   0x10000000        // Bit 1
#define ADC_SMPR1_SMP29_2                   0x20000000        // Bit 2

//*****************  Bit definition for ADC_SMPR2 register  ******************
#define ADC_SMPR2_SMP10                     0x00000007        // SMP10[2:0] bits (Channel 10 Sample time selection)
#define ADC_SMPR2_SMP10_0                   0x00000001        // Bit 0
#define ADC_SMPR2_SMP10_1                   0x00000002        // Bit 1
#define ADC_SMPR2_SMP10_2                   0x00000004        // Bit 2

#define ADC_SMPR2_SMP11                     0x00000038        // SMP11[2:0] bits (Channel 11 Sample time selection)
#define ADC_SMPR2_SMP11_0                   0x00000008        // Bit 0
#define ADC_SMPR2_SMP11_1                   0x00000010        // Bit 1
#define ADC_SMPR2_SMP11_2                   0x00000020        // Bit 2

#define ADC_SMPR2_SMP12                     0x000001C0        // SMP12[2:0] bits (Channel 12 Sample time selection)
#define ADC_SMPR2_SMP12_0                   0x00000040        // Bit 0
#define ADC_SMPR2_SMP12_1                   0x00000080        // Bit 1
#define ADC_SMPR2_SMP12_2                   0x00000100        // Bit 2

#define ADC_SMPR2_SMP13                     0x00000E00        // SMP13[2:0] bits (Channel 13 Sample time selection)
#define ADC_SMPR2_SMP13_0                   0x00000200        // Bit 0
#define ADC_SMPR2_SMP13_1                   0x00000400        // Bit 1
#define ADC_SMPR2_SMP13_2                   0x00000800        // Bit 2

#define ADC_SMPR2_SMP14                     0x00007000        // SMP14[2:0] bits (Channel 14 Sample time selection)
#define ADC_SMPR2_SMP14_0                   0x00001000        // Bit 0
#define ADC_SMPR2_SMP14_1                   0x00002000        // Bit 1
#define ADC_SMPR2_SMP14_2                   0x00004000        // Bit 2

#define ADC_SMPR2_SMP15                     0x00038000        // SMP15[2:0] bits (Channel 5 Sample time selection)
#define ADC_SMPR2_SMP15_0                   0x00008000        // Bit 0
#define ADC_SMPR2_SMP15_1                   0x00010000        // Bit 1
#define ADC_SMPR2_SMP15_2                   0x00020000        // Bit 2

#define ADC_SMPR2_SMP16                     0x001C0000        // SMP16[2:0] bits (Channel 16 Sample time selection)
#define ADC_SMPR2_SMP16_0                   0x00040000        // Bit 0
#define ADC_SMPR2_SMP16_1                   0x00080000        // Bit 1
#define ADC_SMPR2_SMP16_2                   0x00100000        // Bit 2

#define ADC_SMPR2_SMP17                     0x00E00000        // SMP17[2:0] bits (Channel 17 Sample time selection)
#define ADC_SMPR2_SMP17_0                   0x00200000        // Bit 0
#define ADC_SMPR2_SMP17_1                   0x00400000        // Bit 1
#define ADC_SMPR2_SMP17_2                   0x00800000        // Bit 2

#define ADC_SMPR2_SMP18                     0x07000000        // SMP18[2:0] bits (Channel 18 Sample time selection)
#define ADC_SMPR2_SMP18_0                   0x01000000        // Bit 0
#define ADC_SMPR2_SMP18_1                   0x02000000        // Bit 1
#define ADC_SMPR2_SMP18_2                   0x04000000        // Bit 2

#define ADC_SMPR2_SMP19                     0x38000000        // SMP19[2:0] bits (Channel 19 Sample time selection)
#define ADC_SMPR2_SMP19_0                   0x08000000        // Bit 0
#define ADC_SMPR2_SMP19_1                   0x10000000        // Bit 1
#define ADC_SMPR2_SMP19_2                   0x20000000        // Bit 2

//*****************  Bit definition for ADC_SMPR3 register  ******************
#define ADC_SMPR3_SMP0                      0x00000007        // SMP0[2:0] bits (Channel 0 Sample time selection)
#define ADC_SMPR3_SMP0_0                    0x00000001        // Bit 0
#define ADC_SMPR3_SMP0_1                    0x00000002        // Bit 1
#define ADC_SMPR3_SMP0_2                    0x00000004        // Bit 2

#define ADC_SMPR3_SMP1                      0x00000038        // SMP1[2:0] bits (Channel 1 Sample time selection)
#define ADC_SMPR3_SMP1_0                    0x00000008        // Bit 0
#define ADC_SMPR3_SMP1_1                    0x00000010        // Bit 1
#define ADC_SMPR3_SMP1_2                    0x00000020        // Bit 2

#define ADC_SMPR3_SMP2                      0x000001C0        // SMP2[2:0] bits (Channel 2 Sample time selection)
#define ADC_SMPR3_SMP2_0                    0x00000040        // Bit 0
#define ADC_SMPR3_SMP2_1                    0x00000080        // Bit 1
#define ADC_SMPR3_SMP2_2                    0x00000100        // Bit 2

#define ADC_SMPR3_SMP3                      0x00000E00        // SMP3[2:0] bits (Channel 3 Sample time selection)
#define ADC_SMPR3_SMP3_0                    0x00000200        // Bit 0
#define ADC_SMPR3_SMP3_1                    0x00000400        // Bit 1
#define ADC_SMPR3_SMP3_2                    0x00000800        // Bit 2

#define ADC_SMPR3_SMP4                      0x00007000        // SMP4[2:0] bits (Channel 4 Sample time selection)
#define ADC_SMPR3_SMP4_0                    0x00001000        // Bit 0
#define ADC_SMPR3_SMP4_1                    0x00002000        // Bit 1
#define ADC_SMPR3_SMP4_2                    0x00004000        // Bit 2

#define ADC_SMPR3_SMP5                      0x00038000        // SMP5[2:0] bits (Channel 5 Sample time selection)
#define ADC_SMPR3_SMP5_0                    0x00008000        // Bit 0
#define ADC_SMPR3_SMP5_1                    0x00010000        // Bit 1
#define ADC_SMPR3_SMP5_2                    0x00020000        // Bit 2

#define ADC_SMPR3_SMP6                      0x001C0000        // SMP6[2:0] bits (Channel 6 Sample time selection)
#define ADC_SMPR3_SMP6_0                    0x00040000        // Bit 0
#define ADC_SMPR3_SMP6_1                    0x00080000        // Bit 1
#define ADC_SMPR3_SMP6_2                    0x00100000        // Bit 2

#define ADC_SMPR3_SMP7                      0x00E00000        // SMP7[2:0] bits (Channel 7 Sample time selection)
#define ADC_SMPR3_SMP7_0                    0x00200000        // Bit 0
#define ADC_SMPR3_SMP7_1                    0x00400000        // Bit 1
#define ADC_SMPR3_SMP7_2                    0x00800000        // Bit 2

#define ADC_SMPR3_SMP8                      0x07000000        // SMP8[2:0] bits (Channel 8 Sample time selection)
#define ADC_SMPR3_SMP8_0                    0x01000000        // Bit 0
#define ADC_SMPR3_SMP8_1                    0x02000000        // Bit 1
#define ADC_SMPR3_SMP8_2                    0x04000000        // Bit 2

#define ADC_SMPR3_SMP9                      0x38000000        // SMP9[2:0] bits (Channel 9 Sample time selection)
#define ADC_SMPR3_SMP9_0                    0x08000000        // Bit 0
#define ADC_SMPR3_SMP9_1                    0x10000000        // Bit 1
#define ADC_SMPR3_SMP9_2                    0x20000000        // Bit 2

//*****************  Bit definition for ADC_JOFR1 register  ******************
#define ADC_JOFR1_JOFFSET1                  0x00000FFF        // Data offset for injected channel 1

//*****************  Bit definition for ADC_JOFR2 register  ******************
#define ADC_JOFR2_JOFFSET2                  0x00000FFF        // Data offset for injected channel 2

//*****************  Bit definition for ADC_JOFR3 register  ******************
#define ADC_JOFR3_JOFFSET3                  0x00000FFF        // Data offset for injected channel 3

//*****************  Bit definition for ADC_JOFR4 register  ******************
#define ADC_JOFR4_JOFFSET4                  0x00000FFF        // Data offset for injected channel 4

//******************  Bit definition for ADC_HTR register  *******************
#define ADC_HTR_HT                          0x00000FFF        // Analog watchdog high threshold

//******************  Bit definition for ADC_LTR register  *******************
#define ADC_LTR_LT                          0x00000FFF        // Analog watchdog low threshold

//******************  Bit definition for ADC_SQR1 register  ******************
#define ADC_SQR1_L                          0x00F00000        // L[3:0] bits (Regular channel sequence length)
#define ADC_SQR1_L_0                        0x00100000        // Bit 0
#define ADC_SQR1_L_1                        0x00200000        // Bit 1
#define ADC_SQR1_L_2                        0x00400000        // Bit 2
#define ADC_SQR1_L_3                        0x00800000        // Bit 3

#define ADC_SQR1_SQ28                       0x000F8000        // SQ28[4:0] bits (25th conversion in regular sequence)
#define ADC_SQR1_SQ28_0                     0x00008000        // Bit 0
#define ADC_SQR1_SQ28_1                     0x00010000        // Bit 1
#define ADC_SQR1_SQ28_2                     0x00020000        // Bit 2
#define ADC_SQR1_SQ28_3                     0x00040000        // Bit 3
#define ADC_SQR1_SQ28_4                     0x00080000        // Bit 4

#define ADC_SQR1_SQ27                       0x00007C00        // SQ27[4:0] bits (27th conversion in regular sequence)
#define ADC_SQR1_SQ27_0                     0x00000400        // Bit 0
#define ADC_SQR1_SQ27_1                     0x00000800        // Bit 1
#define ADC_SQR1_SQ27_2                     0x00001000        // Bit 2
#define ADC_SQR1_SQ27_3                     0x00002000        // Bit 3
#define ADC_SQR1_SQ27_4                     0x00004000        // Bit 4

#define ADC_SQR1_SQ26                       0x000003E0        // SQ26[4:0] bits (26th conversion in regular sequence)
#define ADC_SQR1_SQ26_0                     0x00000020        // Bit 0
#define ADC_SQR1_SQ26_1                     0x00000040        // Bit 1
#define ADC_SQR1_SQ26_2                     0x00000080        // Bit 2
#define ADC_SQR1_SQ26_3                     0x00000100        // Bit 3
#define ADC_SQR1_SQ26_4                     0x00000200        // Bit 4

#define ADC_SQR1_SQ25                       0x0000001F        // SQ25[4:0] bits (25th conversion in regular sequence)
#define ADC_SQR1_SQ25_0                     0x00000001        // Bit 0
#define ADC_SQR1_SQ25_1                     0x00000002        // Bit 1
#define ADC_SQR1_SQ25_2                     0x00000004        // Bit 2
#define ADC_SQR1_SQ25_3                     0x00000008        // Bit 3
#define ADC_SQR1_SQ25_4                     0x00000010        // Bit 4

//******************  Bit definition for ADC_SQR2 register  ******************
#define ADC_SQR2_SQ19                       0x0000001F        // SQ19[4:0] bits (19th conversion in regular sequence)
#define ADC_SQR2_SQ19_0                     0x00000001        // Bit 0
#define ADC_SQR2_SQ19_1                     0x00000002        // Bit 1
#define ADC_SQR2_SQ19_2                     0x00000004        // Bit 2
#define ADC_SQR2_SQ19_3                     0x00000008        // Bit 3
#define ADC_SQR2_SQ19_4                     0x00000010        // Bit 4

#define ADC_SQR2_SQ20                       0x000003E0        // SQ20[4:0] bits (20th conversion in regular sequence)
#define ADC_SQR2_SQ20_0                     0x00000020        // Bit 0
#define ADC_SQR2_SQ20_1                     0x00000040        // Bit 1
#define ADC_SQR2_SQ20_2                     0x00000080        // Bit 2
#define ADC_SQR2_SQ20_3                     0x00000100        // Bit 3
#define ADC_SQR2_SQ20_4                     0x00000200        // Bit 4

#define ADC_SQR2_SQ21                       0x00007C00        // SQ21[4:0] bits (21th conversion in regular sequence)
#define ADC_SQR2_SQ21_0                     0x00000400        // Bit 0
#define ADC_SQR2_SQ21_1                     0x00000800        // Bit 1
#define ADC_SQR2_SQ21_2                     0x00001000        // Bit 2
#define ADC_SQR2_SQ21_3                     0x00002000        // Bit 3
#define ADC_SQR2_SQ21_4                     0x00004000        // Bit 4

#define ADC_SQR2_SQ22                       0x000F8000        // SQ22[4:0] bits (22th conversion in regular sequence)
#define ADC_SQR2_SQ22_0                     0x00008000        // Bit 0
#define ADC_SQR2_SQ22_1                     0x00010000        // Bit 1
#define ADC_SQR2_SQ22_2                     0x00020000        // Bit 2
#define ADC_SQR2_SQ22_3                     0x00040000        // Bit 3
#define ADC_SQR2_SQ22_4                     0x00080000        // Bit 4

#define ADC_SQR2_SQ23                       0x01F00000        // SQ23[4:0] bits (23th conversion in regular sequence)
#define ADC_SQR2_SQ23_0                     0x00100000        // Bit 0
#define ADC_SQR2_SQ23_1                     0x00200000        // Bit 1
#define ADC_SQR2_SQ23_2                     0x00400000        // Bit 2
#define ADC_SQR2_SQ23_3                     0x00800000        // Bit 3
#define ADC_SQR2_SQ23_4                     0x01000000        // Bit 4

#define ADC_SQR2_SQ24                       0x3E000000        // SQ24[4:0] bits (24th conversion in regular sequence)
#define ADC_SQR2_SQ24_0                     0x02000000        // Bit 0
#define ADC_SQR2_SQ24_1                     0x04000000        // Bit 1
#define ADC_SQR2_SQ24_2                     0x08000000        // Bit 2
#define ADC_SQR2_SQ24_3                     0x10000000        // Bit 3
#define ADC_SQR2_SQ24_4                     0x20000000        // Bit 4

//******************  Bit definition for ADC_SQR3 register  ******************
#define ADC_SQR3_SQ13                       0x0000001F        // SQ13[4:0] bits (13th conversion in regular sequence)
#define ADC_SQR3_SQ13_0                     0x00000001        // Bit 0
#define ADC_SQR3_SQ13_1                     0x00000002        // Bit 1
#define ADC_SQR3_SQ13_2                     0x00000004        // Bit 2
#define ADC_SQR3_SQ13_3                     0x00000008        // Bit 3
#define ADC_SQR3_SQ13_4                     0x00000010        // Bit 4

#define ADC_SQR3_SQ14                       0x000003E0        // SQ14[4:0] bits (14th conversion in regular sequence)
#define ADC_SQR3_SQ14_0                     0x00000020        // Bit 0
#define ADC_SQR3_SQ14_1                     0x00000040        // Bit 1
#define ADC_SQR3_SQ14_2                     0x00000080        // Bit 2
#define ADC_SQR3_SQ14_3                     0x00000100        // Bit 3
#define ADC_SQR3_SQ14_4                     0x00000200        // Bit 4

#define ADC_SQR3_SQ15                       0x00007C00        // SQ15[4:0] bits (15th conversion in regular sequence)
#define ADC_SQR3_SQ15_0                     0x00000400        // Bit 0
#define ADC_SQR3_SQ15_1                     0x00000800        // Bit 1
#define ADC_SQR3_SQ15_2                     0x00001000        // Bit 2
#define ADC_SQR3_SQ15_3                     0x00002000        // Bit 3
#define ADC_SQR3_SQ15_4                     0x00004000        // Bit 4

#define ADC_SQR3_SQ16                       0x000F8000        // SQ16[4:0] bits (16th conversion in regular sequence)
#define ADC_SQR3_SQ16_0                     0x00008000        // Bit 0
#define ADC_SQR3_SQ16_1                     0x00010000        // Bit 1
#define ADC_SQR3_SQ16_2                     0x00020000        // Bit 2
#define ADC_SQR3_SQ16_3                     0x00040000        // Bit 3
#define ADC_SQR3_SQ16_4                     0x00080000        // Bit 4

#define ADC_SQR3_SQ17                       0x01F00000        // SQ17[4:0] bits (17th conversion in regular sequence)
#define ADC_SQR3_SQ17_0                     0x00100000        // Bit 0
#define ADC_SQR3_SQ17_1                     0x00200000        // Bit 1
#define ADC_SQR3_SQ17_2                     0x00400000        // Bit 2
#define ADC_SQR3_SQ17_3                     0x00800000        // Bit 3
#define ADC_SQR3_SQ17_4                     0x01000000        // Bit 4

#define ADC_SQR3_SQ18                       0x3E000000        // SQ18[4:0] bits (18th conversion in regular sequence)
#define ADC_SQR3_SQ18_0                     0x02000000        // Bit 0
#define ADC_SQR3_SQ18_1                     0x04000000        // Bit 1
#define ADC_SQR3_SQ18_2                     0x08000000        // Bit 2
#define ADC_SQR3_SQ18_3                     0x10000000        // Bit 3
#define ADC_SQR3_SQ18_4                     0x20000000        // Bit 4

//******************  Bit definition for ADC_SQR4 register  ******************
#define ADC_SQR4_SQ7                        0x0000001F        // SQ7[4:0] bits (7th conversion in regular sequence)
#define ADC_SQR4_SQ7_0                      0x00000001        // Bit 0
#define ADC_SQR4_SQ7_1                      0x00000002        // Bit 1
#define ADC_SQR4_SQ7_2                      0x00000004        // Bit 2
#define ADC_SQR4_SQ7_3                      0x00000008        // Bit 3
#define ADC_SQR4_SQ7_4                      0x00000010        // Bit 4

#define ADC_SQR4_SQ8                        0x000003E0        // SQ8[4:0] bits (8th conversion in regular sequence)
#define ADC_SQR4_SQ8_0                      0x00000020        // Bit 0
#define ADC_SQR4_SQ8_1                      0x00000040        // Bit 1
#define ADC_SQR4_SQ8_2                      0x00000080        // Bit 2
#define ADC_SQR4_SQ8_3                      0x00000100        // Bit 3
#define ADC_SQR4_SQ8_4                      0x00000200        // Bit 4

#define ADC_SQR4_SQ9                        0x00007C00        // SQ9[4:0] bits (9th conversion in regular sequence)
#define ADC_SQR4_SQ9_0                      0x00000400        // Bit 0
#define ADC_SQR4_SQ9_1                      0x00000800        // Bit 1
#define ADC_SQR4_SQ9_2                      0x00001000        // Bit 2
#define ADC_SQR4_SQ9_3                      0x00002000        // Bit 3
#define ADC_SQR4_SQ9_4                      0x00004000        // Bit 4

#define ADC_SQR4_SQ10                        0x000F8000        // SQ10[4:0] bits (10th conversion in regular sequence)
#define ADC_SQR4_SQ10_0                      0x00008000        // Bit 0
#define ADC_SQR4_SQ10_1                      0x00010000        // Bit 1
#define ADC_SQR4_SQ10_2                      0x00020000        // Bit 2
#define ADC_SQR4_SQ10_3                      0x00040000        // Bit 3
#define ADC_SQR4_SQ10_4                      0x00080000        // Bit 4

#define ADC_SQR4_SQ11                        0x01F00000        // SQ11[4:0] bits (11th conversion in regular sequence)
#define ADC_SQR4_SQ11_0                      0x00100000        // Bit 0
#define ADC_SQR4_SQ11_1                      0x00200000        // Bit 1
#define ADC_SQR4_SQ11_2                      0x00400000        // Bit 2
#define ADC_SQR4_SQ11_3                      0x00800000        // Bit 3
#define ADC_SQR4_SQ11_4                      0x01000000        // Bit 4

#define ADC_SQR4_SQ12                        0x3E000000        // SQ12[4:0] bits (12th conversion in regular sequence)
#define ADC_SQR4_SQ12_0                      0x02000000        // Bit 0
#define ADC_SQR4_SQ12_1                      0x04000000        // Bit 1
#define ADC_SQR4_SQ12_2                      0x08000000        // Bit 2
#define ADC_SQR4_SQ12_3                      0x10000000        // Bit 3
#define ADC_SQR4_SQ12_4                      0x20000000        // Bit 4

//******************  Bit definition for ADC_SQR5 register  ******************
#define ADC_SQR5_SQ1                        0x0000001F        // SQ1[4:0] bits (1st conversion in regular sequence)
#define ADC_SQR5_SQ1_0                      0x00000001        // Bit 0
#define ADC_SQR5_SQ1_1                      0x00000002        // Bit 1
#define ADC_SQR5_SQ1_2                      0x00000004        // Bit 2
#define ADC_SQR5_SQ1_3                      0x00000008        // Bit 3
#define ADC_SQR5_SQ1_4                      0x00000010        // Bit 4

#define ADC_SQR5_SQ2                        0x000003E0        // SQ2[4:0] bits (2nd conversion in regular sequence)
#define ADC_SQR5_SQ2_0                      0x00000020        // Bit 0
#define ADC_SQR5_SQ2_1                      0x00000040        // Bit 1
#define ADC_SQR5_SQ2_2                      0x00000080        // Bit 2
#define ADC_SQR5_SQ2_3                      0x00000100        // Bit 3
#define ADC_SQR5_SQ2_4                      0x00000200        // Bit 4

#define ADC_SQR5_SQ3                        0x00007C00        // SQ3[4:0] bits (3rd conversion in regular sequence)
#define ADC_SQR5_SQ3_0                      0x00000400        // Bit 0
#define ADC_SQR5_SQ3_1                      0x00000800        // Bit 1
#define ADC_SQR5_SQ3_2                      0x00001000        // Bit 2
#define ADC_SQR5_SQ3_3                      0x00002000        // Bit 3
#define ADC_SQR5_SQ3_4                      0x00004000        // Bit 4

#define ADC_SQR5_SQ4                        0x000F8000        // SQ4[4:0] bits (4th conversion in regular sequence)
#define ADC_SQR5_SQ4_0                      0x00008000        // Bit 0
#define ADC_SQR5_SQ4_1                      0x00010000        // Bit 1
#define ADC_SQR5_SQ4_2                      0x00020000        // Bit 2
#define ADC_SQR5_SQ4_3                      0x00040000        // Bit 3
#define ADC_SQR5_SQ4_4                      0x00080000        // Bit 4

#define ADC_SQR5_SQ5                        0x01F00000        // SQ5[4:0] bits (5th conversion in regular sequence)
#define ADC_SQR5_SQ5_0                      0x00100000        // Bit 0
#define ADC_SQR5_SQ5_1                      0x00200000        // Bit 1
#define ADC_SQR5_SQ5_2                      0x00400000        // Bit 2
#define ADC_SQR5_SQ5_3                      0x00800000        // Bit 3
#define ADC_SQR5_SQ5_4                      0x01000000        // Bit 4

#define ADC_SQR5_SQ6                        0x3E000000        // SQ6[4:0] bits (6th conversion in regular sequence)
#define ADC_SQR5_SQ6_0                      0x02000000        // Bit 0
#define ADC_SQR5_SQ6_1                      0x04000000        // Bit 1
#define ADC_SQR5_SQ6_2                      0x08000000        // Bit 2
#define ADC_SQR5_SQ6_3                      0x10000000        // Bit 3
#define ADC_SQR5_SQ6_4                      0x20000000        // Bit 4


//******************  Bit definition for ADC_JSQR register  ******************
#define ADC_JSQR_JSQ1                       0x0000001F        // JSQ1[4:0] bits (1st conversion in injected sequence)
#define ADC_JSQR_JSQ1_0                     0x00000001        // Bit 0
#define ADC_JSQR_JSQ1_1                     0x00000002        // Bit 1
#define ADC_JSQR_JSQ1_2                     0x00000004        // Bit 2
#define ADC_JSQR_JSQ1_3                     0x00000008        // Bit 3
#define ADC_JSQR_JSQ1_4                     0x00000010        // Bit 4

#define ADC_JSQR_JSQ2                       0x000003E0        // JSQ2[4:0] bits (2nd conversion in injected sequence)
#define ADC_JSQR_JSQ2_0                     0x00000020        // Bit 0
#define ADC_JSQR_JSQ2_1                     0x00000040        // Bit 1
#define ADC_JSQR_JSQ2_2                     0x00000080        // Bit 2
#define ADC_JSQR_JSQ2_3                     0x00000100        // Bit 3
#define ADC_JSQR_JSQ2_4                     0x00000200        // Bit 4

#define ADC_JSQR_JSQ3                       0x00007C00        // JSQ3[4:0] bits (3rd conversion in injected sequence)
#define ADC_JSQR_JSQ3_0                     0x00000400        // Bit 0
#define ADC_JSQR_JSQ3_1                     0x00000800        // Bit 1
#define ADC_JSQR_JSQ3_2                     0x00001000        // Bit 2
#define ADC_JSQR_JSQ3_3                     0x00002000        // Bit 3
#define ADC_JSQR_JSQ3_4                     0x00004000        // Bit 4

#define ADC_JSQR_JSQ4                       0x000F8000        // JSQ4[4:0] bits (4th conversion in injected sequence)
#define ADC_JSQR_JSQ4_0                     0x00008000        // Bit 0
#define ADC_JSQR_JSQ4_1                     0x00010000        // Bit 1
#define ADC_JSQR_JSQ4_2                     0x00020000        // Bit 2
#define ADC_JSQR_JSQ4_3                     0x00040000        // Bit 3
#define ADC_JSQR_JSQ4_4                     0x00080000        // Bit 4

#define ADC_JSQR_JL                         0x00300000        // JL[1:0] bits (Injected Sequence length)
#define ADC_JSQR_JL_0                       0x00100000        // Bit 0
#define ADC_JSQR_JL_1                       0x00200000        // Bit 1

//******************  Bit definition for ADC_JDR1 register  ******************
#define ADC_JDR1_JDATA                      0x0000FFFF        // Injected data

//******************  Bit definition for ADC_JDR2 register  ******************
#define ADC_JDR2_JDATA                      0x0000FFFF        // Injected data

//******************  Bit definition for ADC_JDR3 register  ******************
#define ADC_JDR3_JDATA                      0x0000FFFF        // Injected data

//******************  Bit definition for ADC_JDR4 register  ******************
#define ADC_JDR4_JDATA                      0x0000FFFF        // Injected data

//*******************  Bit definition for ADC_DR register  *******************
#define ADC_DR_DATA                         0x0000FFFF        // Regular data

//*****************  Bit definition for ADC_SMPR0 register  ******************
#define ADC_SMPR3_SMP30                     0x00000007        // SMP30[2:0] bits (Channel 30 Sample time selection)
#define ADC_SMPR3_SMP30_0                   0x00000001        // Bit 0
#define ADC_SMPR3_SMP30_1                   0x00000002        // Bit 1
#define ADC_SMPR3_SMP30_2                   0x00000004        // Bit 2

#define ADC_SMPR3_SMP31                     0x00000038        // SMP31[2:0] bits (Channel 31 Sample time selection)
#define ADC_SMPR3_SMP31_0                   0x00000008        // Bit 0
#define ADC_SMPR3_SMP31_1                   0x00000010        // Bit 1
#define ADC_SMPR3_SMP31_2                   0x00000020        // Bit 2

//******************  Bit definition for ADC_CSR register  *******************
#define ADC_CSR_AWD1                        0x00000001        // ADC1 Analog watchdog flag
#define ADC_CSR_EOC1                        0x00000002        // ADC1 End of conversion
#define ADC_CSR_JEOC1                       0x00000004        // ADC1 Injected channel end of conversion
#define ADC_CSR_JSTRT1                      0x00000008        // ADC1 Injected channel Start flag
#define ADC_CSR_STRT1                       0x00000010        // ADC1 Regular channel Start flag
#define ADC_CSR_OVR1                        0x00000020        // ADC1 overrun  flag
#define ADC_CSR_ADONS1                      0x00000040        // ADON status of ADC1

//******************  Bit definition for ADC_CCR register  *******************
#define ADC_CCR_ADCPRE                      0x00030000        // ADC prescaler
#define ADC_CCR_ADCPRE_0                    0x00010000        // Bit 0
#define ADC_CCR_ADCPRE_1                    0x00020000        // Bit 1
#define ADC_CCR_TSVREFE                     0x00800000        // Temperature Sensor and VREFINT Enable
