#include "MemDump.h"
#include <stdio.h>

int main(void)
{
    printf("char:\n");
    char a = 0x12;
    PrintHex((SingleBytePointer) &a, sizeof(a));

    printf("short:\n");
    short b = 0x1122;
    PrintHex((SingleBytePointer) &b, sizeof(b));

    printf("string:\n");
    char c[3] = "abc";
    PrintHex((SingleBytePointer) &c, sizeof(c));

    printf("double:\n");
    double d = 12.32;
    PrintHex((SingleBytePointer) &d, sizeof(d));

    return 0;
}