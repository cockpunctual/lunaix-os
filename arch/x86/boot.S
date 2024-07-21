#include "multiboot.h"

.section .multiboot
    .long MB_MAGIC
    .long MB_ALIGNED_4K_MEM_MAP
    .long CHECKSUM(MB_ALIGNED_4K_MEM_MAP)

.section .bss
    /* According to System V ABI, the stack must be aligned at 16 bytes boundary */
    .align 16
    stack_bottom:
        .skip 16318, 0
    stack_top:

.section .text
    .global start_
    .type start_, @function
    start_:
        movl $stack_top, %esp
        /* 
            TODO: kernel init
                1. Load GDT
                2. Load IDT
                3. Enable paging
        */
        call _kernel_init
        /*
            使用lgdt时，需要在gdt地址处存放：
                gdt limit（存放在低地址）
                gdt address（存放在高地址） 
         */
        subl $6, %esp
        movl $seg_desp, 2(%esp)
        movw gdt_limit, %ax
        movw %ax, (%esp)
        lgdt (%esp)
        addl $6, %esp
        /* 初始化各个段选择子（segment selector） */
        movw $0x10, %cx
        movw %cx, %es
        movw %cx, %ds
        movw %cx, %fs
        movw %cx, %gs
        movw %cx, %ss

        pushw $0x8 /* 0x8为代码段选择子 */ 
        pushl $after_init_gdt
        retf
    after_init_gdt:
        pushl %ebx
        call _kernel_main

        cli
    j_:
        hlt
        jmp j_