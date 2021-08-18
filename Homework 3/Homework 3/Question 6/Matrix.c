#include "Matrix.h"
#include <stdlib.h>
#include <stdio.h>

void swap(numerical_t* a, numerical_t* b)
{
    numerical_t temp = *a;
    *a = *b;
    *b = temp;
}

_Bool isNegative(numerical_t a, numerical_t b)
{
    return a == -b;
}

int transpose(numerical_t** matrix, size_t size)
{
    _Bool symmetric = 1;
    _Bool skewSymmetric = 1;

    for (size_t row = 0; row < size - 1; ++row)
    {
        for (size_t column = row + 1; column < size; ++column)
        {
            if (matrix[row][column] != matrix[column][row])
            {
                symmetric = 0;
            }

            if (!isNegative(matrix[row][column], matrix[column][row]))
            {
                skewSymmetric = 0;
            }

            swap(&matrix[row][column], &matrix[column][row]);
        }
    }

    return (symmetric) ? 1 : ((skewSymmetric) ? -1 : 0);
}