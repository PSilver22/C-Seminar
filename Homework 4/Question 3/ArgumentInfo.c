#include "ArgumentInfo.h"
#include <stdio.h>

_Bool isSwitch(char *argument)
{
    // check if first character is a switch character
    return (*argument == '-' || *argument == '/');
}

_Bool isCharLowercase(char character)
{
    return (character >= 'a' && character <= 'z');
}

_Bool isCharUppercase(char character)
{
    return (character >= 'A' && character <= 'Z');
}

_Bool isStringUppercase(char *string)
{
    _Bool result = 1;

    for (char* currentCharacter = string; *currentCharacter != '\0' && result; ++currentCharacter)
    {
        if (isCharLowercase(*currentCharacter))
        {
            result = 0;
        }
    }

    return result;
}

_Bool isStringLowercase(char* string)
{
    _Bool result = 1;

    for (char* currentCharacter = string; *currentCharacter != '\0' && result; ++currentCharacter)
    {
        if (isCharUppercase(*currentCharacter))
        {
            result = 0;
        }
    }

    return result;
}

size_t countSwitches(char **arguments, size_t argumentCount)
{
    size_t result = 0;

    for (size_t argumentIndex = 0; argumentIndex < argumentCount; ++argumentIndex)
    {
        if (isSwitch(arguments[argumentIndex]))
        {
            ++result;
        }
    }

    return result;
}

size_t countUppercase(char** stringArray, size_t arraySize)
{
    size_t result = 0;

    for (size_t arrayIndex = 0; arrayIndex < arraySize; ++arrayIndex)
    {
        if (isStringUppercase(stringArray[arrayIndex]))
        {
            ++result;
        }
    }

    return result;
}

size_t countLowercase(char** stringArray, size_t arraySize)
{
    size_t result = 0;

    for (size_t arrayIndex = 0; arrayIndex < arraySize; ++arrayIndex)
    {
        if (isStringLowercase(stringArray[arrayIndex]))
        {
            ++result;
        }
    }

    return result;
}

void printArguments(char** arguments, size_t argumentCount)
{
    for (size_t index = 0; index < argumentCount; ++index)
    {
        printf("[%zu] %s\n", index, arguments[index]);
    }
}

void printArgumentInfo(char** argumentArray, size_t argumentCount)
{
    size_t switchArgsCount = countSwitches(argumentArray, argumentCount);
    size_t uppercaseArgsCount = countUppercase(argumentArray, argumentCount);
    size_t lowercaseArgsCount = countLowercase(argumentArray, argumentCount);

    printf("Arguments:\n");
    printArguments(argumentArray, argumentCount);

    printf("The number of arguments: %zu \n", argumentCount);
    printf("The number of switch arguments: %zu \n", switchArgsCount);
    printf("The number of entirely uppercase arguments: %zu \n", uppercaseArgsCount);
    printf("The number of entirely lowercase argument: %zu \n", lowercaseArgsCount);
    printf("The number of arguments that are neither entirely uppercase or lowercase: %zu \n", argumentCount - (uppercaseArgsCount + lowercaseArgsCount));
}