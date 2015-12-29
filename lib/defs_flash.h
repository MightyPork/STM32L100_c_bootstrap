#pragma once
#include "common.h"

// AUTHOR : Ondrej Hruska
// DATE   : 12/2015
// DESCR  : Control registers and bit masks for FLASH control
//
//                FLASH, DATA EEPROM and Option Bytes Registers


//****************************************************************************
//*
//*                               REGISTERS
//*
//****************************************************************************


// FLASH registers

#define FLASH_ACR           MMIO32(FLASH_CTRL + 0x00) // Access control register,
#define FLASH_PECR          MMIO32(FLASH_CTRL + 0x04) // Program/erase control register,
#define FLASH_PDKEYR        MMIO32(FLASH_CTRL + 0x08) // Power down key register,
#define FLASH_PEKEYR        MMIO32(FLASH_CTRL + 0x0c) // Program/erase key register,
#define FLASH_PRGKEYR       MMIO32(FLASH_CTRL + 0x10) // Program memory key register,
#define FLASH_OPTKEYR       MMIO32(FLASH_CTRL + 0x14) // Option byte key register,
#define FLASH_SR            MMIO32(FLASH_CTRL + 0x18) // Status register,
#define FLASH_OBR           MMIO32(FLASH_CTRL + 0x1c) // Option byte register,
#define FLASH_WRPR          MMIO32(FLASH_CTRL + 0x20) // Write protection register,
#define FLASH_WRPR1         MMIO32(FLASH_CTRL + 0x28) // Write protection register 1,
#define FLASH_WRPR2         MMIO32(FLASH_CTRL + 0x2C) // Write protection register 2,

// FLASH option bytes (maybe incorrect, not tested)

#define OB_RDP              MMIO32(OB_CTRL + 0x00) // Read protection register,
#define OB_USER             MMIO32(OB_CTRL + 0x04) // user register,
#define OB_WRP01            MMIO32(OB_CTRL + 0x08) // write protection register 0 1,
#define OB_WRP23            MMIO32(OB_CTRL + 0x0C) // write protection register 2 3,
#define OB_WRP45            MMIO32(OB_CTRL + 0x10) // write protection register 4 5,
#define OB_WRP67            MMIO32(OB_CTRL + 0x14) // write protection register 6 7,
#define OB_WRP89            MMIO32(OB_CTRL + 0x18) // write protection register 8 9,
#define OB_WRP1011          MMIO32(OB_CTRL + 0x1C) // write protection register 10 11,



//****************************************************************************
//*
//*                       BIT MASKS AND DEFINITIONS
//*
//****************************************************************************


//******************  Bit definition for FLASH_ACR register  *****************
#define FLASH_ACR_LATENCY                   0x00000001        // Latency
#define FLASH_ACR_PRFTEN                    0x00000002        // Prefetch Buffer Enable
#define FLASH_ACR_ACC64                     0x00000004        // Access 64 bits
#define FLASH_ACR_SLEEP_PD                  0x00000008        // Flash mode during sleep mode
#define FLASH_ACR_RUN_PD                    0x00000010        // Flash mode during RUN mode

//******************  Bit definition for FLASH_PECR register  *****************
#define FLASH_PECR_PELOCK                    0x00000001        // FLASH_PECR and Flash data Lock
#define FLASH_PECR_PRGLOCK                   0x00000002        // Program matrix Lock
#define FLASH_PECR_OPTLOCK                   0x00000004        // Option byte matrix Lock
#define FLASH_PECR_PROG                      0x00000008        // Program matrix selection
#define FLASH_PECR_DATA                      0x00000010        // Data matrix selection
#define FLASH_PECR_FTDW                      0x00000100        // Fixed Time Data write for Word/Half Word/Byte programming
#define FLASH_PECR_ERASE                     0x00000200        // Page erasing mode
#define FLASH_PECR_FPRG                      0x00000400        // Fast Page/Half Page programming mode
#define FLASH_PECR_PARALLBANK                0x00008000        // Parallel Bank mode
#define FLASH_PECR_EOPIE                     0x00010000        // End of programming interrupt
#define FLASH_PECR_ERRIE                     0x00020000        // Error interrupt
#define FLASH_PECR_OBL_LAUNCH                0x00040000        // Launch the option byte loading

//*****************  Bit definition for FLASH_PDKEYR register  *****************
#define FLASH_PDKEYR_PDKEYR                 0xFFFFFFFF       // FLASH_PEC and data matrix Key

//*****************  Bit definition for FLASH_PEKEYR register  *****************
#define FLASH_PEKEYR_PEKEYR                 0xFFFFFFFF       // FLASH_PEC and data matrix Key

//*****************  Bit definition for FLASH_PRGKEYR register  *****************
#define FLASH_PRGKEYR_PRGKEYR               0xFFFFFFFF        // Program matrix Key

//*****************  Bit definition for FLASH_OPTKEYR register  *****************
#define FLASH_OPTKEYR_OPTKEYR               0xFFFFFFFF        // Option bytes matrix Key

//*****************  Bit definition for FLASH_SR register  ******************
#define FLASH_SR_BSY                        0x00000001        // Busy
#define FLASH_SR_EOP                        0x00000002        // End Of Programming
#define FLASH_SR_ENHV                       0x00000004        // End of high voltage
#define FLASH_SR_READY                      0x00000008        // Flash ready after low power mode

#define FLASH_SR_WRPERR                     0x00000100        // Write protected error
#define FLASH_SR_PGAERR                     0x00000200        // Programming Alignment Error
#define FLASH_SR_SIZERR                     0x00000400        // Size error
#define FLASH_SR_OPTVERR                    0x00000800        // Option validity error
#define FLASH_SR_OPTVERRUSR                 0x00001000        // Option User validity error
#define FLASH_SR_RDERR                      0x00002000        // Read protected error

//*****************  Bit definition for FLASH_OBR register  ******************
#define FLASH_OBR_RDPRT                     0x000000AA        // Read Protection
#define FLASH_OBR_SPRMOD                    0x00000100        // Selection of protection mode of WPRi bits  (available only in STM32L1xx Medium-density Plus devices)
#define FLASH_OBR_BOR_LEV                   0x000F0000        // BOR_LEV[3:0] Brown Out Reset Threshold Level
#define FLASH_OBR_IWDG_SW                   0x00100000        // IWDG_SW
#define FLASH_OBR_nRST_STOP                 0x00200000        // nRST_STOP
#define FLASH_OBR_nRST_STDBY                0x00400000        // nRST_STDBY
#define FLASH_OBR_BFB2                      0x00800000        // BFB2(available only in STM32L1xx High-density devices)

//*****************  Bit definition for FLASH_WRPR register  *****************
#define FLASH_WRPR_WRP                      0xFFFFFFFF        // Write Protection bits

//*****************  Bit definition for FLASH_WRPR1 register  ****************
#define FLASH_WRPR1_WRP                     0xFFFFFFFF        // Write Protection bits (available only in STM32L1xx  Medium-density Plus and High-density devices)

//*****************  Bit definition for FLASH_WRPR2 register  ****************
#define FLASH_WRPR2_WRP                     0xFFFFFFFF        // Write Protection bits (available only in STM32L1xx High-density devices)
