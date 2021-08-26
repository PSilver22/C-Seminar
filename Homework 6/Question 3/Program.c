#include "MemDumpV2.h"
#include <stdio.h>

int main(void)
{
    printf("char:\n");
    char a = 0xaa; // alternating pattern starting with 1
    PrintBin((SingleBytePointer)&a, sizeof(a));

    printf("short:\n");
    short b = 0xaaaa; // alternating pattern starting with 1
    PrintBin((SingleBytePointer)&b, sizeof(b));

    printf("string:\n");
    char c[4] = "abc";
    PrintBin((SingleBytePointer)&c, sizeof(c));

    printf("double:\n");
    double d = 12.32;
    PrintBin((SingleBytePointer)&d, sizeof(d));

    return 0;
}