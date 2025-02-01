#include "trap.h"
#include "csr.h"
#include "panic.h"
#include "types.h"

void handle_trap(void)
{
    uint32_t scause = READ_CSR(scause);
    uint32_t stval = READ_CSR(stval);
    uint32_t user_pc = READ_CSR(sepc);

    PANIC("TRAP: scause=%x, stval=%x, sepc=%x\n", scause, stval, user_pc);
}