#pragma once
#include "common.h"

// AUTHOR : Ondrej Hruska
// DATE   : 12/2015
// DESCR  : Control registers and bit masks for SPI


//****************************************************************************
//*
//*                               REGISTERS
//*
//****************************************************************************

// offsets
#define SPI_CR1_offs      0x00 // SPI1 control register 1 (not used in I2S mode)
#define SPI_CR2_offs      0x04 // SPI1 control register 2
#define SPI_SR_offs       0x08 // SPI1 status register
#define SPI_DR_offs       0x0C // SPI1 data register
#define SPI_CRCPR_offs    0x10 // SPI1 CRC polynomial register (not used in I2S mode)
#define SPI_RXCRCR_offs   0x14 // SPI1 RX CRC register (not used in I2S mode)
#define SPI_TXCRCR_offs   0x18 // SPI1 TX CRC register (not used in I2S mode)
#define SPI_I2SCFGR_offs  0x1C // SPI1_I2S configuration register
#define SPI_I2SPR_offs    0x20 // SPI1_I2S prescaler register


// SPI 1

#define SPI1_CR1         MMIO32(SPI1 + 0x00) // SPI1 control register 1 (not used in I2S mode),
#define SPI1_CR2         MMIO32(SPI1 + 0x04) // SPI1 control register 2,
#define SPI1_SR          MMIO32(SPI1 + 0x08) // SPI1 status register,
#define SPI1_DR          MMIO32(SPI1 + 0x0C) // SPI1 data register,
#define SPI1_CRCPR       MMIO32(SPI1 + 0x10) // SPI1 CRC polynomial register (not used in I2S mode),
#define SPI1_RXCRCR      MMIO32(SPI1 + 0x14) // SPI1 RX CRC register (not used in I2S mode),
#define SPI1_TXCRCR      MMIO32(SPI1 + 0x18) // SPI1 TX CRC register (not used in I2S mode),
#define SPI1_I2SCFGR     MMIO32(SPI1 + 0x1C) // SPI1_I2S configuration register,
#define SPI1_I2SPR       MMIO32(SPI1 + 0x20) // SPI1_I2S prescaler register,

// SPI 2

#define SPI2_CR1        MMIO32(SPI2 + 0x00) // SPI2 control register 1 (not used in I2S mode),
#define SPI2_CR2        MMIO32(SPI2 + 0x04) // SPI2 control register 2,
#define SPI2_SR         MMIO32(SPI2 + 0x08) // SPI2 status register,
#define SPI2_DR         MMIO32(SPI2 + 0x0C) // SPI2 data register,
#define SPI2_CRCPR      MMIO32(SPI2 + 0x10) // SPI2 CRC polynomial register (not used in I2S mode),
#define SPI2_RXCRCR     MMIO32(SPI2 + 0x14) // SPI2 RX CRC register (not used in I2S mode),
#define SPI2_TXCRCR     MMIO32(SPI2 + 0x18) // SPI2 TX CRC register (not used in I2S mode),
#define SPI2_I2SCFGR    MMIO32(SPI2 + 0x1C) // SPI2_I2S configuration register,
#define SPI2_I2SPR      MMIO32(SPI2 + 0x20) // SPI2_I2S prescaler register,

// SPI 3

#define SPI3_CR1          MMIO32(SPI3 + 0x00) // SPI3 control register 1 (not used in I2S mode),
#define SPI3_CR2          MMIO32(SPI3 + 0x04) // SPI3 control register 2,
#define SPI3_SR           MMIO32(SPI3 + 0x08) // SPI3 status register,
#define SPI3_DR           MMIO32(SPI3 + 0x0C) // SPI3 data register,
#define SPI3_CRCPR        MMIO32(SPI3 + 0x10) // SPI3 CRC polynomial register (not used in I2S mode),
#define SPI3_RXCRCR       MMIO32(SPI3 + 0x14) // SPI3 RX CRC register (not used in I2S mode),
#define SPI3_TXCRCR       MMIO32(SPI3 + 0x18) // SPI3 TX CRC register (not used in I2S mode),
#define SPI3_I2SCFGR      MMIO32(SPI3 + 0x1C) // SPI3_I2S configuration register,
#define SPI3_I2SPR        MMIO32(SPI3 + 0x20) // SPI3_I2S prescaler register,



//****************************************************************************
//*
//*                       BIT MASKS AND DEFINITIONS
//*
//****************************************************************************


//******************  Bit definition for SPI_CR1 register  *******************
#define SPI_CR1_CPHA                        0x0001            // Clock Phase
#define SPI_CR1_CPOL                        0x0002            // Clock Polarity
#define SPI_CR1_MSTR                        0x0004            // Master Selection

#define SPI_CR1_BR                          0x0038            // BR[2:0] bits (Baud Rate Control)
#define SPI_CR1_BR_0                        0x0008            // Bit 0
#define SPI_CR1_BR_1                        0x0010            // Bit 1
#define SPI_CR1_BR_2                        0x0020            // Bit 2

#define SPI_CR1_SPE                         0x0040            // SPI Enable
#define SPI_CR1_LSBFIRST                    0x0080            // Frame Format
#define SPI_CR1_SSI                         0x0100            // Internal slave select
#define SPI_CR1_SSM                         0x0200            // Software slave management
#define SPI_CR1_RXONLY                      0x0400            // Receive only
#define SPI_CR1_DFF                         0x0800            // Data Frame Format
#define SPI_CR1_CRCNEXT                     0x1000            // Transmit CRC next
#define SPI_CR1_CRCEN                       0x2000            // Hardware CRC calculation enable
#define SPI_CR1_BIDIOE                      0x4000            // Output enable in bidirectional mode
#define SPI_CR1_BIDIMODE                    0x8000            // Bidirectional data mode enable

//******************  Bit definition for SPI_CR2 register  *******************
#define SPI_CR2_RXDMAEN                     0x01               // Rx Buffer DMA Enable
#define SPI_CR2_TXDMAEN                     0x02               // Tx Buffer DMA Enable
#define SPI_CR2_SSOE                        0x04               // SS Output Enable
#define SPI_CR2_FRF                         0x08               // Frame format
#define SPI_CR2_ERRIE                       0x20               // Error Interrupt Enable
#define SPI_CR2_RXNEIE                      0x40               // RX buffer Not Empty Interrupt Enable
#define SPI_CR2_TXEIE                       0x80               // Tx buffer Empty Interrupt Enable

//*******************  Bit definition for SPI_SR register  *******************
#define SPI_SR_RXNE                         0x01               // Receive buffer Not Empty
#define SPI_SR_TXE                          0x02               // Transmit buffer Empty
#define SPI_SR_CHSIDE                       0x04               // Channel side
#define SPI_SR_UDR                          0x08               // Underrun flag
#define SPI_SR_CRCERR                       0x10               // CRC Error flag
#define SPI_SR_MODF                         0x20               // Mode fault
#define SPI_SR_OVR                          0x40               // Overrun flag
#define SPI_SR_BSY                          0x80               // Busy flag

//*******************  Bit definition for SPI_DR register  *******************
#define SPI_DR_DR                           0xFFFF            // Data Register

//******************  Bit definition for SPI_CRCPR register  *****************
#define SPI_CRCPR_CRCPOLY                   0xFFFF            // CRC polynomial register

//*****************  Bit definition for SPI_RXCRCR register  *****************
#define SPI_RXCRCR_RXCRC                    0xFFFF            // Rx CRC Register

//*****************  Bit definition for SPI_TXCRCR register  *****************
#define SPI_TXCRCR_TXCRC                    0xFFFF            // Tx CRC Register

//*****************  Bit definition for SPI_I2SCFGR register  ****************
#define SPI_I2SCFGR_CHLEN                   0x0001            // Channel length (number of bits per audio channel)

#define SPI_I2SCFGR_DATLEN                  0x0006            // DATLEN[1:0] bits (Data length to be transferred)
#define SPI_I2SCFGR_DATLEN_0                0x0002            // Bit 0
#define SPI_I2SCFGR_DATLEN_1                0x0004            // Bit 1

#define SPI_I2SCFGR_CKPOL                   0x0008            // steady state clock polarity

#define SPI_I2SCFGR_I2SSTD                  0x0030            // I2SSTD[1:0] bits (I2S standard selection)
#define SPI_I2SCFGR_I2SSTD_0                0x0010            // Bit 0
#define SPI_I2SCFGR_I2SSTD_1                0x0020            // Bit 1

#define SPI_I2SCFGR_PCMSYNC                 0x0080            // PCM frame synchronization

#define SPI_I2SCFGR_I2SCFG                  0x0300            // I2SCFG[1:0] bits (I2S configuration mode)
#define SPI_I2SCFGR_I2SCFG_0                0x0100            // Bit 0
#define SPI_I2SCFGR_I2SCFG_1                0x0200            // Bit 1

#define SPI_I2SCFGR_I2SE                    0x0400            // I2S Enable
#define SPI_I2SCFGR_I2SMOD                  0x0800            // I2S mode selection

//*****************  Bit definition for SPI_I2SPR register  ******************
#define SPI_I2SPR_I2SDIV                    0x00FF            // I2S Linear prescaler
#define SPI_I2SPR_ODD                       0x0100            // Odd factor for the prescaler
#define SPI_I2SPR_MCKOE                     0x0200            // Master Clock Output Enable
