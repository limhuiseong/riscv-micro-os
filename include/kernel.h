#ifndef KERNEL_H
#define KERNEL_H

#include "common.h"

#define READ_CSR(reg)                                                                                                  \
    ({                                                                                                                 \
        unsigned long __tmp;                                                                                           \
        __asm__ __volatile__("csrr %0, " #reg : "=r"(__tmp));                                                          \
        __tmp;                                                                                                         \
    })

#define WRITE_CSR(reg, value)                                                                                          \
    do                                                                                                                 \
    {                                                                                                                  \
        uint32_t __tmp = (value);                                                                                      \
        __asm__ __volatile__("csrw " #reg ", %0" ::"r"(__tmp));                                                        \
    } while (0)

#define PANIC(fmt, ...)                                                                                                \
    do                                                                                                                 \
    {                                                                                                                  \
        printf("PANIC: %s:%d: " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__);                                          \
        while (1)                                                                                                      \
        {                                                                                                              \
        }                                                                                                              \
    } while (0)

#define PROCS_MAX 8
#define PROC_UNUSED 0
#define PROC_RUNNABLE 1

struct trap_frame
{
    uint32_t ra;
    uint32_t gp;
    uint32_t tp;
    uint32_t t0;
    uint32_t t1;
    uint32_t t2;
    uint32_t t3;
    uint32_t t4;
    uint32_t t5;
    uint32_t t6;
    uint32_t a0;
    uint32_t a1;
    uint32_t a2;
    uint32_t a3;
    uint32_t a4;
    uint32_t a5;
    uint32_t a6;
    uint32_t a7;
    uint32_t s0;
    uint32_t s1;
    uint32_t s2;
    uint32_t s3;
    uint32_t s4;
    uint32_t s5;
    uint32_t s6;
    uint32_t s7;
    uint32_t s8;
    uint32_t s9;
    uint32_t s10;
    uint32_t s11;
    uint32_t sp;
} __attribute__((packed));

struct sbiret
{
    long error;
    union {
        long value;
        unsigned long uvalue;
    };
};

struct sbiret sbi_call(long arg0, long arg1, long arg2, long arg3, long arg4, long arg5, long fid, long eid);

struct process
{
    int pid;
    int state;
    vaddr_t sp;
    uint8_t stack[8192];
};

__attribute__((section(".text.boot"))) __attribute__((naked)) void boot(void);

void kernel_main(void);

__attribute__((naked)) __attribute__((aligned(4))) void kernel_entry(void);

void handle_trap(void);

paddr_t alloc_pages(uint32_t n);

__attribute__((naked)) void switch_context(uint32_t *prev_sp, uint32_t *next_sp);

struct process *create_process(uint32_t pc);

void delay(void);

#endif