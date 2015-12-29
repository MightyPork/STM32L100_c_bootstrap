#pragma once

/* Part of this file is based on libopencm3 */

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>


typedef volatile uint8_t* io8_t;
typedef volatile uint16_t* io16_t;
typedef volatile uint32_t* io32_t ;
typedef volatile uint64_t* io64_t;

/* Generic memory-mapped I/O accessor functions */
#define MMIO8(addr)     (*(io8_t)(addr))
#define MMIO16(addr)    (*(io16_t)(addr))
#define MMIO32(addr)    (*(io32_t)(addr))
#define MMIO64(addr)    (*(io64_t)(addr))

/* Generic bit-band I/O accessor functions */
#define BBIO_SRAM(addr, bit) \
	MMIO32((((uint32_t)addr) & 0x0FFFFF) * 32 + 0x22000000 + (bit) * 4)

#define BBIO_PERIPH(addr, bit) \
	MMIO32((((uint32_t)addr) & 0x0FFFFF) * 32 + 0x42000000 + (bit) * 4)

// i...iterator, m...mask, count...nr of bits
#define BitFieldLoop(i, m, count) for (uint32_t i = 0, m = 1; i < count; m <<= 1, i++)

#define P_REG(periph_base, reg_offs) ((io32_t) ((periph_base) + (reg_offs)))

#define BIT(x) (1 << (x))

#define BIT0  (1<<0)
#define BIT1  (1<<1)
#define BIT2  (1<<2)
#define BIT3  (1<<3)
#define BIT4  (1<<4)
#define BIT5  (1<<5)
#define BIT6  (1<<6)
#define BIT7  (1<<7)
#define BIT8  (1<<8)
#define BIT9  (1<<9)
#define BIT10 (1<<10)
#define BIT11 (1<<11)
#define BIT12 (1<<12)
#define BIT13 (1<<13)
#define BIT14 (1<<14)
#define BIT15 (1<<15)
#define BIT16 (1<<16)
#define BIT17 (1<<17)
#define BIT18 (1<<18)
#define BIT19 (1<<19)
#define BIT20 (1<<20)
#define BIT21 (1<<21)
#define BIT22 (1<<22)
#define BIT23 (1<<23)
#define BIT24 (1<<24)
#define BIT25 (1<<25)
#define BIT26 (1<<26)
#define BIT27 (1<<27)
#define BIT28 (1<<28)
#define BIT29 (1<<29)
#define BIT30 (1<<30)
#define BIT31 (1<<31)



#include "defs_base.h"
#include "defs_gpio.h"
#include "defs_rcc.h"
#include "defs_flash.h"
#include "defs_systick.h"
#include "defs_usart.h"
