int syscall(int sysno, int arg0, int arg1, int arg2)
{
    register int a0 __asm__("a0") = arg0;
    register int a1 __asm__("a1") = arg1;
    register int a2 __asm__("a2") = arg2;
    register int a3 __asm__("a3") = sysno;

    __asm__ __volatile__("ecall" : "=r"(a0) : "r"(a0), "r"(a1), "r"(a2), "r"(a3) : "memory");

    return a0;
}