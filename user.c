extern char __stack_top[];

__attribute__((noreturn)) void exit(void)
{
    for (;;)
        ;
}

void putchar(char c)
{
    /* TODO */
}

__attribute__((section(".text.start"))) __attribute__((naked)) void start(void)
{
    __asm__ __volatile__("mv sp, %[stack_top] \n"
                         "call main           \n"
                         "call exit           \n" ::[stack_top] "r"(__stack_top));
}