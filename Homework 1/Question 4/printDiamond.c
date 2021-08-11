#include "printDiamond.h"

/// @details Overview:
/// @li Prints right side up triangle, excluding the middle layer
/// @li Prints upside down triangle, including the middle layer
void printDiamond(int size)
{
    int bottomSize = (size % 2 == 0) ? 2 : 1;
    int layerCount = ((size - bottomSize) / 2);

    for (int layer = 0; layer < layerCount; layer++)
    {
        for (int spacesCount = 0; spacesCount < ((size - bottomSize) / 2) - layer; spacesCount++)
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
        for (int spacesCount = 0; spacesCount < ((size - bottomSize) / 2) - layer; spacesCount++)
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