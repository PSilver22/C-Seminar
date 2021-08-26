#include "MemDumpV2.h"
#include <stdio.h>

_Bool CheckSignificantBitOfByte(SingleBytePointer address)
{
    return *address & (1 << (BYTE_SIZE - 1));
}

void PrintBin(SingleBytePointer address, size_t numOfBytes)
{
    for (SingleBytePointer currentByte = address; currentByte < address + numOfBytes; ++currentByte)
    {
        // Loop through each bit of the byte and check if the bit is 1
        SingleBytePointer currentBin = currentByte;
        for (size_t counter = 0; counter < BYTE_SIZE; ++counter)
        {
            // check if the current bit is 1 or 0 
            char bit = (CheckSignificantBitOfByte(currentBin)) ? '1' : '0';
            printf("%c", bit);

            // put a space between every 4 bits
            if (counter == (BYTE_SIZE - 1) / 2)
            {
                printf(" ");
            }

            // shift to the next bit
            (*currentBin) <<= 1;
        }

        printf("\n");
    }
}