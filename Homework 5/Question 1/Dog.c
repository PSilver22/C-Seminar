#include "Dog.h"
#include <stdlib.h>
#include <stdio.h>

void swap(Dog *a, Dog *b)
{
    Dog temp = *a;
    *a = *b;
    *b = temp;
}

_Bool compareWeights(Dog *a, Dog *b)
{
    return a->kg > b->kg;
}

_Bool compareNames(Dog *a, Dog *b)
{
    char *currentLetterA = a->name;
    char *currentLetterB = b->name;
    _Bool result = 0;

    // compare each letter of the names
    while (currentLetterA != '\0' && currentLetterA == currentLetterB)
    {    
        ++currentLetterA;
        ++currentLetterB;
    }

    // compare the first not equal character in the two strings
    if (*currentLetterA > *currentLetterB)
    {
        result = 1;
    }
    
    return result;
}

void sortDogs(Dog *dogs, size_t numOfDogs, ComparisonFunction compare)
{
    // Bubble sort the dogs
    for (size_t count = 0; count < numOfDogs; ++count)
    {
        for (Dog *currentDog = dogs; currentDog != dogs + numOfDogs - 1; ++currentDog)
        {
            if (compare(currentDog, currentDog + 1))
            {
                swap(currentDog, currentDog + 1);
            }
        }
    }
}

void sortByWeight(Dog *dogs, size_t numOfDogs)
{
    sortDogs(dogs, numOfDogs, compareWeights);
}

void sortByName(Dog *dogs, size_t numOfDogs)
{
    sortDogs(dogs, numOfDogs, compareNames);
}