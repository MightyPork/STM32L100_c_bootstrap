#include "common.h"

__attribute__((always_inline))
inline uint32_t __RBIT(uint32_t value)
{
	register uint32_t result;

	__asm__ volatile("rbit %0, %1" : "=r"(result) : "r"(value));
	return (result);
}


// implemented as a macro for more efficient code

/*
__attribute__((always_inline))
inline void patch_register(io32_t reg, uint32_t mask, uint32_t replacement)
{
	*reg = (*reg & ~mask) | (replacement << __CTZ(mask));
}
*/
