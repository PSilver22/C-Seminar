#include "ComplexNumbers.h"
#include <stdio.h>

int main(void)
{
    Number num1 = inputNumber();

    _Bool running = 1;

    // perform inputted operations
    while (running)
    {
        Number num2;
        unsigned int choice;

        printf("What would you like to do?\n1. add\n2. subtract\n3. multiply\n4. division\n5. exit\nchoice:");
        scanf_s("%u", &choice);

        if (choice == 5)
        {
            running = 0;
            break;
        }

        num2 = inputNumber();

        switch(choice)
        {
        case 1:
            num1 = add(num1, num2);
            break;

        case 2:
            num1 = add(num1, negative(num2));
            break;

        case 3:
            num1 = multiply(num1, num2);
            break;

        case 4:
            num1 = divide(num1, num2);
            break;
        }

        printNumber(num1);
    }

    // print out final result for all of the operations.
    
    return 0;
}