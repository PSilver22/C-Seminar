#include <stdlib.h>

#ifndef _MATRIX_H_
#define _MATRIX_H_

typedef int numerical_t;

/// @brief Swaps two variables
/// @param a 
/// @param b 
void swap(numerical_t* a, numerical_t* b);

/// @brief Transposes a given square matrix in-place
/// @param matrix Square matrix to transpose
/// @param size Size of the matrix sides
void transpose(numerical_t** matrix, size_t size);

#endif