#pragma once
#include "common.h"

// AUTHOR : Ondrej Hruska
// DATE   : 12/2015
// DESCR  : Control registers and bit masks for TIM (timers)


//****************************************************************************
//*
//*                               REGISTERS
//*
//****************************************************************************

// offsets
#define TIM_CR1_offs     0x00 // TIM control register 1
#define TIM_CR2_offs     0x04 // TIM control register 2
#define TIM_SMCR_offs    0x08 // TIM slave mode control register
#define TIM_DIER_offs    0x0C // TIM DMA/interrupt enable register
#define TIM_SR_offs      0x10 // TIM status register
#define TIM_EGR_offs     0x14 // TIM event generation register
#define TIM_CCMR1_offs   0x18 // TIM capture/compare mode register 1
#define TIM_CCMR2_offs   0x1C // TIM capture/compare mode register 2
#define TIM_CCER_offs    0x20 // TIM capture/compare enable register
#define TIM_CNT_offs     0x24 // TIM counter register
#define TIM_PSC_offs     0x28 // TIM prescaler
#define TIM_ARR_offs     0x2C // TIM auto-reload register
#define TIM_CCR1_offs    0x34 // TIM capture/compare register 1
#define TIM_CCR2_offs    0x38 // TIM capture/compare register 2
#define TIM_CCR3_offs    0x3C // TIM capture/compare register 3
#define TIM_CCR4_offs    0x40 // TIM capture/compare register 4
#define TIM_DCR_offs     0x48 // TIM DMA control register
#define TIM_DMAR_offs    0x4C // TIM DMA address for full transfer
#define TIM_OR_offs      0x50 // TIM option register



// Timer 2

#define TIM2_CR1         MMIO32(TIM2 + 0x00) // TIM control register 1,
#define TIM2_CR2         MMIO32(TIM2 + 0x04) // TIM control register 2,
#define TIM2_SMCR        MMIO32(TIM2 + 0x08) // TIM slave mode control register,
#define TIM2_DIER        MMIO32(TIM2 + 0x0C) // TIM DMA/interrupt enable register,
#define TIM2_SR          MMIO32(TIM2 + 0x10) // TIM status register,
#define TIM2_EGR         MMIO32(TIM2 + 0x14) // TIM event generation register,
#define TIM2_CCMR1       MMIO32(TIM2 + 0x18) // TIM capture/compare mode register 1,
#define TIM2_CCMR2       MMIO32(TIM2 + 0x1C) // TIM capture/compare mode register 2,
#define TIM2_CCER        MMIO32(TIM2 + 0x20) // TIM capture/compare enable register,
#define TIM2_CNT         MMIO32(TIM2 + 0x24) // TIM counter register,
#define TIM2_PSC         MMIO32(TIM2 + 0x28) // TIM prescaler,
#define TIM2_ARR         MMIO32(TIM2 + 0x2C) // TIM auto-reload register,
#define TIM2_CCR1        MMIO32(TIM2 + 0x34) // TIM capture/compare register 1,
#define TIM2_CCR2        MMIO32(TIM2 + 0x38) // TIM capture/compare register 2,
#define TIM2_CCR3        MMIO32(TIM2 + 0x3C) // TIM capture/compare register 3,
#define TIM2_CCR4        MMIO32(TIM2 + 0x40) // TIM capture/compare register 4,
#define TIM2_DCR         MMIO32(TIM2 + 0x48) // TIM DMA control register,
#define TIM2_DMAR        MMIO32(TIM2 + 0x4C) // TIM DMA address for full transfer,
#define TIM2_OR          MMIO32(TIM2 + 0x50) // TIM option register,

// Timer 3

#define TIM3_CR1         MMIO32(TIM3 + 0x00) // TIM control register 1,
#define TIM3_CR2         MMIO32(TIM3 + 0x04) // TIM control register 2,
#define TIM3_SMCR        MMIO32(TIM3 + 0x08) // TIM slave mode control register,
#define TIM3_DIER        MMIO32(TIM3 + 0x0C) // TIM DMA/interrupt enable register,
#define TIM3_SR          MMIO32(TIM3 + 0x10) // TIM status register,
#define TIM3_EGR         MMIO32(TIM3 + 0x14) // TIM event generation register,
#define TIM3_CCMR1       MMIO32(TIM3 + 0x18) // TIM capture/compare mode register 1,
#define TIM3_CCMR2       MMIO32(TIM3 + 0x1C) // TIM capture/compare mode register 2,
#define TIM3_CCER        MMIO32(TIM3 + 0x20) // TIM capture/compare enable register,
#define TIM3_CNT         MMIO32(TIM3 + 0x24) // TIM counter register,
#define TIM3_PSC         MMIO32(TIM3 + 0x28) // TIM prescaler,
#define TIM3_ARR         MMIO32(TIM3 + 0x2C) // TIM auto-reload register,
#define TIM3_CCR1        MMIO32(TIM3 + 0x34) // TIM capture/compare register 1,
#define TIM3_CCR2        MMIO32(TIM3 + 0x38) // TIM capture/compare register 2,
#define TIM3_CCR3        MMIO32(TIM3 + 0x3C) // TIM capture/compare register 3,
#define TIM3_CCR4        MMIO32(TIM3 + 0x40) // TIM capture/compare register 4,
#define TIM3_DCR         MMIO32(TIM3 + 0x48) // TIM DMA control register,
#define TIM3_DMAR        MMIO32(TIM3 + 0x4C) // TIM DMA address for full transfer,
#define TIM3_OR          MMIO32(TIM3 + 0x50) // TIM option register,

// Timer 4

#define TIM4_CR1         MMIO32(TIM4 + 0x00) // TIM control register 1,
#define TIM4_CR2         MMIO32(TIM4 + 0x04) // TIM control register 2,
#define TIM4_SMCR        MMIO32(TIM4 + 0x08) // TIM slave mode control register,
#define TIM4_DIER        MMIO32(TIM4 + 0x0C) // TIM DMA/interrupt enable register,
#define TIM4_SR          MMIO32(TIM4 + 0x10) // TIM status register,
#define TIM4_EGR         MMIO32(TIM4 + 0x14) // TIM event generation register,
#define TIM4_CCMR1       MMIO32(TIM4 + 0x18) // TIM capture/compare mode register 1,
#define TIM4_CCMR2       MMIO32(TIM4 + 0x1C) // TIM capture/compare mode register 2,
#define TIM4_CCER        MMIO32(TIM4 + 0x20) // TIM capture/compare enable register,
#define TIM4_CNT         MMIO32(TIM4 + 0x24) // TIM counter register,
#define TIM4_PSC         MMIO32(TIM4 + 0x28) // TIM prescaler,
#define TIM4_ARR         MMIO32(TIM4 + 0x2C) // TIM auto-reload register,
#define TIM4_CCR1        MMIO32(TIM4 + 0x34) // TIM capture/compare register 1,
#define TIM4_CCR2        MMIO32(TIM4 + 0x38) // TIM capture/compare register 2,
#define TIM4_CCR3        MMIO32(TIM4 + 0x3C) // TIM capture/compare register 3,
#define TIM4_CCR4        MMIO32(TIM4 + 0x40) // TIM capture/compare register 4,
#define TIM4_DCR         MMIO32(TIM4 + 0x48) // TIM DMA control register,
#define TIM4_DMAR        MMIO32(TIM4 + 0x4C) // TIM DMA address for full transfer,
#define TIM4_OR          MMIO32(TIM4 + 0x50) // TIM option register,

// Timer 5

#define TIM5_CR1         MMIO32(TIM5 + 0x00) // TIM control register 1,
#define TIM5_CR2         MMIO32(TIM5 + 0x04) // TIM control register 2,
#define TIM5_SMCR        MMIO32(TIM5 + 0x08) // TIM slave mode control register,
#define TIM5_DIER        MMIO32(TIM5 + 0x0C) // TIM DMA/interrupt enable register,
#define TIM5_SR          MMIO32(TIM5 + 0x10) // TIM status register,
#define TIM5_EGR         MMIO32(TIM5 + 0x14) // TIM event generation register,
#define TIM5_CCMR1       MMIO32(TIM5 + 0x18) // TIM capture/compare mode register 1,
#define TIM5_CCMR2       MMIO32(TIM5 + 0x1C) // TIM capture/compare mode register 2,
#define TIM5_CCER        MMIO32(TIM5 + 0x20) // TIM capture/compare enable register,
#define TIM5_CNT         MMIO32(TIM5 + 0x24) // TIM counter register,
#define TIM5_PSC         MMIO32(TIM5 + 0x28) // TIM prescaler,
#define TIM5_ARR         MMIO32(TIM5 + 0x2C) // TIM auto-reload register,
#define TIM5_CCR1        MMIO32(TIM5 + 0x34) // TIM capture/compare register 1,
#define TIM5_CCR2        MMIO32(TIM5 + 0x38) // TIM capture/compare register 2,
#define TIM5_CCR3        MMIO32(TIM5 + 0x3C) // TIM capture/compare register 3,
#define TIM5_CCR4        MMIO32(TIM5 + 0x40) // TIM capture/compare register 4,
#define TIM5_DCR         MMIO32(TIM5 + 0x48) // TIM DMA control register,
#define TIM5_DMAR        MMIO32(TIM5 + 0x4C) // TIM DMA address for full transfer,
#define TIM5_OR          MMIO32(TIM5 + 0x50) // TIM option register,

// Timer 6

#define TIM6_CR1         MMIO32(TIM6 + 0x00) // TIM control register 1,
#define TIM6_CR2         MMIO32(TIM6 + 0x04) // TIM control register 2,
#define TIM6_SMCR        MMIO32(TIM6 + 0x08) // TIM slave mode control register,
#define TIM6_DIER        MMIO32(TIM6 + 0x0C) // TIM DMA/interrupt enable register,
#define TIM6_SR          MMIO32(TIM6 + 0x10) // TIM status register,
#define TIM6_EGR         MMIO32(TIM6 + 0x14) // TIM event generation register,
#define TIM6_CCMR1       MMIO32(TIM6 + 0x18) // TIM capture/compare mode register 1,
#define TIM6_CCMR2       MMIO32(TIM6 + 0x1C) // TIM capture/compare mode register 2,
#define TIM6_CCER        MMIO32(TIM6 + 0x20) // TIM capture/compare enable register,
#define TIM6_CNT         MMIO32(TIM6 + 0x24) // TIM counter register,
#define TIM6_PSC         MMIO32(TIM6 + 0x28) // TIM prescaler,
#define TIM6_ARR         MMIO32(TIM6 + 0x2C) // TIM auto-reload register,
#define TIM6_CCR1        MMIO32(TIM6 + 0x34) // TIM capture/compare register 1,
#define TIM6_CCR2        MMIO32(TIM6 + 0x38) // TIM capture/compare register 2,
#define TIM6_CCR3        MMIO32(TIM6 + 0x3C) // TIM capture/compare register 3,
#define TIM6_CCR4        MMIO32(TIM6 + 0x40) // TIM capture/compare register 4,
#define TIM6_DCR         MMIO32(TIM6 + 0x48) // TIM DMA control register,
#define TIM6_DMAR        MMIO32(TIM6 + 0x4C) // TIM DMA address for full transfer,
#define TIM6_OR          MMIO32(TIM6 + 0x50) // TIM option register,

// Timer 7

#define TIM7_CR1         MMIO32(TIM7 + 0x00) // TIM control register 1,
#define TIM7_CR2         MMIO32(TIM7 + 0x04) // TIM control register 2,
#define TIM7_SMCR        MMIO32(TIM7 + 0x08) // TIM slave mode control register,
#define TIM7_DIER        MMIO32(TIM7 + 0x0C) // TIM DMA/interrupt enable register,
#define TIM7_SR          MMIO32(TIM7 + 0x10) // TIM status register,
#define TIM7_EGR         MMIO32(TIM7 + 0x14) // TIM event generation register,
#define TIM7_CCMR1       MMIO32(TIM7 + 0x18) // TIM capture/compare mode register 1,
#define TIM7_CCMR2       MMIO32(TIM7 + 0x1C) // TIM capture/compare mode register 2,
#define TIM7_CCER        MMIO32(TIM7 + 0x20) // TIM capture/compare enable register,
#define TIM7_CNT         MMIO32(TIM7 + 0x24) // TIM counter register,
#define TIM7_PSC         MMIO32(TIM7 + 0x28) // TIM prescaler,
#define TIM7_ARR         MMIO32(TIM7 + 0x2C) // TIM auto-reload register,
#define TIM7_CCR1        MMIO32(TIM7 + 0x34) // TIM capture/compare register 1,
#define TIM7_CCR2        MMIO32(TIM7 + 0x38) // TIM capture/compare register 2,
#define TIM7_CCR3        MMIO32(TIM7 + 0x3C) // TIM capture/compare register 3,
#define TIM7_CCR4        MMIO32(TIM7 + 0x40) // TIM capture/compare register 4,
#define TIM7_DCR         MMIO32(TIM7 + 0x48) // TIM DMA control register,
#define TIM7_DMAR        MMIO32(TIM7 + 0x4C) // TIM DMA address for full transfer,
#define TIM7_OR          MMIO32(TIM7 + 0x50) // TIM option register,

// Timer 9

#define TIM9_CR1         MMIO32(TIM9 + 0x00) // TIM control register 1,
#define TIM9_CR2         MMIO32(TIM9 + 0x04) // TIM control register 2,
#define TIM9_SMCR        MMIO32(TIM9 + 0x08) // TIM slave mode control register,
#define TIM9_DIER        MMIO32(TIM9 + 0x0C) // TIM DMA/interrupt enable register,
#define TIM9_SR          MMIO32(TIM9 + 0x10) // TIM status register,
#define TIM9_EGR         MMIO32(TIM9 + 0x14) // TIM event generation register,
#define TIM9_CCMR1       MMIO32(TIM9 + 0x18) // TIM capture/compare mode register 1,
#define TIM9_CCMR2       MMIO32(TIM9 + 0x1C) // TIM capture/compare mode register 2,
#define TIM9_CCER        MMIO32(TIM9 + 0x20) // TIM capture/compare enable register,
#define TIM9_CNT         MMIO32(TIM9 + 0x24) // TIM counter register,
#define TIM9_PSC         MMIO32(TIM9 + 0x28) // TIM prescaler,
#define TIM9_ARR         MMIO32(TIM9 + 0x2C) // TIM auto-reload register,
#define TIM9_CCR1        MMIO32(TIM9 + 0x34) // TIM capture/compare register 1,
#define TIM9_CCR2        MMIO32(TIM9 + 0x38) // TIM capture/compare register 2,
#define TIM9_CCR3        MMIO32(TIM9 + 0x3C) // TIM capture/compare register 3,
#define TIM9_CCR4        MMIO32(TIM9 + 0x40) // TIM capture/compare register 4,
#define TIM9_DCR         MMIO32(TIM9 + 0x48) // TIM DMA control register,
#define TIM9_DMAR        MMIO32(TIM9 + 0x4C) // TIM DMA address for full transfer,
#define TIM9_OR          MMIO32(TIM9 + 0x50) // TIM option register,

// Timer 10

#define TIM10_CR1        MMIO32(TIM10 + 0x00) // TIM control register 1,
#define TIM10_CR2        MMIO32(TIM10 + 0x04) // TIM control register 2,
#define TIM10_SMCR       MMIO32(TIM10 + 0x08) // TIM slave mode control register,
#define TIM10_DIER       MMIO32(TIM10 + 0x0C) // TIM DMA/interrupt enable register,
#define TIM10_SR         MMIO32(TIM10 + 0x10) // TIM status register,
#define TIM10_EGR        MMIO32(TIM10 + 0x14) // TIM event generation register,
#define TIM10_CCMR1      MMIO32(TIM10 + 0x18) // TIM capture/compare mode register 1,
#define TIM10_CCMR2      MMIO32(TIM10 + 0x1C) // TIM capture/compare mode register 2,
#define TIM10_CCER       MMIO32(TIM10 + 0x20) // TIM capture/compare enable register,
#define TIM10_CNT        MMIO32(TIM10 + 0x24) // TIM counter register,
#define TIM10_PSC        MMIO32(TIM10 + 0x28) // TIM prescaler,
#define TIM10_ARR        MMIO32(TIM10 + 0x2C) // TIM auto-reload register,
#define TIM10_CCR1       MMIO32(TIM10 + 0x34) // TIM capture/compare register 1,
#define TIM10_CCR2       MMIO32(TIM10 + 0x38) // TIM capture/compare register 2,
#define TIM10_CCR3       MMIO32(TIM10 + 0x3C) // TIM capture/compare register 3,
#define TIM10_CCR4       MMIO32(TIM10 + 0x40) // TIM capture/compare register 4,
#define TIM10_DCR        MMIO32(TIM10 + 0x48) // TIM DMA control register,
#define TIM10_DMAR       MMIO32(TIM10 + 0x4C) // TIM DMA address for full transfer,
#define TIM10_OR         MMIO32(TIM10 + 0x50) // TIM option register,

// Timer 11

#define TIM11_CR1        MMIO32(TIM11 + 0x00) // TIM control register 1,
#define TIM11_CR2        MMIO32(TIM11 + 0x04) // TIM control register 2,
#define TIM11_SMCR       MMIO32(TIM11 + 0x08) // TIM slave mode control register,
#define TIM11_DIER       MMIO32(TIM11 + 0x0C) // TIM DMA/interrupt enable register,
#define TIM11_SR         MMIO32(TIM11 + 0x10) // TIM status register,
#define TIM11_EGR        MMIO32(TIM11 + 0x14) // TIM event generation register,
#define TIM11_CCMR1      MMIO32(TIM11 + 0x18) // TIM capture/compare mode register 1,
#define TIM11_CCMR2      MMIO32(TIM11 + 0x1C) // TIM capture/compare mode register 2,
#define TIM11_CCER       MMIO32(TIM11 + 0x20) // TIM capture/compare enable register,
#define TIM11_CNT        MMIO32(TIM11 + 0x24) // TIM counter register,
#define TIM11_PSC        MMIO32(TIM11 + 0x28) // TIM prescaler,
#define TIM11_ARR        MMIO32(TIM11 + 0x2C) // TIM auto-reload register,
#define TIM11_CCR1       MMIO32(TIM11 + 0x34) // TIM capture/compare register 1,
#define TIM11_CCR2       MMIO32(TIM11 + 0x38) // TIM capture/compare register 2,
#define TIM11_CCR3       MMIO32(TIM11 + 0x3C) // TIM capture/compare register 3,
#define TIM11_CCR4       MMIO32(TIM11 + 0x40) // TIM capture/compare register 4,
#define TIM11_DCR        MMIO32(TIM11 + 0x48) // TIM DMA control register,
#define TIM11_DMAR       MMIO32(TIM11 + 0x4C) // TIM DMA address for full transfer,
#define TIM11_OR         MMIO32(TIM11 + 0x50) // TIM option register,



//****************************************************************************
//*
//*                       BIT MASKS AND DEFINITIONS
//*
//****************************************************************************


//******************  Bit definition for TIM_CR1 register  *******************
#define TIM_CR1_CEN                         0x0001            // Counter enable
#define TIM_CR1_UDIS                        0x0002            // Update disable
#define TIM_CR1_URS                         0x0004            // Update request source
#define TIM_CR1_OPM                         0x0008            // One pulse mode
#define TIM_CR1_DIR                         0x0010            // Direction

#define TIM_CR1_CMS                         0x0060            // CMS[1:0] bits (Center-aligned mode selection)
#define TIM_CR1_CMS_0                       0x0020            // Bit 0
#define TIM_CR1_CMS_1                       0x0040            // Bit 1

enum TIM_CenterAlignMode {
	TIM_CMS_EDGE = 0,
	TIM_CMS_CENTER_FLAGS_UP = 1,
	TIM_CMS_CENTER_FLAGS_DOWN = 2,
	TIM_CMS_CENTER_FLAGS_BOTH = 3,
};

#define TIM_CR1_ARPE                        0x0080            // Auto-reload preload enable

#define TIM_CR1_CKD                         0x0300            // CKD[1:0] bits (clock division)
#define TIM_CR1_CKD_0                       0x0100            // Bit 0
#define TIM_CR1_CKD_1                       0x0200            // Bit 1

//******************  Bit definition for TIM_CR2 register  *******************
#define TIM_CR2_CCDS                        0x0008            // Capture/Compare DMA Selection

#define TIM_CR2_MMS                         0x0070            // MMS[2:0] bits (Master Mode Selection)
#define TIM_CR2_MMS_0                       0x0010            // Bit 0
#define TIM_CR2_MMS_1                       0x0020            // Bit 1
#define TIM_CR2_MMS_2                       0x0040            // Bit 2

#define TIM_CR2_TI1S                        0x0080            // TI1 Selection

//******************  Bit definition for TIM_SMCR register  ******************
#define TIM_SMCR_SMS                        0x0007            // SMS[2:0] bits (Slave mode selection)
#define TIM_SMCR_SMS_0                      0x0001            // Bit 0
#define TIM_SMCR_SMS_1                      0x0002            // Bit 1
#define TIM_SMCR_SMS_2                      0x0004            // Bit 2

#define TIM_SMCR_OCCS                       0x0008            // OCCS bits (OCref Clear Selection)

#define TIM_SMCR_TS                         0x0070            // TS[2:0] bits (Trigger selection)
#define TIM_SMCR_TS_0                       0x0010            // Bit 0
#define TIM_SMCR_TS_1                       0x0020            // Bit 1
#define TIM_SMCR_TS_2                       0x0040            // Bit 2

#define TIM_SMCR_MSM                        0x0080            // Master/slave mode

#define TIM_SMCR_ETF                        0x0F00            // ETF[3:0] bits (External trigger filter)
#define TIM_SMCR_ETF_0                      0x0100            // Bit 0
#define TIM_SMCR_ETF_1                      0x0200            // Bit 1
#define TIM_SMCR_ETF_2                      0x0400            // Bit 2
#define TIM_SMCR_ETF_3                      0x0800            // Bit 3

#define TIM_SMCR_ETPS                       0x3000            // ETPS[1:0] bits (External trigger prescaler)
#define TIM_SMCR_ETPS_0                     0x1000            // Bit 0
#define TIM_SMCR_ETPS_1                     0x2000            // Bit 1

#define TIM_SMCR_ECE                        0x4000            // External clock enable
#define TIM_SMCR_ETP                        0x8000            // External trigger polarity

//******************  Bit definition for TIM_DIER register  ******************
#define TIM_DIER_UIE                        0x0001            // Update interrupt enable
#define TIM_DIER_CC1IE                      0x0002            // Capture/Compare 1 interrupt enable
#define TIM_DIER_CC2IE                      0x0004            // Capture/Compare 2 interrupt enable
#define TIM_DIER_CC3IE                      0x0008            // Capture/Compare 3 interrupt enable
#define TIM_DIER_CC4IE                      0x0010            // Capture/Compare 4 interrupt enable
#define TIM_DIER_TIE                        0x0040            // Trigger interrupt enable
#define TIM_DIER_UDE                        0x0100            // Update DMA request enable
#define TIM_DIER_CC1DE                      0x0200            // Capture/Compare 1 DMA request enable
#define TIM_DIER_CC2DE                      0x0400            // Capture/Compare 2 DMA request enable
#define TIM_DIER_CC3DE                      0x0800            // Capture/Compare 3 DMA request enable
#define TIM_DIER_CC4DE                      0x1000            // Capture/Compare 4 DMA request enable
#define TIM_DIER_TDE                        0x4000            // Trigger DMA request enable

//*******************  Bit definition for TIM_SR register  *******************
#define TIM_SR_UIF                          0x0001            // Update interrupt Flag
#define TIM_SR_CC1IF                        0x0002            // Capture/Compare 1 interrupt Flag
#define TIM_SR_CC2IF                        0x0004            // Capture/Compare 2 interrupt Flag
#define TIM_SR_CC3IF                        0x0008            // Capture/Compare 3 interrupt Flag
#define TIM_SR_CC4IF                        0x0010            // Capture/Compare 4 interrupt Flag
#define TIM_SR_TIF                          0x0040            // Trigger interrupt Flag
#define TIM_SR_CC1OF                        0x0200            // Capture/Compare 1 Overcapture Flag
#define TIM_SR_CC2OF                        0x0400            // Capture/Compare 2 Overcapture Flag
#define TIM_SR_CC3OF                        0x0800            // Capture/Compare 3 Overcapture Flag
#define TIM_SR_CC4OF                        0x1000            // Capture/Compare 4 Overcapture Flag

//******************  Bit definition for TIM_EGR register  *******************
#define TIM_EGR_UG                          0x01               // Update Generation
#define TIM_EGR_CC1G                        0x02               // Capture/Compare 1 Generation
#define TIM_EGR_CC2G                        0x04               // Capture/Compare 2 Generation
#define TIM_EGR_CC3G                        0x08               // Capture/Compare 3 Generation
#define TIM_EGR_CC4G                        0x10               // Capture/Compare 4 Generation
#define TIM_EGR_TG                          0x40               // Trigger Generation

//*****************  Bit definition for TIM_CCMR1 register  ******************
#define TIM_CCMR1_CC1S                      0x0003            // CC1S[1:0] bits (Capture/Compare 1 Selection)
#define TIM_CCMR1_CC1S_0                    0x0001            // Bit 0
#define TIM_CCMR1_CC1S_1                    0x0002            // Bit 1

#define TIM_CCMR1_OC1FE                     0x0004            // Output Compare 1 Fast enable
#define TIM_CCMR1_OC1PE                     0x0008            // Output Compare 1 Preload enable

#define TIM_CCMR1_OC1M                      0x0070            // OC1M[2:0] bits (Output Compare 1 Mode)
#define TIM_CCMR1_OC1M_0                    0x0010            // Bit 0
#define TIM_CCMR1_OC1M_1                    0x0020            // Bit 1
#define TIM_CCMR1_OC1M_2                    0x0040            // Bit 2

enum TIM_OutputCompareMode {
	TIM_OCM_FROZEN = 0,
	TIM_OCM_HIGH_ON_MATCH = 1,
	TIM_OCM_LOW_ON_MATCH = 2,
	TIM_OCM_TOGGLE_ON_MATCH = 3,
	TIM_OCM_FORCE_LOW = 4,
	TIM_OCM_FORCE_HIGH = 5,
	TIM_OCM_PWM1 = 6,
	TIM_OCM_PWM2 = 7,
};

#define TIM_CCMR1_OC1CE                     0x0080            // Output Compare 1Clear Enable

#define TIM_CCMR1_CC2S                      0x0300            // CC2S[1:0] bits (Capture/Compare 2 Selection)
#define TIM_CCMR1_CC2S_0                    0x0100            // Bit 0
#define TIM_CCMR1_CC2S_1                    0x0200            // Bit 1

#define TIM_CCMR1_OC2FE                     0x0400            // Output Compare 2 Fast enable
#define TIM_CCMR1_OC2PE                     0x0800            // Output Compare 2 Preload enable

#define TIM_CCMR1_OC2M                      0x7000            // OC2M[2:0] bits (Output Compare 2 Mode)
#define TIM_CCMR1_OC2M_0                    0x1000            // Bit 0
#define TIM_CCMR1_OC2M_1                    0x2000            // Bit 1
#define TIM_CCMR1_OC2M_2                    0x4000            // Bit 2

#define TIM_CCMR1_OC2CE                     0x8000            // Output Compare 2 Clear Enable

//----------------------------------------------------------------------------

#define TIM_CCMR1_IC1PSC                    0x000C            // IC1PSC[1:0] bits (Input Capture 1 Prescaler)
#define TIM_CCMR1_IC1PSC_0                  0x0004            // Bit 0
#define TIM_CCMR1_IC1PSC_1                  0x0008            // Bit 1

#define TIM_CCMR1_IC1F                      0x00F0            // IC1F[3:0] bits (Input Capture 1 Filter)
#define TIM_CCMR1_IC1F_0                    0x0010            // Bit 0
#define TIM_CCMR1_IC1F_1                    0x0020            // Bit 1
#define TIM_CCMR1_IC1F_2                    0x0040            // Bit 2
#define TIM_CCMR1_IC1F_3                    0x0080            // Bit 3

#define TIM_CCMR1_IC2PSC                    0x0C00            // IC2PSC[1:0] bits (Input Capture 2 Prescaler)
#define TIM_CCMR1_IC2PSC_0                  0x0400            // Bit 0
#define TIM_CCMR1_IC2PSC_1                  0x0800            // Bit 1

#define TIM_CCMR1_IC2F                      0xF000            // IC2F[3:0] bits (Input Capture 2 Filter)
#define TIM_CCMR1_IC2F_0                    0x1000            // Bit 0
#define TIM_CCMR1_IC2F_1                    0x2000            // Bit 1
#define TIM_CCMR1_IC2F_2                    0x4000            // Bit 2
#define TIM_CCMR1_IC2F_3                    0x8000            // Bit 3

//*****************  Bit definition for TIM_CCMR2 register  ******************
#define TIM_CCMR2_CC3S                      0x0003            // CC3S[1:0] bits (Capture/Compare 3 Selection)
#define TIM_CCMR2_CC3S_0                    0x0001            // Bit 0
#define TIM_CCMR2_CC3S_1                    0x0002            // Bit 1

#define TIM_CCMR2_OC3FE                     0x0004            // Output Compare 3 Fast enable
#define TIM_CCMR2_OC3PE                     0x0008            // Output Compare 3 Preload enable

#define TIM_CCMR2_OC3M                      0x0070            // OC3M[2:0] bits (Output Compare 3 Mode)
#define TIM_CCMR2_OC3M_0                    0x0010            // Bit 0
#define TIM_CCMR2_OC3M_1                    0x0020            // Bit 1
#define TIM_CCMR2_OC3M_2                    0x0040            // Bit 2

#define TIM_CCMR2_OC3CE                     0x0080            // Output Compare 3 Clear Enable

#define TIM_CCMR2_CC4S                      0x0300            // CC4S[1:0] bits (Capture/Compare 4 Selection)
#define TIM_CCMR2_CC4S_0                    0x0100            // Bit 0
#define TIM_CCMR2_CC4S_1                    0x0200            // Bit 1

#define TIM_CCMR2_OC4FE                     0x0400            // Output Compare 4 Fast enable
#define TIM_CCMR2_OC4PE                     0x0800            // Output Compare 4 Preload enable

#define TIM_CCMR2_OC4M                      0x7000            // OC4M[2:0] bits (Output Compare 4 Mode)
#define TIM_CCMR2_OC4M_0                    0x1000            // Bit 0
#define TIM_CCMR2_OC4M_1                    0x2000            // Bit 1
#define TIM_CCMR2_OC4M_2                    0x4000            // Bit 2

#define TIM_CCMR2_OC4CE                     0x8000            // Output Compare 4 Clear Enable

//----------------------------------------------------------------------------

#define TIM_CCMR2_IC3PSC                    0x000C            // IC3PSC[1:0] bits (Input Capture 3 Prescaler)
#define TIM_CCMR2_IC3PSC_0                  0x0004            // Bit 0
#define TIM_CCMR2_IC3PSC_1                  0x0008            // Bit 1

#define TIM_CCMR2_IC3F                      0x00F0            // IC3F[3:0] bits (Input Capture 3 Filter)
#define TIM_CCMR2_IC3F_0                    0x0010            // Bit 0
#define TIM_CCMR2_IC3F_1                    0x0020            // Bit 1
#define TIM_CCMR2_IC3F_2                    0x0040            // Bit 2
#define TIM_CCMR2_IC3F_3                    0x0080            // Bit 3

#define TIM_CCMR2_IC4PSC                    0x0C00            // IC4PSC[1:0] bits (Input Capture 4 Prescaler)
#define TIM_CCMR2_IC4PSC_0                  0x0400            // Bit 0
#define TIM_CCMR2_IC4PSC_1                  0x0800            // Bit 1

#define TIM_CCMR2_IC4F                      0xF000            // IC4F[3:0] bits (Input Capture 4 Filter)
#define TIM_CCMR2_IC4F_0                    0x1000            // Bit 0
#define TIM_CCMR2_IC4F_1                    0x2000            // Bit 1
#define TIM_CCMR2_IC4F_2                    0x4000            // Bit 2
#define TIM_CCMR2_IC4F_3                    0x8000            // Bit 3

//******************  Bit definition for TIM_CCER register  ******************
#define TIM_CCER_CC1E                       0x0001            // Capture/Compare 1 output enable
#define TIM_CCER_CC1P                       0x0002            // Capture/Compare 1 output Polarity
#define TIM_CCER_CC1NP                      0x0008            // Capture/Compare 1 Complementary output Polarity
#define TIM_CCER_CC2E                       0x0010            // Capture/Compare 2 output enable
#define TIM_CCER_CC2P                       0x0020            // Capture/Compare 2 output Polarity
#define TIM_CCER_CC2NP                      0x0080            // Capture/Compare 2 Complementary output Polarity
#define TIM_CCER_CC3E                       0x0100            // Capture/Compare 3 output enable
#define TIM_CCER_CC3P                       0x0200            // Capture/Compare 3 output Polarity
#define TIM_CCER_CC3NP                      0x0800            // Capture/Compare 3 Complementary output Polarity
#define TIM_CCER_CC4E                       0x1000            // Capture/Compare 4 output enable
#define TIM_CCER_CC4P                       0x2000            // Capture/Compare 4 output Polarity
#define TIM_CCER_CC4NP                      0x8000            // Capture/Compare 4 Complementary output Polarity

//******************  Bit definition for TIM_CNT register  *******************
#define TIM_CNT_CNT                         0xFFFF            // Counter Value

//******************  Bit definition for TIM_PSC register  *******************
#define TIM_PSC_PSC                         0xFFFF            // Prescaler Value

//******************  Bit definition for TIM_ARR register  *******************
#define TIM_ARR_ARR                         0xFFFF            // actual auto-reload Value

//******************  Bit definition for TIM_CCR1 register  ******************
#define TIM_CCR1_CCR1                       0xFFFF            // Capture/Compare 1 Value

//******************  Bit definition for TIM_CCR2 register  ******************
#define TIM_CCR2_CCR2                       0xFFFF            // Capture/Compare 2 Value

//******************  Bit definition for TIM_CCR3 register  ******************
#define TIM_CCR3_CCR3                       0xFFFF            // Capture/Compare 3 Value

//******************  Bit definition for TIM_CCR4 register  ******************
#define TIM_CCR4_CCR4                       0xFFFF            // Capture/Compare 4 Value

//******************  Bit definition for TIM_DCR register  *******************
#define TIM_DCR_DBA                         0x001F            // DBA[4:0] bits (DMA Base Address)
#define TIM_DCR_DBA_0                       0x0001            // Bit 0
#define TIM_DCR_DBA_1                       0x0002            // Bit 1
#define TIM_DCR_DBA_2                       0x0004            // Bit 2
#define TIM_DCR_DBA_3                       0x0008            // Bit 3
#define TIM_DCR_DBA_4                       0x0010            // Bit 4

#define TIM_DCR_DBL                         0x1F00            // DBL[4:0] bits (DMA Burst Length)
#define TIM_DCR_DBL_0                       0x0100            // Bit 0
#define TIM_DCR_DBL_1                       0x0200            // Bit 1
#define TIM_DCR_DBL_2                       0x0400            // Bit 2
#define TIM_DCR_DBL_3                       0x0800            // Bit 3
#define TIM_DCR_DBL_4                       0x1000            // Bit 4

//******************  Bit definition for TIM_DMAR register  ******************
#define TIM_DMAR_DMAB                       0xFFFF            // DMA register for burst accesses

//******************  Bit definition for TIM_OR register  ********************
#define TIM_OR_TI1RMP                       0x0003            // Option register for TI1 Remapping
#define TIM_OR_TI1RMP_0                     0x0001            // Bit 0
#define TIM_OR_TI1RMP_1                     0x0002            // Bit 1
