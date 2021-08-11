#include "Functions.h"

_Bool isQ(char letter)
{
    return letter == 'q' || letter == 'Q';
}

char upper(char letter)
{
    char result = 0;

    if (letter >= 'a' && letter <= 'z')
    {
        result = letter - ('a' - 'A');
    }
    else
    {
        result = letter;
    }

    return result;
}