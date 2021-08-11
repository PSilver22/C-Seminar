#include <stdio.h>
#include "luhnAlgorithm.h"

/// @brief Inputs the first 8 digits of an id and prints the check digit.
int main()
{
    int input;
    printf("Enter the first 8 digits of an id: ");
    scanf_s("%d", &input);

    int lastDigit = calculateCheckDigit(input);
    if (lastDigit != -1)
    {
        printf("The last digit is: %d", lastDigit);
    }
    else
    {
        printf("The start of the id is illegal.");
    }

    return 0;
}