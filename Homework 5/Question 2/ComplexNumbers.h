#ifndef _COMPLEX_NUMBERS_H_
#define _COMPLEX_NUMBERS_H_

#define square(num) (num) * (num)

/// @brief Structure for numbers of the format a + bi
typedef struct ComplexNumber_t
{
    float real;
    float imaginary;
} ComplexNumber;

/// @brief Structure for real or complex numbers
typedef struct Number_t
{
    union NumberType_t
    {
        ComplexNumber complex;
        double real;
    } NumberType;

    _Bool isComplex;
} Number;

/// @brief adds two numbers
/// @param a first number to add
/// @param b second number to add
/// @return Sum of the two number
Number add(Number a, Number b);

/// @brief multiplies two numbers
/// @param a first number to multiply
/// @param b second number to multiply
/// @return Product of the two numbers
Number multiply(Number a, Number b);

/// @brief Divides two numbers
/// @param dividend number to be divided
/// @param divisor number to divide with
/// @return quotient of the two numbers
Number divide(Number dividend, Number divisor);

/// @brief Calculates the conjugate of a number
/// @param num A complex number
/// @return The conjugate of the complex number. If the number is not complex, it returns the number back.
Number conjugate(Number num);

/// @brief Calculates the negative of a number
/// @param num the number to calculate the negative of
/// @return The negative of num
Number negative(Number num);

/// @brief Inputs a number. Checks if it should be complex or not.
/// @return the inputted number
Number inputNumber();

/// @brief Print number
/// @param num 
void printNumber(Number num);

#endif