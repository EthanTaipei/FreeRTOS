#******************************************************************************
#
# Makefile - Rules for building the driver library and examples.
#
# Copyright (c) 2005,2006 Luminary Micro, Inc.  All rights reserved.
#
# Software License Agreement
#
# Luminary Micro, Inc. (LMI) is supplying this software for use solely and
# exclusively on LMI's Stellaris Family of microcontroller products.
#
# The software is owned by LMI and/or its suppliers, and is protected under
# applicable copyright laws.  All rights are reserved.  Any use in violation
# of the foregoing restrictions may subject the user to criminal sanctions
# under applicable laws, as well as to civil liability for the breach of the
# terms and conditions of this license.
#
# THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
# OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
# MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
# LMI SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
# CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
#
#******************************************************************************

include makedefs

DEVICE = STM32F756xx

RTOS_SOURCE_DIR=../../Source
DEMO_SOURCE_DIR=../Common/Minimal
FULL_DEMO_DIR = Full_Demo
ST_LIB_DIR = ST_Library
SYSTEM_DIR = System

# -fno-builtin
CFLAGS+=-D $(DEVICE) -I . -I ${RTOS_SOURCE_DIR}/include -I ${RTOS_SOURCE_DIR}/portable/GCC/ARM_CM7 -I ../Common/include -I $(ST_LIB_DIR)/include -I CMSIS/Device/ST/STM32F7xx/Include -I CMSIS/Include -I $(RTOS_SOURCE_DIR)/portable/GCC/ARM_CM7/r0p1 -I $(FULL_DEMO_DIR) -I $(ST_LIB_DIR)

VPATH=${RTOS_SOURCE_DIR}:${RTOS_SOURCE_DIR}/portable/MemMang:${RTOS_SOURCE_DIR}/portable/GCC/ARM_CM7:${DEMO_SOURCE_DIR}:$(FULL_DEMO_DIR):$(RTOS_SOURCE_DIR)/portable/GCC/ARM_CM7/r0p1:$(ST_LIB_DIR):System_GCC

PORT_SRC = main.c heap_4.c port.c printf-stdarg.c stdlib.c
RTOS_SRC = event_groups.c list.c queue.c tasks.c timers.c
DEMO_SRC = BlockQ.c blocktim.c countsem.c death.c dynamic.c EventGroupsDemo.c \
	flop.c GenQTest.c integer.c IntQueue.c IntSemTest.c PollQ.c QPeek.c \
	QueueOverwrite.c QueueSet.c recmutex.c semtest.c TaskNotify.c TimerDemo.c
FULL_DEMO_SRC = IntQueueTimer.c main_full.c
ST_LIB_SRC = stm32f7xx_hal.c stm32f7xx_hal_cortex.c stm32f7xx_hal_dma.c \
	stm32f7xx_hal_rcc.c stm32f7xx_hal_tim.c stm32f7xx_hal_tim_ex.c stm32f7xx_hal_gpio.c 
SYSTEM_SRC = stm32f7xx_hal_msp.c stm32f7xx_it.c system_stm32f7xx.c 

OBJS = $(patsubst %.c,$(COMPILER)/%.o, $(PORT_SRC) $(RTOS_SRC) $(DEMO_SRC) $(FULL_DEMO_SRC) $(ST_LIB_SRC) $(SYSTEM_SRC))

INIT_OBJS= ${COMPILER}/startup_stm32f756xx.o

#
# The default rule, which causes init to be built.
#
all: ${COMPILER}           \
     ${COMPILER}/RTOSDemo.axf \
	 
#
# The rule to clean out all the build products
#

clean:
	@rm -rf ${COMPILER} ${wildcard *.bin} RTOSDemo.axf
	
#
# The rule to create the target directory
#
${COMPILER}:
	@mkdir ${COMPILER}

${COMPILER}/RTOSDemo.axf: ${INIT_OBJS} ${OBJS}
SCATTER_RTOSDemo=System_GCC/stm32f767.ld
ENTRY_RTOSDemo=Reset_Handler

#
#
# Include the automatically generated dependency files.
#
-include ${wildcard ${COMPILER}/*.d} __dummy__

