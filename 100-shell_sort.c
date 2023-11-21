#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using
 * the Shell sort algorithm with the Knuth sequence.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
    size_t gap, i, j;
    int temp;

    if (array == NULL || size < 2)
        return;

    gap = 1;

    /* Calculate the initial gap using the Knuth sequence */
    while (gap < size / 3)
        gap = gap * 3 + 1;

    while (gap > 0)
    {
        print_array(array, size);

        /* Perform insertion sort on the subarrays defined by the gap */
        for (i = gap; i < size; i++)
        {
            temp = array[i];
            j = i;

            while (j >= gap && array[j - gap] > temp)
            {
                array[j] = array[j - gap];
                j -= gap;
            }

            array[j] = temp;
        }

        /* Calculate the next gap in the Knuth sequence */
        gap = (gap - 1) / 3;
    }

    print_array(array, size);
}

