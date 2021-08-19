#include "Environment.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void listEnvStartingWith(char **envp, char *startingString)
{
    for (char **currentVar = envp; *currentVar != NULL; ++currentVar)
    {
        if (startsWith(*currentVar, startingString))
        {
            printf("%s\n", *currentVar);
        }
    }
}

_Bool startsWith(char* checkString, char* compString)
{
    _Bool result = 1;

    char *currentCheckChar = checkString;
    char *currentCompChar = compString;
    
    // check if any characters aren't equal in the strings
    while (*currentCompChar != '\0')
    {
        if (*currentCompChar != *currentCheckChar)
        {
            result = 0;
            break;
        }

        ++currentCompChar;
        ++currentCheckChar;
    }

    return result;
}