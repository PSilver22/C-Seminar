#include "Reverse.h"
#include <stdio.h>
#include <stddef.h>

#define SIZE 12

_Bool isWhitespaceChar(char c)
{
    _Bool result = 0;
    switch (c)
    {
    case ' ':
        /* fall through */
    case '\n':
        /* fall through */
    case '\0':
        /* fall through */
    case '\t':
        result = 1;
    }

    return result;
}

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverseString(char *string, size_t stringSize)
{
    char *startOfString = string;
    char *endOfString = startOfString + stringSize - 1; // The last character of the string

    while (startOfString < endOfString)
    {
        swap(startOfString, endOfString);
        ++startOfString;
        --endOfString;
    }
}

void reverseSentence(char *sentence, size_t size)
{
    // reverse entire string
    reverseString(sentence, size - 1);

    //reverse each word back to normal
    char *startOfWord = NULL;
    char *currentChar = sentence;
    char *endOfSentence = sentence + size;
    _Bool inWord = 0;

    // find each separate word and re-reverse each.
    while (currentChar != endOfSentence)
    {
        if (!inWord && !isWhitespaceChar(*currentChar))
        {
            startOfWord = currentChar;
            inWord = 1;
        }

        else if (inWord && isWhitespaceChar(*currentChar))
        {
            reverseString(startOfWord, currentChar - startOfWord);
            inWord = 0;
        }
        
        ++currentChar;
    }
}