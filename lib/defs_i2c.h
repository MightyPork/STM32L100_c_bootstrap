#pragma once
#include "common.h"

// AUTHOR : Ondrej Hruska
// DATE   : 12/2015
// DESCR  : Control registers and bit masks for I2C



//****************************************************************************
//*
//*                               REGISTERS
//*
//****************************************************************************

// offsets
#define I2C_CR1_offs      0x00 // I2C Control register 1
#define I2C_CR2_offs      0x04 // I2C Control register 2
#define I2C_OAR1_offs     0x08 // I2C Own address register 1
#define I2C_OAR2_offs     0x0C // I2C Own address register 2
#define I2C_DR_offs       0x10 // I2C Data register
#define I2C_SR1_offs      0x14 // I2C Status register 1
#define I2C_SR2_offs      0x18 // I2C Status register 2
#define I2C_CCR_offs      0x1C // I2C Clock control register
#define I2C_TRISE_offs    0x20 // I2C TRISE register

// I2C 1

#define I2C1_CR1          MMIO32(I2C1 + 0x00) // I2C1 Control register 1,
#define I2C1_CR2          MMIO32(I2C1 + 0x04) // I2C1 Control register 2,
#define I2C1_OAR1         MMIO32(I2C1 + 0x08) // I2C1 Own address register 1,
#define I2C1_OAR2         MMIO32(I2C1 + 0x0C) // I2C1 Own address register 2,
#define I2C1_DR           MMIO32(I2C1 + 0x10) // I2C1 Data register,
#define I2C1_SR1          MMIO32(I2C1 + 0x14) // I2C1 Status register 1,
#define I2C1_SR2          MMIO32(I2C1 + 0x18) // I2C1 Status register 2,
#define I2C1_CCR          MMIO32(I2C1 + 0x1C) // I2C1 Clock control register,
#define I2C1_TRISE        MMIO32(I2C1 + 0x20) // I2C1 TRISE register,

// I2C 2

#define I2C2_CR1          MMIO32(I2C2 + 0x00) // I2C2 Control register 1,
#define I2C2_CR2          MMIO32(I2C2 + 0x04) // I2C2 Control register 2,
#define I2C2_OAR1         MMIO32(I2C2 + 0x08) // I2C2 Own address register 1,
#define I2C2_OAR2         MMIO32(I2C2 + 0x0C) // I2C2 Own address register 2,
#define I2C2_DR           MMIO32(I2C2 + 0x10) // I2C2 Data register,
#define I2C2_SR1          MMIO32(I2C2 + 0x14) // I2C2 Status register 1,
#define I2C2_SR2          MMIO32(I2C2 + 0x18) // I2C2 Status register 2,
#define I2C2_CCR          MMIO32(I2C2 + 0x1C) // I2C2 Clock control register,
#define I2C2_TRISE        MMIO32(I2C2 + 0x20) // I2C2 TRISE register,


//****************************************************************************
//*
//*                       BIT MASKS AND DEFINITIONS
//*
//****************************************************************************


//******************  Bit definition for I2C_CR1 register  *******************
#define I2C_CR1_PE                          0x0001            // Peripheral Enable
#define I2C_CR1_SMBUS                       0x0002            // SMBus Mode
#define I2C_CR1_SMBTYPE                     0x0008            // SMBus Type
#define I2C_CR1_ENARP                       0x0010            // ARP Enable
#define I2C_CR1_ENPEC                       0x0020            // PEC Enable
#define I2C_CR1_ENGC                        0x0040            // General Call Enable
#define I2C_CR1_NOSTRETCH                   0x0080            // Clock Stretching Disable (Slave mode)
#define I2C_CR1_START                       0x0100            // Start Generation
#define I2C_CR1_STOP                        0x0200            // Stop Generation
#define I2C_CR1_ACK                         0x0400            // Acknowledge Enable
#define I2C_CR1_POS                         0x0800            // Acknowledge/PEC Position (for data reception)
#define I2C_CR1_PEC                         0x1000            // Packet Error Checking
#define I2C_CR1_ALERT                       0x2000            // SMBus Alert
#define I2C_CR1_SWRST                       0x8000            // Software Reset

//******************  Bit definition for I2C_CR2 register  *******************
#define I2C_CR2_FREQ                        0x003F            // FREQ[5:0] bits (Peripheral Clock Frequency)
#define I2C_CR2_FREQ_0                      0x0001            // Bit 0
#define I2C_CR2_FREQ_1                      0x0002            // Bit 1
#define I2C_CR2_FREQ_2                      0x0004            // Bit 2
#define I2C_CR2_FREQ_3                      0x0008            // Bit 3
#define I2C_CR2_FREQ_4                      0x0010            // Bit 4
#define I2C_CR2_FREQ_5                      0x0020            // Bit 5

#define I2C_CR2_ITERREN                     0x0100            // Error Interrupt Enable
#define I2C_CR2_ITEVTEN                     0x0200            // Event Interrupt Enable
#define I2C_CR2_ITBUFEN                     0x0400            // Buffer Interrupt Enable
#define I2C_CR2_DMAEN                       0x0800            // DMA Requests Enable
#define I2C_CR2_LAST                        0x1000            // DMA Last Transfer

//******************  Bit definition for I2C_OAR1 register  ******************
#define I2C_OAR1_ADD1_7                     0x00FE            // Interface Address
#define I2C_OAR1_ADD8_9                     0x0300            // Interface Address

#define I2C_OAR1_ADD0                       0x0001            // Bit 0
#define I2C_OAR1_ADD1                       0x0002            // Bit 1
#define I2C_OAR1_ADD2                       0x0004            // Bit 2
#define I2C_OAR1_ADD3                       0x0008            // Bit 3
#define I2C_OAR1_ADD4                       0x0010            // Bit 4
#define I2C_OAR1_ADD5                       0x0020            // Bit 5
#define I2C_OAR1_ADD6                       0x0040            // Bit 6
#define I2C_OAR1_ADD7                       0x0080            // Bit 7
#define I2C_OAR1_ADD8                       0x0100            // Bit 8
#define I2C_OAR1_ADD9                       0x0200            // Bit 9

#define I2C_OAR1_ADDMODE                    0x8000            // Addressing Mode (Slave mode)

//******************  Bit definition for I2C_OAR2 register  ******************
#define I2C_OAR2_ENDUAL                     0x01               // Dual addressing mode enable
#define I2C_OAR2_ADD2                       0xFE               // Interface address

//*******************  Bit definition for I2C_DR register  *******************
#define I2C_DR_DR                           0xFF               // 8-bit Data Register

//******************  Bit definition for I2C_SR1 register  *******************
#define I2C_SR1_SB                          0x0001            // Start Bit (Master mode)
#define I2C_SR1_ADDR                        0x0002            // Address sent (master mode)/matched (slave mode)
#define I2C_SR1_BTF                         0x0004            // Byte Transfer Finished
#define I2C_SR1_ADD10                       0x0008            // 10-bit header sent (Master mode)
#define I2C_SR1_STOPF                       0x0010            // Stop detection (Slave mode)
#define I2C_SR1_RXNE                        0x0040            // Data Register not Empty (receivers)
#define I2C_SR1_TXE                         0x0080            // Data Register Empty (transmitters)
#define I2C_SR1_BERR                        0x0100            // Bus Error
#define I2C_SR1_ARLO                        0x0200            // Arbitration Lost (master mode)
#define I2C_SR1_AF                          0x0400            // Acknowledge Failure
#define I2C_SR1_OVR                         0x0800            // Overrun/Underrun
#define I2C_SR1_PECERR                      0x1000            // PEC Error in reception
#define I2C_SR1_TIMEOUT                     0x4000            // Timeout or Tlow Error
#define I2C_SR1_SMBALERT                    0x8000            // SMBus Alert

//******************  Bit definition for I2C_SR2 register  *******************
#define I2C_SR2_MSL                         0x0001            // Master/Slave
#define I2C_SR2_BUSY                        0x0002            // Bus Busy
#define I2C_SR2_TRA                         0x0004            // Transmitter/Receiver
#define I2C_SR2_GENCALL                     0x0010            // General Call Address (Slave mode)
#define I2C_SR2_SMBDEFAULT                  0x0020            // SMBus Device Default Address (Slave mode)
#define I2C_SR2_SMBHOST                     0x0040            // SMBus Host Header (Slave mode)
#define I2C_SR2_DUALF                       0x0080            // Dual Flag (Slave mode)
#define I2C_SR2_PEC                         0xFF00            // Packet Error Checking Register

//******************  Bit definition for I2C_CCR register  *******************
#define I2C_CCR_CCR                         0x0FFF            // Clock Control Register in Fast/Standard mode (Master mode)
#define I2C_CCR_DUTY                        0x4000            // Fast Mode Duty Cycle
#define I2C_CCR_FS                          0x8000            // I2C Master Mode Selection

//*****************  Bit definition for I2C_TRISE register  ******************
#define I2C_TRISE_TRISE                     0x3F               // Maximum Rise Time in Fast/Standard mode (Master mode)
