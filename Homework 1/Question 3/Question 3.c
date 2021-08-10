/*
=============================================
Author: Pinny Silver
Course: C Workshop
Assignment: Homework 1, Question 3
Description: A function that returns the length of a c-style string.
=============================================
*/

/// @brief Returns the length of a c-style string
/// @param string 
/// @return length of string
int strlen(const char* string)
{
    int letterIndex = 0;
    while (string[letterIndex++] != '\0');
    
    return letterIndex - 1;
}