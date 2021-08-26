#ifndef _MEMDUMP_H_
#define _MEMDUMP_H_
#include <stddef.h>

/// @brief Pointer to a single byte of data
typedef unsigned char* SingleBytePointer;

/// @brief Prints the hexadecimal of data at a given address one byte at a time.
/// @param address The address of the data
/// @param numOfBytes The size of the data at the given address
void PrintHex(SingleBytePointer address, size_t numOfBytes);

#endif