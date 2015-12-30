#pragma once

/* Part of this file is based on libopencm3 */

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

// Memory mapped IO pointer types
typedef volatile uint8_t* io8_t;
typedef volatile uint16_t* io16_t;
typedef volatile uint32_t* io32_t;
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


// intrinsics
#define wait_for_interrupt() __asm__("WFI")

#define __CLZ(div) __builtin_clz(div)
#define __CTZ(div) __builtin_ctz(div)
#define count_leading_zeros(div) __CLZ(div)

#define __REV(x) __builtin_bswap32(x)
#define reverse_bytes(x) __REV(x)

#define enable_interrupts() __asm__("CPSIE I")
#define disable_interrupts() __asm__("CPSID I");
#define enable_faults() __asm__("CPSIE F");
#define disable_faults() __asm__("CPSID F");

uint32_t __RBIT(uint32_t value); // defined in c file as inline asm
#define reverse_bits(v) __RBIT(v)


// i...iterator, m...mask, count...nr of bits
#define BitFieldLoop(i, m, count) for (uint32_t i = 0, m = 1; i < count; m <<= 1, i++)

// get a peripheral register pointer
#define P_REG(periph_base, reg_offs) ((io32_t) ((periph_base) + (reg_offs)))

#define BIT(x) (1 << (x))

#define BIT0  BIT(0)
#define BIT1  BIT(1)
#define BIT2  BIT(2)
#define BIT3  BIT(3)
#define BIT4  BIT(4)
#define BIT5  BIT(5)
#define BIT6  BIT(6)
#define BIT7  BIT(7)
#define BIT8  BIT(8)
#define BIT9  BIT(9)
#define BIT10 BIT(10)
#define BIT11 BIT(11)
#define BIT12 BIT(12)
#define BIT13 BIT(13)
#define BIT14 BIT(14)
#define BIT15 BIT(15)
#define BIT16 BIT(16)
#define BIT17 BIT(17)
#define BIT18 BIT(18)
#define BIT19 BIT(19)
#define BIT20 BIT(20)
#define BIT21 BIT(21)
#define BIT22 BIT(22)
#define BIT23 BIT(23)
#define BIT24 BIT(24)
#define BIT25 BIT(25)
#define BIT26 BIT(26)
#define BIT27 BIT(27)
#define BIT28 BIT(28)
#define BIT29 BIT(29)
#define BIT30 BIT(30)
#define BIT31 BIT(31)



// reg - MMIO32
// mask - uint32_t
// replacement - uint32_t (value that goes in place of mask, right-aligned)
//
// example: original value 0x12345678, patch_register(reg, 0xF00, 0xC) -> 0x12345C78
#define patch_register(reg, mask, replacement) (reg) = ((reg) & ~(mask)) | ((replacement) << __CTZ(mask))

//void patch_register(io32_t reg, uint32_t mask, uint32_t replacement);


#include "defs_base.h"
#include "defs_gpio.h"
#include "defs_rcc.h"
#include "defs_flash.h"
#include "defs_systick.h"
#include "defs_usart.h"
#include "defs_dma.h"
#include "defs_adc.h"
#include "defs_dac.h"
#include "defs_i2c.h"
#include "defs_spi.h"
#include "defs_timers.h"
#include "defs_nvic.h"
