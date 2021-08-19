#ifndef _ARGUMENT_INFO_H_
#define _ARGUMENT_INFO_H_
#include <stddef.h>

/// @brief Check if a given argument is a switch
/// @param argument The argument to check
/// @return True if argument is a switch, else false
_Bool isSwitch(char *argument);

/// @brief Checks if a character is uppercase
/// @param character 
/// @return True if character is uppercase, else false
_Bool isCharUppercase(char character);

/// @brief Checks if the entirety of a string is uppercase
/// @param string 
/// @return True if the string is entirely uppercase, else false
_Bool isStringUppercase(char *string);

/// @brief Checks if a character is lowercase
/// @param character 
/// @return True if character is lowercase, else false
_Bool isCharLowercase(char character);

/// @brief Checks if the entirety of a string is lowercase
/// @param string 
/// @return True if the string is entirely lowercase, else false
_Bool isStringLowercase(char *string);

/// @brief Returns the amount of switches in an array of arguments
/// @param arguments The array of arguments
/// @param argumentCount The number of arguments in the array
/// @return The number of switches in the arguments
size_t countSwitches(char **arguments, size_t argumentCount);

/// @brief Lists the arguments in an array
/// @param arguments The array to list
/// @param argumentCount The number of arguments in the argument array
void printArguments(char **arguments, size_t argumentCount);

/// @brief Counts the amount of strings in an array that are entirely uppercase
/// @param stringArray The array to check
/// @param arraySize The number of strings in the array
/// @return The count of strings that are entirely uppercase
size_t countUppercase(char **stringArray, size_t arraySize);

/// @brief Counts the amount of strings in an array that are entirely lowercase
/// @param stringArray The array to check
/// @param arraySize The number of strings in the array
/// @return The count of strings that are entirely lowercase
size_t countLowercase(char **stringArray, size_t arraySize);

/// @brief Print all the information about given arguments
/// @param argumentArray Array of arguments to get info on
/// @param argumentCount Size of argument array
void printArgumentInfo(char **argumentArray, size_t argumentCount);

#endif