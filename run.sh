#!/bin/bash
set -xue

CC=clang
CFLAGS="-std=c11 -O2 -g3 -Wall -Wextra --target=riscv32 -ffreestanding -nostdlib -I./include"

# user mode start
$CC $CFLAGS -Wl,-Tuser.ld -Wl,-Map=shell.map -o shell.elf shell.c user.c
OBJCOPY=llvm-objcopy
$OBJCOPY --set-section-flags .bss=alloc,contents -O binary shell.elf shell.bin
$OBJCOPY -Ibinary -Oelf32-littleriscv shell.bin shell.bin.o
# user mode end

$CC $CFLAGS -Wl,-Tkernel.ld -Wl,-Map=kernel.map -o kernel.elf \
    boot/boot.s \
    init/main.c \
    kernel/console.c kernel/sched.c kernel/trap.c kernel/arch/riscv/sbi.c \
    kernel/mm/page_alloc.c kernel/mm/page_table.c \
    lib/delay.c lib/string.c \
    shell.bin.o

QEMU=qemu-system-riscv32
$QEMU -machine virt -bios default -nographic -serial mon:stdio --no-reboot \
    -kernel kernel.elf