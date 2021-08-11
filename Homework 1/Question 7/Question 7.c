#include <stdio.h>

/// @brief Inputs a stream of numbers, terminated on 0, then prints the reverse of the numbers.
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