.section .text.boot
.global boot

boot:
    la sp, __stack_top
    j main