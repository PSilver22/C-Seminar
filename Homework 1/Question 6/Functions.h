#pragma once
#define ID_SIZE 9

/// @brief Checks if the given number has N digits.
/// @param number The number to check the amount of digits.
/// @param N The size to check the given number for.
_Bool hasNDigits(int number, int N)
{
    int count = 0;
    for (int tempNumber = number; tempNumber != 0; tempNumber /= 10)
    {
        count++;
    }

    return count == N;
}

/// @brief A recursive function to setup a given number for the Luhn algorithm.
/// @param number The number to setup.
/// @param secondDigit A boolean stating if the current digit should be multiplied by 2 according to the algorithm.
/// @return The number updated for Luhn algorithm.
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

/// @brief Calculates the sum the digits of a number.
/// @param number 
/// @return Sum of digits of a number.
int sumOfDigits(int number)
{
    int sum = 0;
    for (int tempNumber = number; tempNumber != 0; tempNumber /= 10)
    {
        sum += tempNumber % 10;
    }

    return sum;
}

/// @brief Calculates the check digit of an id.
/// @param startOfId The first 8 digits of an id.
/// @return The check digit.
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