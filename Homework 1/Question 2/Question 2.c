/*
=============================================
Author: Pinny Silver
Course: C Workshop
Assignment: Homework 1, Question 2
Description: Inputs a letter, then prints the capital of it. Terminated on 'q' or 'Q'.
=============================================
*/

#include <stdio.h>
#include "Functions.h"

int main()
{
    char inputChar;

    do
    {
        printf("Input a character: ");
        scanf_s(" %c", &inputChar);

        printf("Uppercase of the input: %c\n", upper(inputChar));
    } while (!isQ(inputChar));

    return 0;
}