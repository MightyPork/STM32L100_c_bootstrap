TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += \
	lib \
	/usr/arm-none-eabi/include

DEFINES += STM32F3 __ARM_ARCH_7M__ ARM_MATH_CM4


DISTFILES += \
	Makefile \
    style.astylerc \
    startup_stm32l100xc.s \
    stm32l100rc.ld \
    .gitignore

SOURCES += \
    main.c \
    lib/gpio.c \
    lib/usart.c \
    init.c \
    timebase.c \
    gpio.c \
    usart.c \
    utils/gpio.c \
    utils/timebase.c \
    utils/usart.c \
    utils/debounce.c \
    blink.c \
    lib/common.c \
    utils/nvic.c

HEADERS += \
    lib/common.h \
    lib/defs_base.h \
    lib/defs_flash.h \
    lib/defs_gpio.h \
    lib/defs_rcc.h \
    lib/defs_systick.h \
    lib/defs_usart.h \
    lib/usart.h \
    init.h \
    timebase.h \
    gpio.h \
    usart.h \
    utils/gpio.h \
    utils/timebase.h \
    utils/usart.h \
    utils/debounce.h \
    blink.h \
    lib/defs_adc.h \
    lib/defs_dac.h \
    lib/defs_dma.h \
    lib/defs_i2c.h \
    lib/defs_spi.h \
    lib/defs_timers.h \
    lib/defs_nvic.h \
    utils/nvic.h

