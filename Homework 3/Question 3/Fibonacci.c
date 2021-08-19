#include "fibonacci.h"

uint fibonacci(uint n)
{
    uint result;

    // fibonacci base cases of 0 and 1
    if (n == 0 || n == 1)
    {
        result = n;
    }

    else
    {
        // result equals sum of the two previous values.
        result = fibonacci(n - 1) + fibonacci(n - 2);
    }

    return result;
}