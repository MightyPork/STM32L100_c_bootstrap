DEFS		= -DSTM32L1

FP_FLAGS	?= -msoft-float
ARCH_FLAGS	= -mthumb -mcpu=cortex-m3 $(FP_FLAGS) -mfix-cortex-m3-ldrd

LDSCRIPT    = stm32l100rc.ld

################################################################

# Main file
BINARY      = main

INCL_DIRS   = . lib source
SRC_DIR     = source

STARTUP_SCRIPT = startup_stm32l100xc.s

OBJS += $(BINARY).o $(STARTUP_SCRIPT:.s=.o)
OBJS += lib/gpio.o
OBJS += lib/systick.o
OBJS += lib/usart.o

################################################################

JUNK            = *.o *.d *.elf *.bin *.hex *.srec *.list *.map *.dis *.disasm

###############################################################################
###############################################################################
###############################################################################

# Be silent per default, but 'make V=1' will show all compiler calls.
ifneq ($(V),1)
  Q     := @
  NULL  := 2>/dev/null
endif

###############################################################################
# Executables

PREFIX  ?= arm-none-eabi

CC      := $(PREFIX)-gcc
CXX     := $(PREFIX)-g++
LD      := $(PREFIX)-gcc
AR      := $(PREFIX)-ar
AS      := $(PREFIX)-as
OBJCOPY := $(PREFIX)-objcopy
OBJDUMP := $(PREFIX)-objdump
GDB     := $(PREFIX)-gdb
STFLASH := $(shell which st-flash)

###############################################################################

# For CMSIS compatibility
DEFS          += -D__weak="__attribute__((weak))" -D__packed="__attribute__((__packed__))"

###############################################################################
# C flags

CFLAGS      += -Os -ggdb -std=gnu99 -Wfatal-errors
CFLAGS      += -Wall -Wextra -Wshadow
CFLAGS      += -Wwrite-strings -Wold-style-definition -Winline -Wmissing-noreturn -Wstrict-prototypes
CFLAGS      += -Wredundant-decls -Wfloat-equal -Wsign-compare
CFLAGS      += -fno-common -ffunction-sections -fdata-sections -Wunused-function
CFLAGS      += -MD
CFLAGS      += $(INCL_DIRS:%=-I%) $(DEFS)

###############################################################################
# Linker flags

LDFLAGS     += --static -specs=nano.specs -lm -lc
#LDFLAGS     += -L$(OCM3_LIB_DIR)
LDFLAGS     += -T$(LDSCRIPT)
LDFLAGS     += -Wl,-Map=$(*).map
LDFLAGS     += -Wl,--gc-sections

###############################################################################
# Used libraries

LDLIBS		+= -lm
LDLIBS		+= -Wl,--start-group -lc -lgcc -lnosys -Wl,--end-group

###############################################################################
###############################################################################
###############################################################################

.SUFFIXES: .elf .bin .hex .srec .list .map .images
.SECONDEXPANSION:
.SECONDARY:

all: elf

ttyusb:
	gtkterm -s 115200 -p /dev/ttyUSB0

ttyacm:
	gtkterm -p /dev/ttyACM0

elf: $(BINARY).elf
bin: $(BINARY).bin
hex: $(BINARY).hex
srec: $(BINARY).srec
list: $(BINARY).list

images: $(BINARY).images
flash: $(BINARY).flash

dis: $(BINARY).elf
	$(Q)$(OBJDUMP) -dS $(BINARY).elf -j .text -j .isr_vector > $(BINARY).dis

%.images: %.bin %.hex %.srec %.list %.map

%.bin: %.elf
	$(Q)$(OBJCOPY) -Obinary $(*).elf $(*).bin

%.hex: %.elf
	$(Q)$(OBJCOPY) -Oihex $(*).elf $(*).hex

%.srec: %.elf
	$(Q)$(OBJCOPY) -Osrec $(*).elf $(*).srec

%.list: %.elf
	$(Q)$(OBJDUMP) -S $(*).elf > $(*).list

%.elf %.map: $(OBJS)
	$(Q)$(LD) $(LDFLAGS) $(ARCH_FLAGS) $(OBJS) $(LDLIBS) -o $(*).elf

%.o: %.c
	$(Q)$(CC) $(CFLAGS) $(ARCH_FLAGS) -o $(*).o -c $(*).c

%.o: %.s
	$(Q)$(CC) $(CFLAGS) $(ARCH_FLAGS) -o $(*).o -c $(*).s

clean:
	$(Q)$(RM) $(JUNK)
	$(Q)cd lib && $(RM) $(JUNK)

%.flash: %.bin
	@printf "  FLASH  $<\n"
	$(Q)$(STFLASH) write $(*).bin 0x8000000

.PHONY: images clean elf bin hex srec list dis ttyusb ttyacm

-include $(OBJS:.o=.d)
