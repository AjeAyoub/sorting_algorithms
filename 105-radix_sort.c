#include "sort.h"
#include <stdlib.h>

/**
 * radix_sort - Sorts an array of integers in ascending order using
 * the LSD radix sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
    int max = getMax(array, size);

    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countingSort(array, size, exp);
        print_array(array, size);
    }
}

/**
 * getMax - Gets the maximum value in an array.
 * @array: The array to find the maximum value.
 * @size: The size of the array.
 *
 * Return: The maximum value in the array.
 */
int getMax(int *array, size_t size)
{
    int max = array[0];
    for (size_t i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}

/**
 * countingSort - Sorts the array using counting sort based on the
 * significant place represented by exp.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @exp: The current significant place (1, 10, 100, ...).
 */
void countingSort(int *array, size_t size, int exp)
{
    const int radix = 10; // The base of the number system
    int *output = malloc(sizeof(int) * size);
    int count[radix] = {0};

    if (output == NULL)
        return;

    // Count occurrences of digits at the current significant place
    for (size_t i = 0; i < size; i++)
        count[(array[i] / exp) % radix]++;

    // Accumulate the counts to get the position of each element
    for (int i = 1; i < radix; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / exp) % radix] - 1] = array[i];
        count[(array[i] / exp) % radix]--;
    }

    // Copy the sorted elements back to the original array
    for (size_t i = 0; i < size; i++)
        array[i] = output[i];

    free(output);
}
