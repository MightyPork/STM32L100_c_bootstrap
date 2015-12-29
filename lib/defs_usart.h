#pragma once
#include "common.h"

// AUTHOR : Ondrej Hruska
// DATE   : 12/2015
// DESCR  : Control registers and bit masks for USART
//
//      Universal Synchronous Asynchronous Receiver Transmitter (USART)


//****************************************************************************
//*
//*                               REGISTERS
//*
//****************************************************************************

// offsets
#define USART_SR_offs    0x00 // USART1 Status register,
#define USART_DR_offs    0x04 // USART1 Data register,
#define USART_BRR_offs   0x08 // USART1 Baud rate register,
#define USART_CR1_offs   0x0C // USART1 Control register 1,
#define USART_CR2_offs   0x10 // USART1 Control register 2,
#define USART_CR3_offs   0x14 // USART1 Control register 3,
#define USART_GTPR_offs  0x18 // USART1 Guard time and prescaler register,


// USART 1

#define USART1_SR           MMIO32(USART1 + 0x00) // USART1 Status register,
#define USART1_DR           MMIO32(USART1 + 0x04) // USART1 Data register,
#define USART1_BRR          MMIO32(USART1 + 0x08) // USART1 Baud rate register,
#define USART1_CR1          MMIO32(USART1 + 0x0C) // USART1 Control register 1,
#define USART1_CR2          MMIO32(USART1 + 0x10) // USART1 Control register 2,
#define USART1_CR3          MMIO32(USART1 + 0x14) // USART1 Control register 3,
#define USART1_GTPR         MMIO32(USART1 + 0x18) // USART1 Guard time and prescaler register,

// USART 2

#define USART2_SR         MMIO32(USART2 + 0x00) // USART2 Status register,
#define USART2_DR         MMIO32(USART2 + 0x04) // USART2 Data register,
#define USART2_BRR        MMIO32(USART2 + 0x08) // USART2 Baud rate register,
#define USART2_CR1        MMIO32(USART2 + 0x0C) // USART2 Control register 1,
#define USART2_CR2        MMIO32(USART2 + 0x10) // USART2 Control register 2,
#define USART2_CR3        MMIO32(USART2 + 0x14) // USART2 Control register 3,
#define USART2_GTPR       MMIO32(USART2 + 0x18) // USART2 Guard time and prescaler register,

// USART 3

#define USART3_SR         MMIO32(USART3 + 0x00) // USART3 Status register,
#define USART3_DR         MMIO32(USART3 + 0x04) // USART3 Data register,
#define USART3_BRR        MMIO32(USART3 + 0x08) // USART3 Baud rate register,
#define USART3_CR1        MMIO32(USART3 + 0x0C) // USART3 Control register 1,
#define USART3_CR2        MMIO32(USART3 + 0x10) // USART3 Control register 2,
#define USART3_CR3        MMIO32(USART3 + 0x14) // USART3 Control register 3,
#define USART3_GTPR       MMIO32(USART3 + 0x18) // USART3 Guard time and prescaler register,

// USART 4

#define UART4_SR          MMIO32(UART4 + 0x00) // UART4 Status register,
#define UART4_DR          MMIO32(UART4 + 0x04) // UART4 Data register,
#define UART4_BRR         MMIO32(UART4 + 0x08) // UART4 Baud rate register,
#define UART4_CR1         MMIO32(UART4 + 0x0C) // UART4 Control register 1,
#define UART4_CR2         MMIO32(UART4 + 0x10) // UART4 Control register 2,
#define UART4_CR3         MMIO32(UART4 + 0x14) // UART4 Control register 3,
#define UART4_GTPR        MMIO32(UART4 + 0x18) // UART4 Guard time and prescaler register,

// USART 5

#define UART5_SR          MMIO32(UART5 + 0x00) // UART5 Status register,
#define UART5_DR          MMIO32(UART5 + 0x04) // UART5 Data register,
#define UART5_BRR         MMIO32(UART5 + 0x08) // UART5 Baud rate register,
#define UART5_CR1         MMIO32(UART5 + 0x0C) // UART5 Control register 1,
#define UART5_CR2         MMIO32(UART5 + 0x10) // UART5 Control register 2,
#define UART5_CR3         MMIO32(UART5 + 0x14) // UART5 Control register 3,
#define UART5_GTPR        MMIO32(UART5 + 0x18) // UART5 Guard time and prescaler register,



//****************************************************************************
//*
//*                       BIT MASKS AND DEFINITIONS
//*
//****************************************************************************


//******************  Bit definition for USART_SR register  ******************
#define USART_SR_PE                         0x0001            // Parity Error
#define USART_SR_FE                         0x0002            // Framing Error
#define USART_SR_NE                         0x0004            // Noise Error Flag
#define USART_SR_ORE                        0x0008            // OverRun Error
#define USART_SR_IDLE                       0x0010            // IDLE line detected
#define USART_SR_RXNE                       0x0020            // Read Data Register Not Empty
#define USART_SR_TC                         0x0040            // Transmission Complete
#define USART_SR_TXE                        0x0080            // Transmit Data Register Empty
#define USART_SR_LBD                        0x0100            // LIN Break Detection Flag
#define USART_SR_CTS                        0x0200            // CTS Flag

//******************  Bit definition for USART_DR register  ******************
#define USART_DR_DR                         0x01FF            // Data value

//*****************  Bit definition for USART_BRR register  ******************
#define USART_BRR_DIV_FRACTION              0x000F            // Fraction of USARTDIV
#define USART_BRR_DIV_MANTISSA              0xFFF0            // Mantissa of USARTDIV

//*****************  Bit definition for USART_CR1 register  ******************
#define USART_CR1_SBK                       0x0001            // Send Break
#define USART_CR1_RWU                       0x0002            // Receiver wakeup
#define USART_CR1_RE                        0x0004            // Receiver Enable
#define USART_CR1_TE                        0x0008            // Transmitter Enable
#define USART_CR1_IDLEIE                    0x0010            // IDLE Interrupt Enable
#define USART_CR1_RXNEIE                    0x0020            // RXNE Interrupt Enable
#define USART_CR1_TCIE                      0x0040            // Transmission Complete Interrupt Enable
#define USART_CR1_TXEIE                     0x0080            // PE Interrupt Enable
#define USART_CR1_PEIE                      0x0100            // PE Interrupt Enable
#define USART_CR1_PS                        0x0200            // Parity Selection
#define USART_CR1_PCE                       0x0400            // Parity Control Enable
#define USART_CR1_WAKE                      0x0800            // Wakeup method
#define USART_CR1_M                         0x1000            // Word length
#define USART_CR1_UE                        0x2000            // USART Enable
#define USART_CR1_OVER8                     0x8000            // Oversampling by 8-bit mode

//*****************  Bit definition for USART_CR2 register  ******************
#define USART_CR2_ADD                       0x000F            // Address of the USART node
#define USART_CR2_LBDL                      0x0020            // LIN Break Detection Length
#define USART_CR2_LBDIE                     0x0040            // LIN Break Detection Interrupt Enable
#define USART_CR2_LBCL                      0x0100            // Last Bit Clock pulse
#define USART_CR2_CPHA                      0x0200            // Clock Phase
#define USART_CR2_CPOL                      0x0400            // Clock Polarity
#define USART_CR2_CLKEN                     0x0800            // Clock Enable

#define USART_CR2_STOP                      0x3000            // STOP[1:0] bits (STOP bits)
#define USART_CR2_STOP_0                    0x1000            // Bit 0
#define USART_CR2_STOP_1                    0x2000            // Bit 1

#define USART_CR2_LINEN                     0x4000            // LIN mode enable

//*****************  Bit definition for USART_CR3 register  ******************
#define USART_CR3_EIE                       0x0001            // Error Interrupt Enable
#define USART_CR3_IREN                      0x0002            // IrDA mode Enable
#define USART_CR3_IRLP                      0x0004            // IrDA Low-Power
#define USART_CR3_HDSEL                     0x0008            // Half-Duplex Selection
#define USART_CR3_NACK                      0x0010            // Smartcard NACK enable
#define USART_CR3_SCEN                      0x0020            // Smartcard mode enable
#define USART_CR3_DMAR                      0x0040            // DMA Enable Receiver
#define USART_CR3_DMAT                      0x0080            // DMA Enable Transmitter
#define USART_CR3_RTSE                      0x0100            // RTS Enable
#define USART_CR3_CTSE                      0x0200            // CTS Enable
#define USART_CR3_CTSIE                     0x0400            // CTS Interrupt Enable
#define USART_CR3_ONEBIT                    0x0800            // One sample bit method enable

//*****************  Bit definition for USART_GTPR register  *****************
#define USART_GTPR_PSC                      0x00FF            // PSC[7:0] bits (Prescaler value)
#define USART_GTPR_PSC_0                    0x0001            // Bit 0
#define USART_GTPR_PSC_1                    0x0002            // Bit 1
#define USART_GTPR_PSC_2                    0x0004            // Bit 2
#define USART_GTPR_PSC_3                    0x0008            // Bit 3
#define USART_GTPR_PSC_4                    0x0010            // Bit 4
#define USART_GTPR_PSC_5                    0x0020            // Bit 5
#define USART_GTPR_PSC_6                    0x0040            // Bit 6
#define USART_GTPR_PSC_7                    0x0080            // Bit 7

#define USART_GTPR_GT                       0xFF00            // Guard time value
