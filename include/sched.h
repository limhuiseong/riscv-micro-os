#ifndef SCHED_H
#define SCHED_H

#include "types.h"

#define PROCS_MAX 8
#define PROC_UNUSED 0
#define PROC_RUNNABLE 1

struct process
{
    int pid;
    int state;
    vaddr_t sp;
    uint8_t stack[8192];
    uint32_t *page_table;
};

struct process *create_process(uint32_t pc);
void __attribute__((naked)) switch_context(uint32_t *prev_sp, uint32_t *next_sp);
void yield(void);

#endif