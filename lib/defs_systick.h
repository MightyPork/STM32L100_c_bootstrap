#pragma once

#include "common.h"

// AUTHOR : Ondrej Hruska
// DATE   : 12/2015
// DESCR  : Control registers and bit masks for SysTick


//****************************************************************************
//*
//*                               REGISTERS
//*
//****************************************************************************


#define SysTick_CSR           MMIO32(SCS_BASE + 0x010)        // (R/W) SysTick Control and Status Register
#define SysTick_RELOAD        MMIO32(SCS_BASE + 0x014)        // (R/W) SysTick Reload Value Register
#define SysTick_VAL           MMIO32(SCS_BASE + 0x018)        // (R/W) SysTick Current Value Register
#define SysTick_CALIB         MMIO32(SCS_BASE + 0x01C)        // (R/ ) SysTick Calibration Value Register



//****************************************************************************
//*
//*                       BIT MASKS AND DEFINITIONS
//*
//****************************************************************************


//****************  Bit definition for SysTick_CSR register  ****************

#define SysTick_CSR_ENABLE                 0x00000001    // Counter enable
#define SysTick_CSR_TICKINT                0x00000002    // Enable interrupt when counter reaches zero
#define SysTick_CSR_CLKSOURCE              0x00000004    // Clock source (0 - external, 1 - core clock)

#define SysTick_CSR_CLKSOURCE_CORE         0x00000004    // Clock source - core clock
#define SysTick_CSR_CLKSOURCE_DIV8         0x00000000    // Clock source - core clock / 8

#define SysTick_CSR_COUNTFLAG              0x00010000    // Count Flag (only if interrupt is disabled)


//****************  Bit definition for SysTick_LOAD register  ****************

#define SysTick_RELOAD_MASK                0x00FFFFFF    // Reload value used when the counter reaches 0


//****************  Bit definition for SysTick_VAL register  *****************

#define SysTick_VAL_MASK                   0x00FFFFFF    // Current value at the time the register is accessed


//****************  Bit definition for SysTick_CALIB register  ***************

#define SysTick_CALIB_TENMS                0x00FFFFFF    // Reload value to use for 10ms timing
#define SysTick_CALIB_SKEW                 0x40000000    // Calibration value is not exactly 10 ms
#define SysTick_CALIB_NOREF                0x80000000    // The reference clock is not provided
