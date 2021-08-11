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

/// @details Overview of @link Luhn algorithm @endlink:
/// @li From the rightmost digit, and moving left, double the value of every second digit
/// @li Sum all the digits of the modified number
/// @li If the total mod 10 is 0, the id is valid.
_Bool checkId(int id)
{
    _Bool result = 0;

    if (hasNDigits(id, ID_SIZE))
    {
        int modifiedID = setupLuhnNumber(id, 0);
        result = (sumOfDigits(modifiedID) % 10) == 0;
    }

    return result;
}