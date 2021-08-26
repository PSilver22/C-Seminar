#include "MemDump.h"
#include <stdio.h>

void PrintHex(SingleBytePointer address, size_t numOfBytes)
{
    for (SingleBytePointer currentByte = address; currentByte < address + numOfBytes; ++currentByte)
    {
        if (*currentByte <= 0xf)
        {
            printf("0");
        }
        
        printf("%x\n", *currentByte);
    }
}