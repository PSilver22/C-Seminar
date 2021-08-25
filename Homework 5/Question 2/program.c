#include "ComplexNumbers.h"
#include <stdio.h>

int main(void)
{
    Number num1 = inputNumber();

    _Bool running = 1;
    while (running)
    {
        Number num2;
        unsigned int choice;

        printf("What would you like to do?\n1. add\n2. subtract\n3. multiply\n4. division\n5. exit\n");
        scanf_s("%u", &choice);

        switch(choice)
        {
        case 1:
            num2 = inputNumber();
            num1 = add(num1, num2);
            break;

        case 2:
            num2 = inputNumber();
            num1 = add(num1, negative(num2));
            break;

        case 3:
            num2 = inputNumber();
            num1 = multiply(num1, num2);
            break;

        case 4:
            num2 = inputNumber();
            num1 = divide(num1, num2);
            break;

        default:
            running = 0;
        }
    }

    printNumber(num1);
    
    return 0;
}