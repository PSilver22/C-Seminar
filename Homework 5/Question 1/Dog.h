#ifndef _DOG_H_
#define _DOG_H_

#include <stddef.h>
typedef unsigned int weight;

/// @brief Struct to represent a dog, keeping names and weight
typedef struct Dog_t {
    char* name;
    weight kg;
} Dog;

void swap(Dog *a, Dog *b);

/// @brief When the function returns true, the first dog goes before the second dog.
typedef _Bool(*ComparisonFunction)(Dog *, Dog *); 

/// @brief Sorts dogs based off of the passed compare function
/// @param dogs Array of dogs
/// @param numOfDogs Number of dogs in the array
/// @param compare Comparison function to use to sort the dogs
void sortDogs(Dog *dogs, size_t numOfDogs, ComparisonFunction compare);

/// @brief Sorts dogs based off of the dogs weight
/// @param dogs Array of dogs
/// @param numOfDogs Number of dogs in the array
void sortByWeight(Dog *dogs, size_t numOfDogs);

/// @brief Sorts dogs based off of the dogs weight
/// @param dogs Array of dogs
/// @param numOfDogs Number of dogs in the array
void sortByName(Dog *dogs, size_t numOfDogs);

/// @brief Compares the weights of two dogs
_Bool compareWeights(Dog *a, Dog *b);

/// @brief Compares the names of the two dogs
_Bool compareNames(Dog *a, Dog *b);

#endif