#include "Matrix.h"
#include <stdlib.h>

void swap(numerical_t* a, numerical_t* b)
{
    numerical_t temp = *a;
    *a = *b;
    *b = temp;
}

void transpose(numerical_t** matrix, size_t size)
{
    for (size_t row = 0; row < size - 1; ++row)
    {
        for (size_t column = row + 1; column < size; ++column)
        {
            swap(&matrix[row][column], &matrix[column][row]);
        }
    }
}