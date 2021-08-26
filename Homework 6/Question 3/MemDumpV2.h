#ifndef _MEMDUMPV2_H_
#define _MEMDUMPV2_H_
#include <stddef.h>

#define BYTE_SIZE 8

/// @brief Pointer to a single byte of data
typedef unsigned char* SingleBytePointer;

/// @brief Checks if the most significant bit of a byte is on
/// @param address The address of the data to check
/// @return True if the significant bit is 1, false if 0
_Bool CheckSignificantBitOfByte(SingleBytePointer address);

/// @brief Prints the binary of data at a given address one byte at a time.
/// @param address The address of the data
/// @param numOfBytes The size of the data at the given address
void PrintBin(SingleBytePointer address, size_t numOfBytes);

#endif