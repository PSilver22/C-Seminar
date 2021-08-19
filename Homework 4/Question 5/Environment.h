#include <stddef.h>

#ifndef _ENVIRONMENT_H_
#define _ENVIRONMENT_H_

/// @brief Lists environment variables starting with startingString
/// @param envp The array of environment variables, ending with null pointer
/// @param startingString The string to check each environment variable for starting with
void listEnvStartingWith(char** envp, char* startingString);

/// @brief Checks if checkString starts with compString, assumes compString is smaller
/// @param checkString String to check
/// @param compString String to compare with
/// @return True if checkString starts with compString, else false
_Bool startsWith(char *checkString, char *compString);

#endif