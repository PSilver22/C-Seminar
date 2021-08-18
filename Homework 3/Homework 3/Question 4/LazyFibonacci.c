#include "LazyFibonacci.h"
#include <stdlib.h>

uint lazyFibonacci(uint n)
{
    // create array with beginning of fibonacci sequence
    uint* fiboNumbers = malloc((n + 1) * sizeof(uint));
    fiboNumbers[0] = 0, fiboNumbers[1] = 1;

    // fill in the rest of the array until the nth element
    for (size_t index = 2; index <= n; ++index)
    {
        fiboNumbers[index] = fiboNumbers[index - 1] + fiboNumbers[index - 2];
    }

    // get the last number in the sequence
    uint result = fiboNumbers[n];

    free(fiboNumbers);
    return result;
}