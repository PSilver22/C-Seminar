#include <stdio.h>

/// @brief Inputs a stream of numbers, terminated on 0, and prints the second to biggest/smallest numbers.
int main()
{
    int max = 0;
    int min = 0;
    int secondToMax = 0;
    int secondToMin = 0;

    int input = 0;
    do
    {
        if (input >= max || max == 0)
        {
            secondToMax = max;
            max = input;
        }
        else if (input > secondToMax || secondToMax == 0)
        {
            secondToMax = input;
        }

        if (input <= min || min == 0)
        {
            secondToMin = min;
            min = input;
        }
        else if (input >= secondToMin || secondToMin == 0)
        {
            secondToMin = input;
        }

        printf("Input a number: ");
        scanf_s(" %d", &input);

    } while (input != 0);

    if (secondToMin == 0 || secondToMax == 0)
    {
        printf("No result");
    }
    else
    {
        printf("Second to min: %d\nSecond to max: %d", secondToMin, secondToMax);
    }
    
    return 0;
}
