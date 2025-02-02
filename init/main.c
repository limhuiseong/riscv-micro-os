#include "console.h"
#include "delay.h"
#include "panic.h"
#include "string.h"
#include "types.h"

extern char __bss[], __bss_end[], __stack_top[];

void start_kernel(void)
{
    memset(__bss, 0, (size_t)__bss_end - (size_t)__bss);

    char *boot_msg = "\n\nbooting...\nRISCV MICRO OS 0.0.1\n";

    while (*boot_msg)
    {
        putchar(*boot_msg++);
        delay(30000000);
    }

    for (;;)
        __asm__ __volatile__("wfi");
}