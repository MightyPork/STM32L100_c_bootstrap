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
    stm32l100rc.ld

SOURCES += \
    main.c \
    lib/gpio.c \
    lib/systick.c \
    lib/usart.c

HEADERS += \
    lib/common.h \
    lib/defs_base.h \
    lib/defs_flash.h \
    lib/defs_gpio.h \
    lib/defs_rcc.h \
    lib/gpio.h \
    lib/defs_systick.h \
    lib/systick.h \
    lib/defs_usart.h \
    lib/usart.h

