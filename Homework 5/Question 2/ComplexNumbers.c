#include "ComplexNumbers.h"
#include <stdio.h>

Number conjugate(Number num)
{
    Number result = num;

    if (num.isComplex)
    {
        result.isComplex = 1;

        result.NumberType.complex.real = num.NumberType.complex.real;
        result.NumberType.complex.imaginary = -(num.NumberType.complex.imaginary);
    }

    return result;
}

Number negative(Number num)
{
    Number result;

    if (num.isComplex)
    {
        result.NumberType.complex.imaginary = -(num.NumberType.complex.imaginary);
        result.NumberType.complex.real = -(num.NumberType.complex.real);
    }

    else
    {
        result.NumberType.real = -(num.NumberType.real);
    }

    result.isComplex = num.isComplex;

    return result;
}

Number add(Number a, Number b)
{
    Number result;

    if (a.isComplex && b.isComplex)
    {
        result.isComplex = 1;

        // add the imaginary parts and the real parts of the parameters
        result.NumberType.complex.imaginary = a.NumberType.complex.imaginary + b.NumberType.complex.imaginary;
        result.NumberType.complex.real = a.NumberType.complex.real + b.NumberType.complex.real;
    }

    else if (a.isComplex || b.isComplex)
    {
        result.isComplex = 1;

        // get the complex parameter and real parameter
        ComplexNumber complex = (a.isComplex) ? a.NumberType.complex : b.NumberType.complex;
        double real = (!a.isComplex) ? a.NumberType.real : b.NumberType.real;

        result.NumberType.complex.imaginary = complex.imaginary;
        result.NumberType.complex.real = real + complex.real;
    }

    else
    {
        result.isComplex = 0;
        
        result.NumberType.real = a.NumberType.real + b.NumberType.real;
    }

    return result;
}

Number multiply(Number a, Number b)
{
    Number result;

    if (a.isComplex && b.isComplex)
    {
        result.NumberType.complex.imaginary = (a.NumberType.complex.imaginary * b.NumberType.complex.real) + (a.NumberType.complex.real * b.NumberType.complex.imaginary);
        result.NumberType.complex.real = (a.NumberType.complex.real * b.NumberType.complex.real) - (a.NumberType.complex.imaginary * b.NumberType.complex.imaginary);

        result.isComplex = (result.NumberType.complex.imaginary != 0);
        if (!result.isComplex)
        {
            result.NumberType.real = (double) result.NumberType.complex.real;
        }
    }

    else if (a.isComplex || b.isComplex)
    {
        ComplexNumber complex = (a.isComplex) ? a.NumberType.complex : b.NumberType.complex;
        double real = (!a.isComplex) ? a.NumberType.real : b.NumberType.real;

        result.NumberType.complex.imaginary = (float) real * complex.imaginary;
        result.NumberType.complex.real = (float) real * complex.real;
        
        result.isComplex = (result.NumberType.complex.imaginary != 0);
        if (!result.isComplex)
        {
            result.NumberType.real = (double)result.NumberType.complex.real;
        }
    }

    else
    {
        result.NumberType.real = a.NumberType.real * b.NumberType.real;
    }

    return result;
}

Number divide(Number dividend, Number divisor)
{
    Number result;

    if (divisor.isComplex)
    {
        result.isComplex = 1;

        // equation for dividing a number by a complex number
        result = multiply(dividend, conjugate(divisor));
        result = divide(result, multiply(divisor, conjugate(divisor)));
    }

    else if (dividend.isComplex)
    {
        result.isComplex = 1;

        result.NumberType.complex.imaginary = dividend.NumberType.complex.imaginary / divisor.NumberType.real;
        result.NumberType.complex.real = dividend.NumberType.complex.real / divisor.NumberType.real;
    }

    else
    {
        result.isComplex = 0;

        result.NumberType.real = dividend.NumberType.real / divisor.NumberType.real;
    }

    result.isComplex = (result.NumberType.complex.imaginary != 0);
    if (!result.isComplex)
    {
        result.NumberType.real = (double)result.NumberType.complex.real;
    }

    return result;
}

Number inputNumber()
{
    int response;
    printf("Complex or real number (1/2):\n");
    scanf_s("%d", &response);

    Number result;
    if (response == 1)
    {
        result.isComplex = 1;

        printf("Real number: \n");
        scanf_s("%f", &result.NumberType.complex.real);

        printf("Imaginary number: \n");
        scanf_s("%f", &result.NumberType.complex.imaginary);
    }

    else
    {
        result.isComplex = 0;

        printf("Number: \n");
        scanf_s("%lf", &result.NumberType.real);
    }

    return result;
}

void printNumber(Number num)
{
    if (num.isComplex)
    {
        printf("%f + %fi", num.NumberType.complex.real, num.NumberType.complex.imaginary);
    }

    else
    {
        printf("%lf", num.NumberType.real);
    }
}