///////////////////////////////////////////////////////////////////////////////
// ONLY USE FOR KERNEL
///////////////////////////////////////////////////////////////////////////////

#ifndef RISCV_SBI_H
#define RISCV_SBI_H

struct sbiret
{
    long error;
    union {
        long value;
        unsigned long uvalue;
    };
};

struct sbiret sbi_call(long arg0, long arg1, long arg2, long arg3, long arg4, long arg5, long fid, long eid);

#endif