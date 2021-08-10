/*
=============================================
Author: Pinny Silver
Course: C Workshop
Assignment: Homework 1, Question 7
Description: Inputs a stream of numbers, terminated on 0, then prints the reverse of the numbers.
=============================================
*/

#include <stdio.h>

int main()
{
    int input;
    printf("Input a number: ");
    scanf_s(" %d", &input);

    if (input == 0)
    {
        return 0;
    }

    main();
    printf("%d, ", input);

    return 0;
}