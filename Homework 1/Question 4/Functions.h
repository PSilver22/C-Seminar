#pragma once
#include <stdio.h>

/// @brief Prints a diamond.
/// @param layerCount The amount of layers in the diamond.
/// @param middleSize The size of the middle layer of the diamond.
/// @param bottomSize The size of the bottom layer of the diamond.
void printDiamond(layerCount, middleSize, bottomSize)
{
    for (int layer = 0; layer < layerCount; layer++)
    {
        for (int spacesCount = 0; spacesCount < ((middleSize - bottomSize) / 2) - layer; spacesCount++)
        {
            printf(" ");
        }

        for (int starCount = 0; starCount < bottomSize + layer * 2; starCount++)
        {
            printf("*");
        }

        printf("\n");
    }

    for (int layer = layerCount; layer >= 0; layer--)
    {
        for (int spacesCount = 0; spacesCount < ((middleSize - bottomSize) / 2) - layer; spacesCount++)
        {
            printf(" ");
        }

        for (int starCount = 0; starCount < bottomSize + layer * 2; starCount++)
        {
            printf("*");
        }

        printf("\n");
    }
}