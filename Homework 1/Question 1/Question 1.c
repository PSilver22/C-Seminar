/*
=============================================
Author: Pinny Silver
Course: C Workshop
Assignment: Homework 1, Question 1
Description: Inputs then prints a character. Terminated on 'q' or 'Q'.
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

        printf("Your character is: %c\n", inputChar);
    } while (!isQ(inputChar));

    return 0;
}