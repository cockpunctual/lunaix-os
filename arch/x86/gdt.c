#include <lunaix/arch/gdt.h>
#include <stdint.h>

uint64_t seg_desp[5];
uint16_t gdt_limit = sizeof(seg_desp);

static void create_seg_descriptor(uint16_t idx, uint32_t base_addr, uint32_t limit, uint32_t flag)
{
    seg_desp[idx] = SEG_BASE_ADDR_M(base_addr)| flag | SEG_LIMIT_H(limit) |  SEG_BASE_ADDR_H(base_addr) ;
    seg_desp[idx] = seg_desp[idx] << 32;
    seg_desp[idx] |= SEG_LIMIT_L(limit) | SEG_BASE_ADDR_L(base_addr);
}

void init_gdt()
{
    create_seg_descriptor(0, 0, 0, 0); // null descriptor
    create_seg_descriptor(1, 0, 0xfffff, GDT_R0_CODE_PL0);
    create_seg_descriptor(2, 0, 0xfffff, GDT_R0_DATA_PL0);
    create_seg_descriptor(3, 0, 0xfffff, GDT_R3_CODE_PL0);
    create_seg_descriptor(4, 0, 0xfffff, GDT_R3_CODE_PL0);
}