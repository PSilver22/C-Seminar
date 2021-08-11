#pragma once

#define ID_SIZE 9

/// @brief Checks if the given number has N digits.
/// @param number The number to check the amount of digits.
/// @param N The size to check the given number for.
_Bool hasNDigits(int number, int N);

/// @brief A recursive function to setup a given number for the Luhn algorithm.
/// @param number The number to setup.
/// @param secondDigit A boolean stating if the current digit should be multiplied by 2 according to the algorithm.
/// @return The number updated for Luhn algorithm.
int setupLuhnNumber(int number, _Bool secondDigit);

/// @brief Calculates the sum the digits of a number.
/// @param number 
/// @return Sum of digits of a number.
int sumOfDigits(int number);

/// @brief Checks if the given ID is legal according to the Luhn algorithm
/// @param id 
_Bool checkId(int id);