#include "stddef.h"
#include <stdarg.h>

#ifndef _REVERSE_H_
#define _REVERSE_H_

/// @brief Swaps two characters
/// @param a 
/// @param b 
void swap(char *a, char *b);

/// @brief Reverses the order of the words in the sentence in-place
/// @param sentence Sentence to reverse
/// @param size Size of the sentence string
void reverseSentence(char *sentence, size_t size);

/// @brief Reverse a string in-place
/// @param string String to reverse
/// @param stringSize Size of the string without the null character
void reverseString(char *string, size_t stringSize);

/// @brief Checks if the given character is a whitespace character
/// @param c The character to check
/// @return True if character is whitespace, else false
_Bool isWhitespaceChar(char c);

#endif