#include <libc/string.h>

extern void test_memcpy();
extern char* get_buf();

const char* str = "Hello lunaix os!\n";
char buf[256] = {0};
char* get_buf()
{
    return buf;
}

void test_memcpy()
{
    size_t len = strlen(str);
    memcpy(buf, str, len);
}

