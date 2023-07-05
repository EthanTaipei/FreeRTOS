#include "cpu.h"

#if defined(gcc)
void __attribute__((naked))
CPUcpsie(void)
{
    __asm("    cpsie   i\n"
          "    dsb      \n"
          "    isb      \n"
          "    bx      lr\n");
}

void __attribute__((naked))
CPUcpsid(void)
{
    __asm("    cpsid   i\n"
          "    dsb      \n"
          "    isb      \n"
          "    bx      lr\n");
}

void __attribute__((naked))
CPUwfi(void)
{
    //
    // Wait for the next interrupt.
    //
    __asm("    dsb      \n"
          "    isb      \n"
          "    wfi      \n"
          "    bx      lr\n");
}
#endif

