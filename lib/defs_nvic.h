#pragma once
#include "common.h"

// AUTHOR : Ondrej Hruska
// DATE   : 12/2015
// DESCR  : Control registers and bit masks for NVIC (interrupt vector controller)

//****************************************************************************
//*
//*                               REGISTERS
//*
//****************************************************************************

// system handler
#define SCS_SHPR(ipr_id)      MMIO8(SCS_BASE + 0xD18 + ipr_id)
#define NVIC_NMI_IRQ			-14
#define NVIC_HARD_FAULT_IRQ		-13
#define NVIC_MEM_MANAGE_IRQ		-12
#define NVIC_BUS_FAULT_IRQ		-11
#define NVIC_USAGE_FAULT_IRQ	-10
/* irq numbers -6 to -9 are reserved */
#define NVIC_SV_CALL_IRQ		-5
#define DEBUG_MONITOR_IRQ		-4
/* irq number -3 reserved */
#define NVIC_PENDSV_IRQ			-2
#define NVIC_SYSTICK_IRQ		-1



// NVIC

#define NVIC_ISER_BASE        (NVIC + 0x000)
#define NVIC_ISER0            MMIO32(NVIC + 0x000) // (R/W)  Interrupt Set Enable Register
#define NVIC_ISER1            MMIO32(NVIC + 0x004) // (R/W)  Interrupt Set Enable Register
#define NVIC_ISER2            MMIO32(NVIC + 0x008) // (R/W)  Interrupt Set Enable Register
#define NVIC_ISER3            MMIO32(NVIC + 0x00C) // (R/W)  Interrupt Set Enable Register
#define NVIC_ISER4            MMIO32(NVIC + 0x010) // (R/W)  Interrupt Set Enable Register
#define NVIC_ISER5            MMIO32(NVIC + 0x014) // (R/W)  Interrupt Set Enable Register
#define NVIC_ISER6            MMIO32(NVIC + 0x018) // (R/W)  Interrupt Set Enable Register
#define NVIC_ISER7            MMIO32(NVIC + 0x01C) // (R/W)  Interrupt Set Enable Register
#define NVIC_ISER8            MMIO32(NVIC + 0x020) // (R/W)  Interrupt Set Enable Register

#define NVIC_ICER_BASE        (NVIC + 0x080)
#define NVIC_ICER0            MMIO32(NVIC + 0x080) // (R/W)  Interrupt Clear Enable Register
#define NVIC_ICER1            MMIO32(NVIC + 0x084) // (R/W)  Interrupt Clear Enable Register
#define NVIC_ICER2            MMIO32(NVIC + 0x088) // (R/W)  Interrupt Clear Enable Register
#define NVIC_ICER3            MMIO32(NVIC + 0x08C) // (R/W)  Interrupt Clear Enable Register
#define NVIC_ICER4            MMIO32(NVIC + 0x090) // (R/W)  Interrupt Clear Enable Register
#define NVIC_ICER5            MMIO32(NVIC + 0x094) // (R/W)  Interrupt Clear Enable Register
#define NVIC_ICER6            MMIO32(NVIC + 0x098) // (R/W)  Interrupt Clear Enable Register
#define NVIC_ICER7            MMIO32(NVIC + 0x09C) // (R/W)  Interrupt Clear Enable Register

#define NVIC_ISPR_BASE        (NVIC + 0x100)
#define NVIC_ISPR0            MMIO32(NVIC + 0x100) // (R/W)  Interrupt Set Pending Register
#define NVIC_ISPR1            MMIO32(NVIC + 0x104) // (R/W)  Interrupt Set Pending Register
#define NVIC_ISPR2            MMIO32(NVIC + 0x108) // (R/W)  Interrupt Set Pending Register
#define NVIC_ISPR3            MMIO32(NVIC + 0x10C) // (R/W)  Interrupt Set Pending Register
#define NVIC_ISPR4            MMIO32(NVIC + 0x110) // (R/W)  Interrupt Set Pending Register
#define NVIC_ISPR5            MMIO32(NVIC + 0x114) // (R/W)  Interrupt Set Pending Register
#define NVIC_ISPR6            MMIO32(NVIC + 0x118) // (R/W)  Interrupt Set Pending Register
#define NVIC_ISPR7            MMIO32(NVIC + 0x11C) // (R/W)  Interrupt Set Pending Register

#define NVIC_ICPR_BASE        (NVIC + 0x180)
#define NVIC_ICPR0            MMIO32(NVIC + 0x180) // (R/W)  Interrupt Clear Pending Register
#define NVIC_ICPR1            MMIO32(NVIC + 0x184) // (R/W)  Interrupt Clear Pending Register
#define NVIC_ICPR2            MMIO32(NVIC + 0x188) // (R/W)  Interrupt Clear Pending Register
#define NVIC_ICPR3            MMIO32(NVIC + 0x18C) // (R/W)  Interrupt Clear Pending Register
#define NVIC_ICPR4            MMIO32(NVIC + 0x190) // (R/W)  Interrupt Clear Pending Register
#define NVIC_ICPR5            MMIO32(NVIC + 0x194) // (R/W)  Interrupt Clear Pending Register
#define NVIC_ICPR6            MMIO32(NVIC + 0x198) // (R/W)  Interrupt Clear Pending Register
#define NVIC_ICPR7            MMIO32(NVIC + 0x19C) // (R/W)  Interrupt Clear Pending Register

#define NVIC_IABR_BASE        (NVIC + 0x200)
#define NVIC_IABR0            MMIO32(NVIC + 0x200) // (R/W)  Interrupt Active bit Register
#define NVIC_IABR1            MMIO32(NVIC + 0x204) // (R/W)  Interrupt Active bit Register
#define NVIC_IABR2            MMIO32(NVIC + 0x208) // (R/W)  Interrupt Active bit Register
#define NVIC_IABR3            MMIO32(NVIC + 0x20C) // (R/W)  Interrupt Active bit Register
#define NVIC_IABR4            MMIO32(NVIC + 0x210) // (R/W)  Interrupt Active bit Register
#define NVIC_IABR5            MMIO32(NVIC + 0x214) // (R/W)  Interrupt Active bit Register
#define NVIC_IABR6            MMIO32(NVIC + 0x218) // (R/W)  Interrupt Active bit Register
#define NVIC_IABR7            MMIO32(NVIC + 0x21C) // (R/W)  Interrupt Active bit Register

#define NVIC_IPR_BASE         (NVIC + 0x300) // (R/W)  Interrupt Priority Register (8Bit wide) +240

#define NVIC_IPR(n)			  MMIO8(NVIC_IPR_BASE + (n))
#define NVIC_ISER(n)		  MMIO32(NVIC_ISER_BASE + (n*4))
#define NVIC_ICER(n)		  MMIO32(NVIC_ICER_BASE + (n*4))
#define NVIC_ISPR(n)		  MMIO32(NVIC_ISPR_BASE + (n*4))
#define NVIC_ICPR(n)		  MMIO32(NVIC_ICPR_BASE + (n*4))
#define NVIC_IABR(n)		  MMIO32(NVIC_IABR_BASE + (n*4))

#define NVIC_STIR             MMIO32(NVIC + 0xE00) // ( /W)  Software Trigger Interrupt Register



//****************************************************************************
//*
//*                       BIT MASKS AND DEFINITIONS
//*
//****************************************************************************


//*****************  Bit definition for NVIC_ISER register  ******************
#define NVIC_ISER_SETENA                    0xFFFFFFFF        // Interrupt set enable bits
#define NVIC_ISER_SETENA_0                  0x00000001        // bit 0
#define NVIC_ISER_SETENA_1                  0x00000002        // bit 1
#define NVIC_ISER_SETENA_2                  0x00000004        // bit 2
#define NVIC_ISER_SETENA_3                  0x00000008        // bit 3
#define NVIC_ISER_SETENA_4                  0x00000010        // bit 4
#define NVIC_ISER_SETENA_5                  0x00000020        // bit 5
#define NVIC_ISER_SETENA_6                  0x00000040        // bit 6
#define NVIC_ISER_SETENA_7                  0x00000080        // bit 7
#define NVIC_ISER_SETENA_8                  0x00000100        // bit 8
#define NVIC_ISER_SETENA_9                  0x00000200        // bit 9
#define NVIC_ISER_SETENA_10                 0x00000400        // bit 10
#define NVIC_ISER_SETENA_11                 0x00000800        // bit 11
#define NVIC_ISER_SETENA_12                 0x00001000        // bit 12
#define NVIC_ISER_SETENA_13                 0x00002000        // bit 13
#define NVIC_ISER_SETENA_14                 0x00004000        // bit 14
#define NVIC_ISER_SETENA_15                 0x00008000        // bit 15
#define NVIC_ISER_SETENA_16                 0x00010000        // bit 16
#define NVIC_ISER_SETENA_17                 0x00020000        // bit 17
#define NVIC_ISER_SETENA_18                 0x00040000        // bit 18
#define NVIC_ISER_SETENA_19                 0x00080000        // bit 19
#define NVIC_ISER_SETENA_20                 0x00100000        // bit 20
#define NVIC_ISER_SETENA_21                 0x00200000        // bit 21
#define NVIC_ISER_SETENA_22                 0x00400000        // bit 22
#define NVIC_ISER_SETENA_23                 0x00800000        // bit 23
#define NVIC_ISER_SETENA_24                 0x01000000        // bit 24
#define NVIC_ISER_SETENA_25                 0x02000000        // bit 25
#define NVIC_ISER_SETENA_26                 0x04000000        // bit 26
#define NVIC_ISER_SETENA_27                 0x08000000        // bit 27
#define NVIC_ISER_SETENA_28                 0x10000000        // bit 28
#define NVIC_ISER_SETENA_29                 0x20000000        // bit 29
#define NVIC_ISER_SETENA_30                 0x40000000        // bit 30
#define NVIC_ISER_SETENA_31                 0x80000000        // bit 31

//*****************  Bit definition for NVIC_ICER register  ******************
#define NVIC_ICER_CLRENA                   0xFFFFFFFF        // Interrupt clear-enable bits
#define NVIC_ICER_CLRENA_0                  0x00000001        // bit 0
#define NVIC_ICER_CLRENA_1                  0x00000002        // bit 1
#define NVIC_ICER_CLRENA_2                  0x00000004        // bit 2
#define NVIC_ICER_CLRENA_3                  0x00000008        // bit 3
#define NVIC_ICER_CLRENA_4                  0x00000010        // bit 4
#define NVIC_ICER_CLRENA_5                  0x00000020        // bit 5
#define NVIC_ICER_CLRENA_6                  0x00000040        // bit 6
#define NVIC_ICER_CLRENA_7                  0x00000080        // bit 7
#define NVIC_ICER_CLRENA_8                  0x00000100        // bit 8
#define NVIC_ICER_CLRENA_9                  0x00000200        // bit 9
#define NVIC_ICER_CLRENA_10                 0x00000400        // bit 10
#define NVIC_ICER_CLRENA_11                 0x00000800        // bit 11
#define NVIC_ICER_CLRENA_12                 0x00001000        // bit 12
#define NVIC_ICER_CLRENA_13                 0x00002000        // bit 13
#define NVIC_ICER_CLRENA_14                 0x00004000        // bit 14
#define NVIC_ICER_CLRENA_15                 0x00008000        // bit 15
#define NVIC_ICER_CLRENA_16                 0x00010000        // bit 16
#define NVIC_ICER_CLRENA_17                 0x00020000        // bit 17
#define NVIC_ICER_CLRENA_18                 0x00040000        // bit 18
#define NVIC_ICER_CLRENA_19                 0x00080000        // bit 19
#define NVIC_ICER_CLRENA_20                 0x00100000        // bit 20
#define NVIC_ICER_CLRENA_21                 0x00200000        // bit 21
#define NVIC_ICER_CLRENA_22                 0x00400000        // bit 22
#define NVIC_ICER_CLRENA_23                 0x00800000        // bit 23
#define NVIC_ICER_CLRENA_24                 0x01000000        // bit 24
#define NVIC_ICER_CLRENA_25                 0x02000000        // bit 25
#define NVIC_ICER_CLRENA_26                 0x04000000        // bit 26
#define NVIC_ICER_CLRENA_27                 0x08000000        // bit 27
#define NVIC_ICER_CLRENA_28                 0x10000000        // bit 28
#define NVIC_ICER_CLRENA_29                 0x20000000        // bit 29
#define NVIC_ICER_CLRENA_30                 0x40000000        // bit 30
#define NVIC_ICER_CLRENA_31                 0x80000000        // bit 31

//*****************  Bit definition for NVIC_ISPR register  ******************
#define NVIC_ISPR_SETPEND                   0xFFFFFFFF        // Interrupt set-pending bits
#define NVIC_ISPR_SETPEND_0                 0x00000001        // bit 0
#define NVIC_ISPR_SETPEND_1                 0x00000002        // bit 1
#define NVIC_ISPR_SETPEND_2                 0x00000004        // bit 2
#define NVIC_ISPR_SETPEND_3                 0x00000008        // bit 3
#define NVIC_ISPR_SETPEND_4                 0x00000010        // bit 4
#define NVIC_ISPR_SETPEND_5                 0x00000020        // bit 5
#define NVIC_ISPR_SETPEND_6                 0x00000040        // bit 6
#define NVIC_ISPR_SETPEND_7                 0x00000080        // bit 7
#define NVIC_ISPR_SETPEND_8                 0x00000100        // bit 8
#define NVIC_ISPR_SETPEND_9                 0x00000200        // bit 9
#define NVIC_ISPR_SETPEND_10                0x00000400        // bit 10
#define NVIC_ISPR_SETPEND_11                0x00000800        // bit 11
#define NVIC_ISPR_SETPEND_12                0x00001000        // bit 12
#define NVIC_ISPR_SETPEND_13                0x00002000        // bit 13
#define NVIC_ISPR_SETPEND_14                0x00004000        // bit 14
#define NVIC_ISPR_SETPEND_15                0x00008000        // bit 15
#define NVIC_ISPR_SETPEND_16                0x00010000        // bit 16
#define NVIC_ISPR_SETPEND_17                0x00020000        // bit 17
#define NVIC_ISPR_SETPEND_18                0x00040000        // bit 18
#define NVIC_ISPR_SETPEND_19                0x00080000        // bit 19
#define NVIC_ISPR_SETPEND_20                0x00100000        // bit 20
#define NVIC_ISPR_SETPEND_21                0x00200000        // bit 21
#define NVIC_ISPR_SETPEND_22                0x00400000        // bit 22
#define NVIC_ISPR_SETPEND_23                0x00800000        // bit 23
#define NVIC_ISPR_SETPEND_24                0x01000000        // bit 24
#define NVIC_ISPR_SETPEND_25                0x02000000        // bit 25
#define NVIC_ISPR_SETPEND_26                0x04000000        // bit 26
#define NVIC_ISPR_SETPEND_27                0x08000000        // bit 27
#define NVIC_ISPR_SETPEND_28                0x10000000        // bit 28
#define NVIC_ISPR_SETPEND_29                0x20000000        // bit 29
#define NVIC_ISPR_SETPEND_30                0x40000000        // bit 30
#define NVIC_ISPR_SETPEND_31                0x80000000        // bit 31

//*****************  Bit definition for NVIC_ICPR register  ******************
#define NVIC_ICPR_CLRPEND                   0xFFFFFFFF        // Interrupt clear-pending bits
#define NVIC_ICPR_CLRPEND_0                 0x00000001        // bit 0
#define NVIC_ICPR_CLRPEND_1                 0x00000002        // bit 1
#define NVIC_ICPR_CLRPEND_2                 0x00000004        // bit 2
#define NVIC_ICPR_CLRPEND_3                 0x00000008        // bit 3
#define NVIC_ICPR_CLRPEND_4                 0x00000010        // bit 4
#define NVIC_ICPR_CLRPEND_5                 0x00000020        // bit 5
#define NVIC_ICPR_CLRPEND_6                 0x00000040        // bit 6
#define NVIC_ICPR_CLRPEND_7                 0x00000080        // bit 7
#define NVIC_ICPR_CLRPEND_8                 0x00000100        // bit 8
#define NVIC_ICPR_CLRPEND_9                 0x00000200        // bit 9
#define NVIC_ICPR_CLRPEND_10                0x00000400        // bit 10
#define NVIC_ICPR_CLRPEND_11                0x00000800        // bit 11
#define NVIC_ICPR_CLRPEND_12                0x00001000        // bit 12
#define NVIC_ICPR_CLRPEND_13                0x00002000        // bit 13
#define NVIC_ICPR_CLRPEND_14                0x00004000        // bit 14
#define NVIC_ICPR_CLRPEND_15                0x00008000        // bit 15
#define NVIC_ICPR_CLRPEND_16                0x00010000        // bit 16
#define NVIC_ICPR_CLRPEND_17                0x00020000        // bit 17
#define NVIC_ICPR_CLRPEND_18                0x00040000        // bit 18
#define NVIC_ICPR_CLRPEND_19                0x00080000        // bit 19
#define NVIC_ICPR_CLRPEND_20                0x00100000        // bit 20
#define NVIC_ICPR_CLRPEND_21                0x00200000        // bit 21
#define NVIC_ICPR_CLRPEND_22                0x00400000        // bit 22
#define NVIC_ICPR_CLRPEND_23                0x00800000        // bit 23
#define NVIC_ICPR_CLRPEND_24                0x01000000        // bit 24
#define NVIC_ICPR_CLRPEND_25                0x02000000        // bit 25
#define NVIC_ICPR_CLRPEND_26                0x04000000        // bit 26
#define NVIC_ICPR_CLRPEND_27                0x08000000        // bit 27
#define NVIC_ICPR_CLRPEND_28                0x10000000        // bit 28
#define NVIC_ICPR_CLRPEND_29                0x20000000        // bit 29
#define NVIC_ICPR_CLRPEND_30                0x40000000        // bit 30
#define NVIC_ICPR_CLRPEND_31                0x80000000        // bit 31

//*****************  Bit definition for NVIC_IABR register  ******************
#define NVIC_IABR_ACTIVE                    0xFFFFFFFF        // Interrupt active flags
#define NVIC_IABR_ACTIVE_0                  0x00000001        // bit 0
#define NVIC_IABR_ACTIVE_1                  0x00000002        // bit 1
#define NVIC_IABR_ACTIVE_2                  0x00000004        // bit 2
#define NVIC_IABR_ACTIVE_3                  0x00000008        // bit 3
#define NVIC_IABR_ACTIVE_4                  0x00000010        // bit 4
#define NVIC_IABR_ACTIVE_5                  0x00000020        // bit 5
#define NVIC_IABR_ACTIVE_6                  0x00000040        // bit 6
#define NVIC_IABR_ACTIVE_7                  0x00000080        // bit 7
#define NVIC_IABR_ACTIVE_8                  0x00000100        // bit 8
#define NVIC_IABR_ACTIVE_9                  0x00000200        // bit 9
#define NVIC_IABR_ACTIVE_10                 0x00000400        // bit 10
#define NVIC_IABR_ACTIVE_11                 0x00000800        // bit 11
#define NVIC_IABR_ACTIVE_12                 0x00001000        // bit 12
#define NVIC_IABR_ACTIVE_13                 0x00002000        // bit 13
#define NVIC_IABR_ACTIVE_14                 0x00004000        // bit 14
#define NVIC_IABR_ACTIVE_15                 0x00008000        // bit 15
#define NVIC_IABR_ACTIVE_16                 0x00010000        // bit 16
#define NVIC_IABR_ACTIVE_17                 0x00020000        // bit 17
#define NVIC_IABR_ACTIVE_18                 0x00040000        // bit 18
#define NVIC_IABR_ACTIVE_19                 0x00080000        // bit 19
#define NVIC_IABR_ACTIVE_20                 0x00100000        // bit 20
#define NVIC_IABR_ACTIVE_21                 0x00200000        // bit 21
#define NVIC_IABR_ACTIVE_22                 0x00400000        // bit 22
#define NVIC_IABR_ACTIVE_23                 0x00800000        // bit 23
#define NVIC_IABR_ACTIVE_24                 0x01000000        // bit 24
#define NVIC_IABR_ACTIVE_25                 0x02000000        // bit 25
#define NVIC_IABR_ACTIVE_26                 0x04000000        // bit 26
#define NVIC_IABR_ACTIVE_27                 0x08000000        // bit 27
#define NVIC_IABR_ACTIVE_28                 0x10000000        // bit 28
#define NVIC_IABR_ACTIVE_29                 0x20000000        // bit 29
#define NVIC_IABR_ACTIVE_30                 0x40000000        // bit 30
#define NVIC_IABR_ACTIVE_31                 0x80000000        // bit 31

//*****************  Bit definition for NVIC_PRI0 register  ******************
#define NVIC_IPR0_PRI_0                     0x000000FF        // Priority of interrupt 0
#define NVIC_IPR0_PRI_1                     0x0000FF00        // Priority of interrupt 1
#define NVIC_IPR0_PRI_2                     0x00FF0000        // Priority of interrupt 2
#define NVIC_IPR0_PRI_3                     0xFF000000        // Priority of interrupt 3

//*****************  Bit definition for NVIC_PRI1 register  ******************
#define NVIC_IPR1_PRI_4                     0x000000FF        // Priority of interrupt 4
#define NVIC_IPR1_PRI_5                     0x0000FF00        // Priority of interrupt 5
#define NVIC_IPR1_PRI_6                     0x00FF0000        // Priority of interrupt 6
#define NVIC_IPR1_PRI_7                     0xFF000000        // Priority of interrupt 7

//*****************  Bit definition for NVIC_PRI2 register  ******************
#define NVIC_IPR2_PRI_8                     0x000000FF        // Priority of interrupt 8
#define NVIC_IPR2_PRI_9                     0x0000FF00        // Priority of interrupt 9
#define NVIC_IPR2_PRI_10                    0x00FF0000        // Priority of interrupt 10
#define NVIC_IPR2_PRI_11                    0xFF000000        // Priority of interrupt 11

//*****************  Bit definition for NVIC_PRI3 register  ******************
#define NVIC_IPR3_PRI_12                    0x000000FF        // Priority of interrupt 12
#define NVIC_IPR3_PRI_13                    0x0000FF00        // Priority of interrupt 13
#define NVIC_IPR3_PRI_14                    0x00FF0000        // Priority of interrupt 14
#define NVIC_IPR3_PRI_15                    0xFF000000        // Priority of interrupt 15

//*****************  Bit definition for NVIC_PRI4 register  ******************
#define NVIC_IPR4_PRI_16                    0x000000FF        // Priority of interrupt 16
#define NVIC_IPR4_PRI_17                    0x0000FF00        // Priority of interrupt 17
#define NVIC_IPR4_PRI_18                    0x00FF0000        // Priority of interrupt 18
#define NVIC_IPR4_PRI_19                    0xFF000000        // Priority of interrupt 19

//*****************  Bit definition for NVIC_PRI5 register  ******************
#define NVIC_IPR5_PRI_20                    0x000000FF        // Priority of interrupt 20
#define NVIC_IPR5_PRI_21                    0x0000FF00        // Priority of interrupt 21
#define NVIC_IPR5_PRI_22                    0x00FF0000        // Priority of interrupt 22
#define NVIC_IPR5_PRI_23                    0xFF000000        // Priority of interrupt 23

//*****************  Bit definition for NVIC_PRI6 register  ******************
#define NVIC_IPR6_PRI_24                    0x000000FF        // Priority of interrupt 24
#define NVIC_IPR6_PRI_25                    0x0000FF00        // Priority of interrupt 25
#define NVIC_IPR6_PRI_26                    0x00FF0000        // Priority of interrupt 26
#define NVIC_IPR6_PRI_27                    0xFF000000        // Priority of interrupt 27

//*****************  Bit definition for NVIC_PRI7 register  ******************
#define NVIC_IPR7_PRI_28                    0x000000FF        // Priority of interrupt 28
#define NVIC_IPR7_PRI_29                    0x0000FF00        // Priority of interrupt 29
#define NVIC_IPR7_PRI_30                    0x00FF0000        // Priority of interrupt 30
#define NVIC_IPR7_PRI_31                    0xFF000000        // Priority of interrupt 31


//---------- definitions for L100 ---------------
// copied from libopencm3

#define NVIC_WWDG_IRQ 0
#define NVIC_PVD_IRQ 1
#define NVIC_TAMPER_STAMP_IRQ 2
#define NVIC_RTC_WKUP_IRQ 3
#define NVIC_FLASH_IRQ 4
#define NVIC_RCC_IRQ 5
#define NVIC_EXTI0_IRQ 6
#define NVIC_EXTI1_IRQ 7
#define NVIC_EXTI2_IRQ 8
#define NVIC_EXTI3_IRQ 9
#define NVIC_EXTI4_IRQ 10
#define NVIC_DMA1_CHANNEL1_IRQ 11
#define NVIC_DMA1_CHANNEL2_IRQ 12
#define NVIC_DMA1_CHANNEL3_IRQ 13
#define NVIC_DMA1_CHANNEL4_IRQ 14
#define NVIC_DMA1_CHANNEL5_IRQ 15
#define NVIC_DMA1_CHANNEL6_IRQ 16
#define NVIC_DMA1_CHANNEL7_IRQ 17
#define NVIC_ADC1_IRQ 18
#define NVIC_USB_HP_IRQ 19
#define NVIC_USB_LP_IRQ 20
#define NVIC_DAC_IRQ 21
#define NVIC_COMP_IRQ 22
#define NVIC_EXTI9_5_IRQ 23
#define NVIC_LCD_IRQ 24
#define NVIC_TIM9_IRQ 25
#define NVIC_TIM10_IRQ 26
#define NVIC_TIM11_IRQ 27
#define NVIC_TIM2_IRQ 28
#define NVIC_TIM3_IRQ 29
#define NVIC_TIM4_IRQ 30
#define NVIC_I2C1_EV_IRQ 31
#define NVIC_I2C1_ER_IRQ 32
#define NVIC_I2C2_EV_IRQ 33
#define NVIC_I2C2_ER_IRQ 34
#define NVIC_SPI1_IRQ 35
#define NVIC_SPI2_IRQ 36
#define NVIC_USART1_IRQ 37
#define NVIC_USART2_IRQ 38
#define NVIC_USART3_IRQ 39
#define NVIC_EXTI15_10_IRQ 40
#define NVIC_RTC_ALARM_IRQ 41
#define NVIC_USB_FS_WAKEUP_IRQ 42
#define NVIC_TIM6_IRQ 43
#define NVIC_TIM7_IRQ 44
#define NVIC_SDIO_IRQ 45
#define NVIC_TIM5_IRQ 46
#define NVIC_SPI3_IRQ 47
#define NVIC_UART4_IRQ 48
#define NVIC_UART5_IRQ 49
#define NVIC_DMA2_CH1_IRQ 50
#define NVIC_DMA2_CH2_IRQ 51
#define NVIC_DMA2_CH3_IRQ 52
#define NVIC_DMA2_CH4_IRQ 53
#define NVIC_DMA2_CH5_IRQ 54
#define NVIC_AES_IRQ 55
#define NVIC_COMP_ACQ_IRQ 56

#define NVIC_IRQ_COUNT 57
