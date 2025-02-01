ENTRY(boot)                             /* Entry point */

SECTIONS {
    . = 0x80200000;                     /* Base address */
    __kernel_base = .;
    
    .text :{
        KEEP(*(.text.boot));            /* Keep the boot text section */
        *(.text .text.*);               /* Include all other text sections */
    }

    .rodata : ALIGN(4) {
        *(.rodata .rodata.*);           /* Include all read-only data sections */
    }

    .data : ALIGN(4) {
        *(.data .data.*);               /* Include all data sections */
    }

    .bss : ALIGN(4) {
        __bss = .;                      /* Start of BSS section */
        *(.bss .bss.* .sbss .sbss.*);   /* Include all BSS sections */
        __bss_end = .;                  /* End of BSS section */
    }

    /* Kernel stack */
    . = ALIGN(4);                       /* Align to 4 bytes */
    . += 128 * 1024;                    /* 128KB */
    __stack_top = .;                    /* Top of the kernel stack */

    /* Memory allocation area */             
    . = ALIGN(4096);                    /* Align to 4096 bytes */
    __free_ram = .;                     /* Start of memory allocation area */
    . += 64 * 1024 * 1024;              /* 64MB */
    __free_ram_end = .;                 /* End of memory allocation area */
}