#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * counting_sort - Sorts an array of integers in ascending order using the
 * counting sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    counting_sort_algorithm(array, size);
}

/**
 * counting_sort_algorithm - Implements the counting sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort_algorithm(int *array, size_t size)
{
    int *count, *output;
    size_t i;
    int max = array[0];

    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    count = malloc((max + 1) * sizeof(int));
    output = malloc(size * sizeof(int));

    if (count == NULL || output == NULL)
        exit(EXIT_FAILURE);

    for (i = 0; i <= (size_t)max; i++)
        count[i] = 0;

    for (i = 0; i < size; i++)
        count[array[i]]++;

    print_count_array(count, max + 1);

    for (i = 1; i <= (size_t)max; i++)
        count[i] += count[i - 1];

    for (i = 0; i < size; i++)
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    for (i = 0; i < size; i++)
        array[i] = output[i];

    free(count);
    free(output);
}

/**
 * print_count_array - Prints the counting array.
 * @count: The counting array.
 * @size: The size of the array.
 */
void print_count_array(int *count, size_t size)
{
    size_t i;

    printf("%d", count[0]);
    for (i = 1; i < size; i++)
        printf(", %d", count[i]);
    printf("\n");
}
