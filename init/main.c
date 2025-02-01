#include "console.h"
#include "panic.h"
#include "string.h"
#include "types.h"

extern char __bss[], __bss_end[], __stack_top[];

void main(void)
{
    memset(__bss, 0, (size_t)__bss_end - (size_t)__bss);

    printf("\n\nbooted!\n\n");

    for (;;)
        __asm__ __volatile__("wfi");
}