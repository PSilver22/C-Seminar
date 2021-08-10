/*
=============================================
Author: Pinny Silver
Course: C Workshop
Assignment: Homework 1, Question 4
Description: Prints diamond of given size.
=============================================
*/

#include <stdio.h>
#include "Functions.h"

int main()
{
    int middleSize;
    printf("How big should the middle layer be? ");
    scanf_s("%d", &middleSize);

    int bottomSize = (middleSize % 2 == 0) ? 2 : 1;
    int layerCount = ((middleSize - bottomSize) / 2);

    printDiamond(layerCount, middleSize, bottomSize);

    return 0;
}