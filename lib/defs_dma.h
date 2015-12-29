#pragma once
#include "common.h"

// AUTHOR : Ondrej Hruska
// DATE   : 12/2015
// DESCR  : Control registers and bit masks for DMA (Direct memory access)


//****************************************************************************
//*
//*                               REGISTERS
//*
//****************************************************************************


// DMA 1

// Status registers
#define DMA1_ISR            MMIO32(_DMA1 + 0x00) // DMA interrupt status register,
#define DMA1_IFCR           MMIO32(_DMA1 + 0x04) // DMA interrupt flag clear register,

// Channel bases
#define DMA1_CH1    (_DMA1 + 0x0008)
#define DMA1_CH2    (_DMA1 + 0x001C)
#define DMA1_CH3    (_DMA1 + 0x0030)
#define DMA1_CH4    (_DMA1 + 0x0044)
#define DMA1_CH5    (_DMA1 + 0x0058)
#define DMA1_CH6    (_DMA1 + 0x006C)
#define DMA1_CH7    (_DMA1 + 0x0080)

// offsets
#define DMA_CCR_offs          0x00 // DMA channel x configuration register
#define DMA_CNDTR_offs        0x04 // DMA channel x number of data register
#define DMA_CPAR_offs         0x08 // DMA channel x peripheral address register
#define DMA_CMAR_offs         0x0C // DMA channel x memory address register



#define DMA1_CH1_CCR          MMIO32(DMA1_CH1 + 0x00) // DMA channel x configuration register
#define DMA1_CH1_CNDTR        MMIO32(DMA1_CH1 + 0x04) // DMA channel x number of data register
#define DMA1_CH1_CPAR         MMIO32(DMA1_CH1 + 0x08) // DMA channel x peripheral address register
#define DMA1_CH1_CMAR         MMIO32(DMA1_CH1 + 0x0C) // DMA channel x memory address register

#define DMA1_CH2_CCR          MMIO32(DMA1_CH2 + 0x00) // DMA channel x configuration register
#define DMA1_CH2_CNDTR        MMIO32(DMA1_CH2 + 0x04) // DMA channel x number of data register
#define DMA1_CH2_CPAR         MMIO32(DMA1_CH2 + 0x08) // DMA channel x peripheral address register
#define DMA1_CH2_CMAR         MMIO32(DMA1_CH2 + 0x0C) // DMA channel x memory address register

#define DMA1_CH3_CCR          MMIO32(DMA1_CH3 + 0x00) // DMA channel x configuration register
#define DMA1_CH3_CNDTR        MMIO32(DMA1_CH3 + 0x04) // DMA channel x number of data register
#define DMA1_CH3_CPAR         MMIO32(DMA1_CH3 + 0x08) // DMA channel x peripheral address register
#define DMA1_CH3_CMAR         MMIO32(DMA1_CH3 + 0x0C) // DMA channel x memory address register

#define DMA1_CH4_CCR          MMIO32(DMA1_CH4 + 0x00) // DMA channel x configuration register
#define DMA1_CH4_CNDTR        MMIO32(DMA1_CH4 + 0x04) // DMA channel x number of data register
#define DMA1_CH4_CPAR         MMIO32(DMA1_CH4 + 0x08) // DMA channel x peripheral address register
#define DMA1_CH4_CMAR         MMIO32(DMA1_CH4 + 0x0C) // DMA channel x memory address register

#define DMA1_CH5_CCR          MMIO32(DMA1_CH5 + 0x00) // DMA channel x configuration register
#define DMA1_CH5_CNDTR        MMIO32(DMA1_CH5 + 0x04) // DMA channel x number of data register
#define DMA1_CH5_CPAR         MMIO32(DMA1_CH5 + 0x08) // DMA channel x peripheral address register
#define DMA1_CH5_CMAR         MMIO32(DMA1_CH5 + 0x0C) // DMA channel x memory address register

#define DMA1_CH6_CCR          MMIO32(DMA1_CH6 + 0x00) // DMA channel x configuration register
#define DMA1_CH6_CNDTR        MMIO32(DMA1_CH6 + 0x04) // DMA channel x number of data register
#define DMA1_CH6_CPAR         MMIO32(DMA1_CH6 + 0x08) // DMA channel x peripheral address register
#define DMA1_CH6_CMAR         MMIO32(DMA1_CH6 + 0x0C) // DMA channel x memory address register

#define DMA1_CH7_CCR          MMIO32(DMA1_CH7 + 0x00) // DMA channel x configuration register
#define DMA1_CH7_CNDTR        MMIO32(DMA1_CH7 + 0x04) // DMA channel x number of data register
#define DMA1_CH7_CPAR         MMIO32(DMA1_CH7 + 0x08) // DMA channel x peripheral address register
#define DMA1_CH7_CMAR         MMIO32(DMA1_CH7 + 0x0C) // DMA channel x memory address register


// DMA 2

// Status registers
#define DMA2_ISR            (_DMA2 + 0x00) // DMA interrupt status register,
#define DMA2_IFCR           (_DMA2 + 0x04) // DMA interrupt flag clear register,

// Channel bases
#define DMA2_CH1    (_DMA2 + 0x0008)
#define DMA2_CH2    (_DMA2 + 0x001C)
#define DMA2_CH3    (_DMA2 + 0x0030)
#define DMA2_CH4    (_DMA2 + 0x0044)
#define DMA2_CH5    (_DMA2 + 0x0058)

#define DMA2_CH1_CCR          MMIO32(DMA2_CH1 + 0x00) // DMA channel x configuration register
#define DMA2_CH1_CNDTR        MMIO32(DMA2_CH1 + 0x04) // DMA channel x number of data register
#define DMA2_CH1_CPAR         MMIO32(DMA2_CH1 + 0x08) // DMA channel x peripheral address register
#define DMA2_CH1_CMAR         MMIO32(DMA2_CH1 + 0x0C) // DMA channel x memory address register

#define DMA2_CH2_CCR          MMIO32(DMA2_CH2 + 0x00) // DMA channel x configuration register
#define DMA2_CH2_CNDTR        MMIO32(DMA2_CH2 + 0x04) // DMA channel x number of data register
#define DMA2_CH2_CPAR         MMIO32(DMA2_CH2 + 0x08) // DMA channel x peripheral address register
#define DMA2_CH2_CMAR         MMIO32(DMA2_CH2 + 0x0C) // DMA channel x memory address register

#define DMA2_CH3_CCR          MMIO32(DMA2_CH3 + 0x00) // DMA channel x configuration register
#define DMA2_CH3_CNDTR        MMIO32(DMA2_CH3 + 0x04) // DMA channel x number of data register
#define DMA2_CH3_CPAR         MMIO32(DMA2_CH3 + 0x08) // DMA channel x peripheral address register
#define DMA2_CH3_CMAR         MMIO32(DMA2_CH3 + 0x0C) // DMA channel x memory address register

#define DMA2_CH4_CCR          MMIO32(DMA2_CH4 + 0x00) // DMA channel x configuration register
#define DMA2_CH4_CNDTR        MMIO32(DMA2_CH4 + 0x04) // DMA channel x number of data register
#define DMA2_CH4_CPAR         MMIO32(DMA2_CH4 + 0x08) // DMA channel x peripheral address register
#define DMA2_CH4_CMAR         MMIO32(DMA2_CH4 + 0x0C) // DMA channel x memory address register

#define DMA2_CH5_CCR          MMIO32(DMA2_CH5 + 0x00) // DMA channel x configuration register
#define DMA2_CH5_CNDTR        MMIO32(DMA2_CH5 + 0x04) // DMA channel x number of data register
#define DMA2_CH5_CPAR         MMIO32(DMA2_CH5 + 0x08) // DMA channel x peripheral address register
#define DMA2_CH5_CMAR         MMIO32(DMA2_CH5 + 0x0C) // DMA channel x memory address register



//****************************************************************************
//*
//*                       BIT MASKS AND DEFINITIONS
//*
//****************************************************************************


//******************  Bit definition for DMA_ISR register  *******************
#define DMA_ISR_GIF1                        0x00000001        // Channel 1 Global interrupt flag
#define DMA_ISR_TCIF1                       0x00000002        // Channel 1 Transfer Complete flag
#define DMA_ISR_HTIF1                       0x00000004        // Channel 1 Half Transfer flag
#define DMA_ISR_TEIF1                       0x00000008        // Channel 1 Transfer Error flag
#define DMA_ISR_GIF2                        0x00000010        // Channel 2 Global interrupt flag
#define DMA_ISR_TCIF2                       0x00000020        // Channel 2 Transfer Complete flag
#define DMA_ISR_HTIF2                       0x00000040        // Channel 2 Half Transfer flag
#define DMA_ISR_TEIF2                       0x00000080        // Channel 2 Transfer Error flag
#define DMA_ISR_GIF3                        0x00000100        // Channel 3 Global interrupt flag
#define DMA_ISR_TCIF3                       0x00000200        // Channel 3 Transfer Complete flag
#define DMA_ISR_HTIF3                       0x00000400        // Channel 3 Half Transfer flag
#define DMA_ISR_TEIF3                       0x00000800        // Channel 3 Transfer Error flag
#define DMA_ISR_GIF4                        0x00001000        // Channel 4 Global interrupt flag
#define DMA_ISR_TCIF4                       0x00002000        // Channel 4 Transfer Complete flag
#define DMA_ISR_HTIF4                       0x00004000        // Channel 4 Half Transfer flag
#define DMA_ISR_TEIF4                       0x00008000        // Channel 4 Transfer Error flag
#define DMA_ISR_GIF5                        0x00010000        // Channel 5 Global interrupt flag
#define DMA_ISR_TCIF5                       0x00020000        // Channel 5 Transfer Complete flag
#define DMA_ISR_HTIF5                       0x00040000        // Channel 5 Half Transfer flag
#define DMA_ISR_TEIF5                       0x00080000        // Channel 5 Transfer Error flag
#define DMA_ISR_GIF6                        0x00100000        // Channel 6 Global interrupt flag
#define DMA_ISR_TCIF6                       0x00200000        // Channel 6 Transfer Complete flag
#define DMA_ISR_HTIF6                       0x00400000        // Channel 6 Half Transfer flag
#define DMA_ISR_TEIF6                       0x00800000        // Channel 6 Transfer Error flag
#define DMA_ISR_GIF7                        0x01000000        // Channel 7 Global interrupt flag
#define DMA_ISR_TCIF7                       0x02000000        // Channel 7 Transfer Complete flag
#define DMA_ISR_HTIF7                       0x04000000        // Channel 7 Half Transfer flag
#define DMA_ISR_TEIF7                       0x08000000        // Channel 7 Transfer Error flag

//******************  Bit definition for DMA_IFCR register  ******************
#define DMA_IFCR_CGIF1                      0x00000001        // Channel 1 Global interrupt clearr
#define DMA_IFCR_CTCIF1                     0x00000002        // Channel 1 Transfer Complete clear
#define DMA_IFCR_CHTIF1                     0x00000004        // Channel 1 Half Transfer clear
#define DMA_IFCR_CTEIF1                     0x00000008        // Channel 1 Transfer Error clear
#define DMA_IFCR_CGIF2                      0x00000010        // Channel 2 Global interrupt clear
#define DMA_IFCR_CTCIF2                     0x00000020        // Channel 2 Transfer Complete clear
#define DMA_IFCR_CHTIF2                     0x00000040        // Channel 2 Half Transfer clear
#define DMA_IFCR_CTEIF2                     0x00000080        // Channel 2 Transfer Error clear
#define DMA_IFCR_CGIF3                      0x00000100        // Channel 3 Global interrupt clear
#define DMA_IFCR_CTCIF3                     0x00000200        // Channel 3 Transfer Complete clear
#define DMA_IFCR_CHTIF3                     0x00000400        // Channel 3 Half Transfer clear
#define DMA_IFCR_CTEIF3                     0x00000800        // Channel 3 Transfer Error clear
#define DMA_IFCR_CGIF4                      0x00001000        // Channel 4 Global interrupt clear
#define DMA_IFCR_CTCIF4                     0x00002000        // Channel 4 Transfer Complete clear
#define DMA_IFCR_CHTIF4                     0x00004000        // Channel 4 Half Transfer clear
#define DMA_IFCR_CTEIF4                     0x00008000        // Channel 4 Transfer Error clear
#define DMA_IFCR_CGIF5                      0x00010000        // Channel 5 Global interrupt clear
#define DMA_IFCR_CTCIF5                     0x00020000        // Channel 5 Transfer Complete clear
#define DMA_IFCR_CHTIF5                     0x00040000        // Channel 5 Half Transfer clear
#define DMA_IFCR_CTEIF5                     0x00080000        // Channel 5 Transfer Error clear
#define DMA_IFCR_CGIF6                      0x00100000        // Channel 6 Global interrupt clear
#define DMA_IFCR_CTCIF6                     0x00200000        // Channel 6 Transfer Complete clear
#define DMA_IFCR_CHTIF6                     0x00400000        // Channel 6 Half Transfer clear
#define DMA_IFCR_CTEIF6                     0x00800000        // Channel 6 Transfer Error clear
#define DMA_IFCR_CGIF7                      0x01000000        // Channel 7 Global interrupt clear
#define DMA_IFCR_CTCIF7                     0x02000000        // Channel 7 Transfer Complete clear
#define DMA_IFCR_CHTIF7                     0x04000000        // Channel 7 Half Transfer clear
#define DMA_IFCR_CTEIF7                     0x08000000        // Channel 7 Transfer Error clear

//******************  Bit definition for DMA_CCR1 register  ******************
#define DMA_CCR1_EN                         0x0001            // Channel enable
#define DMA_CCR1_TCIE                       0x0002            // Transfer complete interrupt enable
#define DMA_CCR1_HTIE                       0x0004            // Half Transfer interrupt enable
#define DMA_CCR1_TEIE                       0x0008            // Transfer error interrupt enable
#define DMA_CCR1_DIR                        0x0010            // Data transfer direction
#define DMA_CCR1_CIRC                       0x0020            // Circular mode
#define DMA_CCR1_PINC                       0x0040            // Peripheral increment mode
#define DMA_CCR1_MINC                       0x0080            // Memory increment mode

#define DMA_CCR1_PSIZE                      0x0300            // PSIZE[1:0] bits (Peripheral size)
#define DMA_CCR1_PSIZE_0                    0x0100            // Bit 0
#define DMA_CCR1_PSIZE_1                    0x0200            // Bit 1

#define DMA_CCR1_MSIZE                      0x0C00            // MSIZE[1:0] bits (Memory size)
#define DMA_CCR1_MSIZE_0                    0x0400            // Bit 0
#define DMA_CCR1_MSIZE_1                    0x0800            // Bit 1

#define DMA_CCR1_PL                         0x3000            // PL[1:0] bits(Channel Priority level)
#define DMA_CCR1_PL_0                       0x1000            // Bit 0
#define DMA_CCR1_PL_1                       0x2000            // Bit 1

#define DMA_CCR1_MEM2MEM                    0x4000            // Memory to memory mode

//******************  Bit definition for DMA_CCR2 register  ******************
#define DMA_CCR2_EN                         0x0001            // Channel enable
#define DMA_CCR2_TCIE                       0x0002            // ransfer complete interrupt enable
#define DMA_CCR2_HTIE                       0x0004            // Half Transfer interrupt enable
#define DMA_CCR2_TEIE                       0x0008            // Transfer error interrupt enable
#define DMA_CCR2_DIR                        0x0010            // Data transfer direction
#define DMA_CCR2_CIRC                       0x0020            // Circular mode
#define DMA_CCR2_PINC                       0x0040            // Peripheral increment mode
#define DMA_CCR2_MINC                       0x0080            // Memory increment mode

#define DMA_CCR2_PSIZE                      0x0300            // PSIZE[1:0] bits (Peripheral size)
#define DMA_CCR2_PSIZE_0                    0x0100            // Bit 0
#define DMA_CCR2_PSIZE_1                    0x0200            // Bit 1

#define DMA_CCR2_MSIZE                      0x0C00            // MSIZE[1:0] bits (Memory size)
#define DMA_CCR2_MSIZE_0                    0x0400            // Bit 0
#define DMA_CCR2_MSIZE_1                    0x0800            // Bit 1

#define DMA_CCR2_PL                         0x3000            // PL[1:0] bits (Channel Priority level)
#define DMA_CCR2_PL_0                       0x1000            // Bit 0
#define DMA_CCR2_PL_1                       0x2000            // Bit 1

#define DMA_CCR2_MEM2MEM                    0x4000            // Memory to memory mode

//******************  Bit definition for DMA_CCR3 register  ******************
#define DMA_CCR3_EN                         0x0001            // Channel enable
#define DMA_CCR3_TCIE                       0x0002            // Transfer complete interrupt enable
#define DMA_CCR3_HTIE                       0x0004            // Half Transfer interrupt enable
#define DMA_CCR3_TEIE                       0x0008            // Transfer error interrupt enable
#define DMA_CCR3_DIR                        0x0010            // Data transfer direction
#define DMA_CCR3_CIRC                       0x0020            // Circular mode
#define DMA_CCR3_PINC                       0x0040            // Peripheral increment mode
#define DMA_CCR3_MINC                       0x0080            // Memory increment mode

#define DMA_CCR3_PSIZE                      0x0300            // PSIZE[1:0] bits (Peripheral size)
#define DMA_CCR3_PSIZE_0                    0x0100            // Bit 0
#define DMA_CCR3_PSIZE_1                    0x0200            // Bit 1

#define DMA_CCR3_MSIZE                      0x0C00            // MSIZE[1:0] bits (Memory size)
#define DMA_CCR3_MSIZE_0                    0x0400            // Bit 0
#define DMA_CCR3_MSIZE_1                    0x0800            // Bit 1

#define DMA_CCR3_PL                         0x3000            // PL[1:0] bits (Channel Priority level)
#define DMA_CCR3_PL_0                       0x1000            // Bit 0
#define DMA_CCR3_PL_1                       0x2000            // Bit 1

#define DMA_CCR3_MEM2MEM                    0x4000            // Memory to memory mode

// ******************  Bit definition for DMA_CCR4 register  ******************
#define DMA_CCR4_EN                         0x0001            // Channel enable
#define DMA_CCR4_TCIE                       0x0002            // Transfer complete interrupt enable
#define DMA_CCR4_HTIE                       0x0004            // Half Transfer interrupt enable
#define DMA_CCR4_TEIE                       0x0008            // Transfer error interrupt enable
#define DMA_CCR4_DIR                        0x0010            // Data transfer direction
#define DMA_CCR4_CIRC                       0x0020            // Circular mode
#define DMA_CCR4_PINC                       0x0040            // Peripheral increment mode
#define DMA_CCR4_MINC                       0x0080            // Memory increment mode

#define DMA_CCR4_PSIZE                      0x0300            // PSIZE[1:0] bits (Peripheral size)
#define DMA_CCR4_PSIZE_0                    0x0100            // Bit 0
#define DMA_CCR4_PSIZE_1                    0x0200            // Bit 1

#define DMA_CCR4_MSIZE                      0x0C00            // MSIZE[1:0] bits (Memory size)
#define DMA_CCR4_MSIZE_0                    0x0400            // Bit 0
#define DMA_CCR4_MSIZE_1                    0x0800            // Bit 1

#define DMA_CCR4_PL                         0x3000            // PL[1:0] bits (Channel Priority level)
#define DMA_CCR4_PL_0                       0x1000            // Bit 0
#define DMA_CCR4_PL_1                       0x2000            // Bit 1

#define DMA_CCR4_MEM2MEM                    0x4000            // Memory to memory mode

//*****************  Bit definition for DMA_CCR5 register  ******************
#define DMA_CCR5_EN                         0x0001            // Channel enable
#define DMA_CCR5_TCIE                       0x0002            // Transfer complete interrupt enable
#define DMA_CCR5_HTIE                       0x0004            // Half Transfer interrupt enable
#define DMA_CCR5_TEIE                       0x0008            // Transfer error interrupt enable
#define DMA_CCR5_DIR                        0x0010            // Data transfer direction
#define DMA_CCR5_CIRC                       0x0020            // Circular mode
#define DMA_CCR5_PINC                       0x0040            // Peripheral increment mode
#define DMA_CCR5_MINC                       0x0080            // Memory increment mode

#define DMA_CCR5_PSIZE                      0x0300            // PSIZE[1:0] bits (Peripheral size)
#define DMA_CCR5_PSIZE_0                    0x0100            // Bit 0
#define DMA_CCR5_PSIZE_1                    0x0200            // Bit 1

#define DMA_CCR5_MSIZE                      0x0C00            // MSIZE[1:0] bits (Memory size)
#define DMA_CCR5_MSIZE_0                    0x0400            // Bit 0
#define DMA_CCR5_MSIZE_1                    0x0800            // Bit 1

#define DMA_CCR5_PL                         0x3000            // PL[1:0] bits (Channel Priority level)
#define DMA_CCR5_PL_0                       0x1000            // Bit 0
#define DMA_CCR5_PL_1                       0x2000            // Bit 1

#define DMA_CCR5_MEM2MEM                    0x4000            // Memory to memory mode enable

//******************  Bit definition for DMA_CCR6 register  ******************
#define DMA_CCR6_EN                         0x0001            // Channel enable
#define DMA_CCR6_TCIE                       0x0002            // Transfer complete interrupt enable
#define DMA_CCR6_HTIE                       0x0004            // Half Transfer interrupt enable
#define DMA_CCR6_TEIE                       0x0008            // Transfer error interrupt enable
#define DMA_CCR6_DIR                        0x0010            // Data transfer direction
#define DMA_CCR6_CIRC                       0x0020            // Circular mode
#define DMA_CCR6_PINC                       0x0040            // Peripheral increment mode
#define DMA_CCR6_MINC                       0x0080            // Memory increment mode

#define DMA_CCR6_PSIZE                      0x0300            // PSIZE[1:0] bits (Peripheral size)
#define DMA_CCR6_PSIZE_0                    0x0100            // Bit 0
#define DMA_CCR6_PSIZE_1                    0x0200            // Bit 1

#define DMA_CCR6_MSIZE                      0x0C00            // MSIZE[1:0] bits (Memory size)
#define DMA_CCR6_MSIZE_0                    0x0400            // Bit 0
#define DMA_CCR6_MSIZE_1                    0x0800            // Bit 1

#define DMA_CCR6_PL                         0x3000            // PL[1:0] bits (Channel Priority level)
#define DMA_CCR6_PL_0                       0x1000            // Bit 0
#define DMA_CCR6_PL_1                       0x2000            // Bit 1

#define DMA_CCR6_MEM2MEM                    0x4000            // Memory to memory mode

//******************  Bit definition for DMA_CCR7 register  ******************
#define DMA_CCR7_EN                         0x0001            // Channel enable
#define DMA_CCR7_TCIE                       0x0002            // Transfer complete interrupt enable
#define DMA_CCR7_HTIE                       0x0004            // Half Transfer interrupt enable
#define DMA_CCR7_TEIE                       0x0008            // Transfer error interrupt enable
#define DMA_CCR7_DIR                        0x0010            // Data transfer direction
#define DMA_CCR7_CIRC                       0x0020            // Circular mode
#define DMA_CCR7_PINC                       0x0040            // Peripheral increment mode
#define DMA_CCR7_MINC                       0x0080            // Memory increment mode

#define DMA_CCR7_PSIZE                      0x0300            // PSIZE[1:0] bits (Peripheral size)
#define DMA_CCR7_PSIZE_0                    0x0100            // Bit 0
#define DMA_CCR7_PSIZE_1                    0x0200            // Bit 1

#define DMA_CCR7_MSIZE                      0x0C00            // MSIZE[1:0] bits (Memory size)
#define DMA_CCR7_MSIZE_0                    0x0400            // Bit 0
#define DMA_CCR7_MSIZE_1                    0x0800            // Bit 1

#define DMA_CCR7_PL                         0x3000            // PL[1:0] bits (Channel Priority level)
#define DMA_CCR7_PL_0                       0x1000            // Bit 0
#define DMA_CCR7_PL_1                       0x2000            // Bit 1

#define DMA_CCR7_MEM2MEM                    0x4000            // Memory to memory mode enable

//*****************  Bit definition for DMA_CNDTR1 register  *****************
#define DMA_CNDTR1_NDT                      0xFFFF            // Number of data to Transfer

//*****************  Bit definition for DMA_CNDTR2 register  *****************
#define DMA_CNDTR2_NDT                      0xFFFF            // Number of data to Transfer

//*****************  Bit definition for DMA_CNDTR3 register  *****************
#define DMA_CNDTR3_NDT                      0xFFFF            // Number of data to Transfer

//*****************  Bit definition for DMA_CNDTR4 register  *****************
#define DMA_CNDTR4_NDT                      0xFFFF            // Number of data to Transfer

//*****************  Bit definition for DMA_CNDTR5 register  *****************
#define DMA_CNDTR5_NDT                      0xFFFF            // Number of data to Transfer

//*****************  Bit definition for DMA_CNDTR6 register  *****************
#define DMA_CNDTR6_NDT                      0xFFFF            // Number of data to Transfer

//*****************  Bit definition for DMA_CNDTR7 register  *****************
#define DMA_CNDTR7_NDT                      0xFFFF            // Number of data to Transfer

//*****************  Bit definition for DMA_CPAR1 register  ******************
#define DMA_CPAR1_PA                        0xFFFFFFFF        // Peripheral Address

//*****************  Bit definition for DMA_CPAR2 register  ******************
#define DMA_CPAR2_PA                        0xFFFFFFFF        // Peripheral Address

//*****************  Bit definition for DMA_CPAR3 register  ******************
#define DMA_CPAR3_PA                        0xFFFFFFFF        // Peripheral Address


//*****************  Bit definition for DMA_CPAR4 register  ******************
#define DMA_CPAR4_PA                        0xFFFFFFFF        // Peripheral Address

//*****************  Bit definition for DMA_CPAR5 register  ******************
#define DMA_CPAR5_PA                        0xFFFFFFFF        // Peripheral Address

//*****************  Bit definition for DMA_CPAR6 register  ******************
#define DMA_CPAR6_PA                        0xFFFFFFFF        // Peripheral Address


//*****************  Bit definition for DMA_CPAR7 register  ******************
#define DMA_CPAR7_PA                        0xFFFFFFFF        // Peripheral Address

//*****************  Bit definition for DMA_CMAR1 register  ******************
#define DMA_CMAR1_MA                        0xFFFFFFFF        // Memory Address

//*****************  Bit definition for DMA_CMAR2 register  ******************
#define DMA_CMAR2_MA                        0xFFFFFFFF        // Memory Address

//*****************  Bit definition for DMA_CMAR3 register  ******************
#define DMA_CMAR3_MA                        0xFFFFFFFF        // Memory Address


//*****************  Bit definition for DMA_CMAR4 register  ******************
#define DMA_CMAR4_MA                        0xFFFFFFFF        // Memory Address

//*****************  Bit definition for DMA_CMAR5 register  ******************
#define DMA_CMAR5_MA                        0xFFFFFFFF        // Memory Address

//*****************  Bit definition for DMA_CMAR6 register  ******************
#define DMA_CMAR6_MA                        0xFFFFFFFF        // Memory Address

//*****************  Bit definition for DMA_CMAR7 register  ******************
#define DMA_CMAR7_MA                        0xFFFFFFFF        // Memory Address
