include ../../makedefs

SRCS = cpu.c adc.c comp.c flash.c gpio.c i2c.c interrupt.c qei.c ssi.c sysctl.c systick.c timer.c uart.c watchdog.c
OBJS = $(SRCS:.c=.o)
CFLAGS += -I. -DBUILD_ALL -Dgcc

libdriver.a: $(OBJS)
	$(AR) -cr $@ $^

clean:
	rm -f *.o *.a
