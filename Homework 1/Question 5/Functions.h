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

/// @brief Checks if the given ID is legal according to the Luhn algorithm
/// @param id 
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