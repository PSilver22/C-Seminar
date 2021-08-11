#include "luhnAlgorithm.h"

_Bool hasNDigits(int number, int N)
{
    int count = 0;
    for (int tempNumber = number; tempNumber != 0; tempNumber /= 10)
    {
        count++;
    }

    return count == N;
}

int setupLuhnNumber(int number, _Bool secondDigit)
{
    if (number == 0)
    {
        return number;
    }

    int currentDigit = number % 10;
    if (secondDigit)
    {
        currentDigit *= 2;
        if (currentDigit > 9)
        {
            currentDigit -= 9;
        }
    }

    return (setupLuhnNumber(number / 10, !secondDigit) * 10) + currentDigit;
}

int sumOfDigits(int number)
{
    int sum = 0;
    for (int tempNumber = number; tempNumber != 0; tempNumber /= 10)
    {
        sum += tempNumber % 10;
    }

    return sum;
}

/// @details Starts with the Luhn algorithm as seen previously, but with an 8 digit number.\n
/// Using the sum of digits that is gotten from the algorithm, it finds what number is needed to reach a power of 10.
int calculateCheckDigit(int startOfId)
{
    int result = -1;

    if (hasNDigits(startOfId, ID_SIZE - 1))
    {
        int luhnNum = setupLuhnNumber(startOfId, 1);
        result = 10 - (sumOfDigits(luhnNum) % 10);
    }

    return result;
}