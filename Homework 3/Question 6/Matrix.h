#include <stdlib.h>

#ifndef _MATRIX_H_
#define _MATRIX_H_

typedef int numerical_t;

/// @brief Swaps two variables
/// @param a 
/// @param b 
void swap(numerical_t* a, numerical_t* b);

/// @brief Transposes a given square matrix in-place, and checks if symmetric or skew symmetric
/// @param matrix Square matrix to transpose
/// @param size Size of the matrix sides
/// @return Return 1 if the matrix is symmetrical, -1 if skew symmetrical, and 0 if none
int transpose(numerical_t **matrix, size_t size);

/// @brief Checks if one number is the negative of the other
/// @param a First number
/// @param b Second number
/// @return True if a is the negative of b, false otherwise
_Bool isNegative(numerical_t a, numerical_t b);

#endif