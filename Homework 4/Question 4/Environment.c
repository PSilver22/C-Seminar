#include "Environment.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void listEnvVariables(char** envp)
{
    for(char **currentVar = envp; *currentVar != NULL; ++currentVar)
    {
        char *key = getEnvKey(*currentVar);
        char *value = getEnvValue(*currentVar);
        
        printf("Environment variable \"%s\" has the value \"%s\"\n", key, value);

        // since key and value were allocated in the function, so they have to be freed
        free(key);
        free(value);
    }
}

size_t getEnvKeyLength(char *envVariable)
{
    size_t length = 0;
    for (; envVariable[length] != '='; length++) {}

    return length;
}

char *getEnvKey(char *envVariable)
{
    size_t length = getEnvKeyLength(envVariable);
    char *envKey = malloc((length + 1) * sizeof(char));
    envKey[length] = '\0';

    // copy the key of the env
    for (size_t i = 0; i < length; ++i)
    {
        envKey[i] = envVariable[i];
    }

    return envKey;
}

size_t getEnvValueLength(char* envVariable)
{
    size_t length = 0;
    size_t keyLength = getEnvKeyLength(envVariable);
    for (; envVariable[length + keyLength + 1] != '\0'; length++) {}

    return length;
}

char* getEnvValue(char* envVariable)
{
    size_t length = getEnvValueLength(envVariable);
    char *envValue = malloc((length + 1) * sizeof(char));
    envValue[length] = '\0';

    size_t envValueStart = getEnvKeyLength(envVariable) + 1;

    // copy the key of the env
    for (size_t i = 0; i < length; ++i)
    {
        envValue[i] = envVariable[i + envValueStart];
    }

    return envValue;
}