#include <libc/string.h>
#include <stdint.h>

void* memcpy(void* dst, const void* src, size_t len)
{
    uint8_t* dst_ptr = (uint8_t*)dst;
    const uint8_t* src_ptr = (const uint8_t*)src;
    for (size_t i = 0; i < len; ++i) {
        dst_ptr[i] = src_ptr[i];
    }
    return dst;
}

void* memset(void* dst, int num, size_t len)
{
    uint8_t* ptr = (uint8_t*)dst;
    for (size_t i = 0; i < len; ++i) {
        ptr[i] = num;
    }
    return dst;
}

int memcmp(const void* src1, const void* src2, size_t n)
{
    size_t i = 0;
    const uint8_t* src1_tmp = (uint8_t*)src1;
    const uint8_t* src2_tmp = (uint8_t*)src2;

    while (n > i) {
        if (src1_tmp[i] == src2_tmp[i]) {
            src1_tmp++;
            src2_tmp++;
            i++;
        } else if (src1_tmp[i] < src2_tmp[i]) {
            return -1;
        } else {
            return 1;
        }
    }
    return 0;
}

void* memmove(void*, const void*, size_t)
{
    return NULL;
}

size_t strlen(const char* str)
{
    size_t len = 0;
    while((*str) != '\0') {
        str++;
        len++;
    }
    return len;
}