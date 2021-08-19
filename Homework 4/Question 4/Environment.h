#include <stddef.h>

#ifndef _ENVIRONMENT_H_
#define _ENVIRONMENT_H_

/// @brief Lists environment variables
/// @param envp The array of environment variables, ending with null
void listEnvVariables(char **envp);

/// @brief Gets the key of the environment variable
/// @param envVariable Environment variable string with key and value separated by '='
/// @return Allocated string with the key
char *getEnvKey(char *envVariable);

/// @brief Get the length of the environment key string
/// @param envVariable Environment variable string with key and value separated by '='
/// @return Length of the key of the environment variable
size_t getEnvKeyLength(char *envVariable);

/// @brief Get the length of the environment value string
/// @param envVariable Environment variable string with key and value separated by '='
/// @return Length of the value of the environment variable
size_t getEnvValueLength(char *envVariable);

/// @brief Gets the key of the environment variable
/// @param envVariable Environment variable string with key and value separated by '='
/// @return Allocated string with the variable
char *getEnvValue(char *envVariable);
#endif