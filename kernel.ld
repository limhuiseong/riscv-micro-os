/* entry point */
ENTRY(boot)

SECTIONS {
	/* base address */
    . = 0x80200000;

    .text :{
        KEEP(*(.text.boot));            // Keep the boot text section
        *(.text .text.*);               // Include all other text sections
    }

    .rodata : ALIGN(4) {
        *(.rodata .rodata.*);           // Include all read-only data sections
    }

    .data : ALIGN(4) {
        *(.data .data.*);               // Include all data sections
    }

    .bss : ALIGN(4) {
        __bss = .;                      // Start of BSS section
        *(.bss .bss.* .sbss .sbss.*);   // Include all BSS sections
        __bss_end = .;                  // End of BSS section
    }

    /* kernel stack */
    . = ALIGN(4);                       // 4B
    . += 128 * 1024;                    // 128KB
    __stack_top = .;                    // Top of the kernel stack

    . = ALIGN(4096);
    __free_ram = .;
    . += 64 * 1024 * 1024;
    __free_ram_end = .;
}