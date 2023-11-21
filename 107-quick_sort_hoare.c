#include "sort.h"

/**
 * cocktail_sort - Sorts an array of integers in ascending order using Cocktail sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void cocktail_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    int swapped = 1;
    size_t start = 0;
    size_t end = size - 1;

    while (swapped)
    {
        swapped = 0;

        for (size_t i = start; i < end; ++i)
        {
            if (array[i] > array[i + 1])
            {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = 1;
                print_array(array, size);
            }
        }

        if (!swapped)
            break;

        swapped = 0;
        end--;

        for (size_t i = end; i > start - 1; i--)
        {
            if (array[i] > array[i + 1])
            {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = 1;
                print_array(array, size);
            }
        }

        start++;
    }
}
