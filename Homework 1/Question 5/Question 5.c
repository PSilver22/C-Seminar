#include <stdio.h>
#include "luhnAlgorithm.h"

/// @brief Description: Inputs a 9 digit id and says if it's valid according to the Luhn algorithm.
int main()
{
    int id;
    printf("Input an ID: ");
    scanf_s("%d", &id);

    if (checkId(id))
    {
        printf("The ID is valid.");
    }
    else
    {
        printf("The ID is not valid");
    }

    return 0;
}