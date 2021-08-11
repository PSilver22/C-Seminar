/// @mainpage
/// @author Pinny Silver
/// @date 8/11/21
/// @par Course
/// C Workshop
#include <stdio.h>
#include "isQ.h"

/// @brief Inputs then prints the inputted character. Terminated on 'q' or 'Q'.
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