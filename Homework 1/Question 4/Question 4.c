#include <stdio.h>
#include "printDiamond.h"

/// @brief Inputs the size of a dimaond, then prints the diamond.
int main()
{
    int size;
    printf("How big should the diamond be? ");
    scanf_s("%d", &size);

    printDiamond(size);

    return 0;
}