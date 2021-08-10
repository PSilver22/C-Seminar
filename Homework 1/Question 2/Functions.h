#pragma once

/// @brief Returns if the given letter is q/Q
/// @param letter
_Bool isQ(char letter)
{
    return letter == 'q' || letter == 'Q';
}

/// @brief Returns the capital version of a given letter. If the given character is not a letter, it returns the character back.
/// @param letter 
/// @return uppercase letter
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