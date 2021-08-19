#include "LazyFibonacci.h"
#include <stdlib.h>

#define MAX_SIZE 100

fiboNum_t lazyFibonacci(fiboNum_t n)
{
    // create array with beginning of fibonacci sequence
    static fiboNum_t fiboNumbers[MAX_SIZE] = { 0, 1 };
    static size_t fiboNumSize = 2;

    // if the result already exists, don't calculate
    fiboNum_t result;
    if (n <= fiboNumSize)
    {
        result = fiboNumbers[n];
    }

    // if the results don't exist, calculate from the last value
    else
    {
        for (size_t index = fiboNumSize; index <= n; ++index)
        {
            fiboNumbers[index] = fiboNumbers[index - 1] + fiboNumbers[index - 2];
        }

        fiboNumSize = n;

        result = fiboNumbers[n];
    }

    return result;
}