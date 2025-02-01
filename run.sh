#!/bin/bash
set -xue

CC=clang
CFLAGS="-std=c11 -O2 -g3 -Wall -Wextra --target=riscv32 -ffreestanding -nostdlib -I./include"
$CC $CFLAGS -Wl,-Tkernel.ld -Wl,-Map=kernel.map -o kernel.elf \
    boot/boot.s \
    init/main.c \
    kernel/console.c kernel/sched.c kernel/trap.c kernel/arch/riscv/sbi.c \
    kernel/mm/page_alloc.c kernel/mm/page_table.c \
    lib/delay.c lib/string.c

QEMU=qemu-system-riscv32
$QEMU -machine virt -bios default -nographic -serial mon:stdio --no-reboot \
    -kernel kernel.elf