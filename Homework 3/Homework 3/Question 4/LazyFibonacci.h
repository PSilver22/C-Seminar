#ifndef _LAZY_FIBONACCI_H_
#define _LAZY_FIBONACCI_H_

typedef unsigned long long int fiboNum_t;

/// @brief Calculates the nth fibonacci number using lazy evaluation
/// @param n Which number in the fibonacci sequence should be calculated
/// @return The nth fibonacci number
fiboNum_t lazyFibonacci(fiboNum_t n);

#endif