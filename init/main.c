#include "console.h"
#include "delay.h"
#include "panic.h"
#include "string.h"
#include "types.h"

extern char __bss[], __bss_end[], __stack_top[];

void main(void)
{
    memset(__bss, 0, (size_t)__bss_end - (size_t)__bss);

    char *booting_msg = "booting...\n";

    printf("\n\n");
    while (*booting_msg)
    {
        putchar(*booting_msg++);
        delay(50000000);
    }
    printf("RISCV MICRO OS 0.0.1\n");

    for (;;)
        __asm__ __volatile__("wfi");
}