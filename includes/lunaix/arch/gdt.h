#ifndef __GDT_H__
#define __GDT_H__

// Each define here is for a specific flag in the descriptor.
// Refer to the intel documentation for a description of what each one does.
#define SEG_DESCTYPE(x)  ((x) << 8) // Descriptor type (0 for system, 1 for code/data)
#define SEG_CODE_DATA(x) ((x) << 12) // 1 for data seg, 0 for system
#define SEG_DPL(x)       ((x) << 13) // privilage
#define SEG_PRES(x)      ((x) << 15) // Present
#define SEG_AVL(x)       ((x) << 20) // Avaliable (useless of operating system)
#define SEG_MODE(x)      ((x) << 21) // Mode (0 for 32bit, 1 for 64bit)
#define SEG_DB(x)        ((x) << 22) // D/B (0 for 16bit(use ip and sp register), 1 for 32bit(use eip and esp register))
#define SEG_GRAN(x)      ((x) << 23) // Granularity (0 for 1B - 1MB, 1 for 4KB - 4GB)
 
#define SEG_DATA_RD        0x00 // Read-Only
#define SEG_DATA_RDA       0x01 // Read-Only, accessed
#define SEG_DATA_RDWR      0x02 // Read/Write
#define SEG_DATA_RDWRA     0x03 // Read/Write, accessed
#define SEG_DATA_RDEXPD    0x04 // Read-Only, expand-down
#define SEG_DATA_RDEXPDA   0x05 // Read-Only, expand-down, accessed
#define SEG_DATA_RDWREXPD  0x06 // Read/Write, expand-down
#define SEG_DATA_RDWREXPDA 0x07 // Read/Write, expand-down, accessed
#define SEG_CODE_EX        0x08 // Execute-Only
#define SEG_CODE_EXA       0x09 // Execute-Only, accessed
#define SEG_CODE_EXRD      0x0A // Execute/Read
#define SEG_CODE_EXRDA     0x0B // Execute/Read, accessed
#define SEG_CODE_EXC       0x0C // Execute-Only, conforming
#define SEG_CODE_EXCA      0x0D // Execute-Only, conforming, accessed
#define SEG_CODE_EXRDC     0x0E // Execute/Read, conforming
#define SEG_CODE_EXRDCA    0x0F // Execute/Read, conforming, accessed

#define GDT_R3_CODE_PL0    SEG_DESCTYPE(SEG_CODE_EXRD) | SEG_CODE_DATA(1) | SEG_DPL(3) | \
                           SEG_PRES(1) | SEG_AVL(0) | SEG_MODE(0) | \
                           SEG_DB(1) | SEG_GRAN(1)


#define GDT_R3_DATA_PL0    SEG_DESCTYPE(SEG_DATA_RDWR) | SEG_CODE_DATA(1) | SEG_DPL(3) | \
                           SEG_PRES(1) | SEG_AVL(0) | SEG_MODE(0) | \
                           SEG_DB(1) | SEG_GRAN(1)

#define GDT_R0_CODE_PL0    SEG_DESCTYPE(SEG_CODE_EXRD) | SEG_CODE_DATA(1) | SEG_DPL(0) | \
                           SEG_PRES(1) | SEG_AVL(0) | SEG_MODE(0) | \
                           SEG_DB(1) | SEG_GRAN(1)


#define GDT_R0_DATA_PL0    SEG_DESCTYPE(SEG_DATA_RDWR) | SEG_CODE_DATA(1) | SEG_DPL(0) | \
                           SEG_PRES(1) | SEG_AVL(0) | SEG_MODE(0) | \
                           SEG_DB(1) | SEG_GRAN(1)

#define SEG_LIMIT_L(x)       ((x) & 0xffff)
#define SEG_LIMIT_H(x)       (((x) & 0xf0000) )
#define SEG_BASE_ADDR_L(x)   (((x) & 0xffff) << 16)
#define SEG_BASE_ADDR_M(x)   (((x) & 0x00ff0000) >> 16)
#define SEG_BASE_ADDR_H(x)   (((x) & 0xff000000))
void init_gdt();             
#endif