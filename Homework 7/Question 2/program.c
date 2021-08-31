#include "Macros.h"

#define ARRAY_SIZE 5

int main(void)
{
    double sum = 0, average = 0, grades[ARRAY_SIZE] = {12.1, 54.7, 92.2, 78.0, 43.1};

    for (size_t index = 0; index < ARRAY_SIZE; ++index)
    {
        sum += grades[index];
        average = sum / ((double) index + 1);

        TRACE_VAR(index, "%u");
        TRACE_VAR(grades[index], "%lf");
        TRACE_VAR(sum, "%lf");
        TRACE_VAR(average, "%lf");

        printf("\n");
    }

    return 0;
}