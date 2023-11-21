#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge_sort - Sorts an array of integers in ascending order using the
 * top-down merge sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    merge_recursive(array, size);
}

/**
 * merge_recursive - Recursively divides and merges the array.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_recursive(int *array, size_t size)
{
    if (size > 1)
    {
        size_t mid = size / 2;
        int *left = array;
        int *right = array + mid;

        printf("Merging...\n");
        printf("[left]: ");
        print_array(left, mid);
        printf("[right]: ");
        print_array(right, size - mid);

        merge_recursive(left, mid);
        merge_recursive(right, size - mid);

        merge(array, left, mid, right, size - mid);

        printf("[Done]: ");
        print_array(array, size);
    }
}

/**
 * merge - Merges two subarrays into a sorted array.
 * @array: The main array.
 * @left: The left subarray.
 * @left_size: The size of the left subarray.
 * @right: The right subarray.
 * @right_size: The size of the right subarray.
 */
void merge(int *array, int *left, size_t left_size, int *right, size_t right_size)
{
    size_t i = 0, j = 0, k = 0;
    int *temp = malloc((left_size + right_size) * sizeof(int));

    if (temp == NULL)
        exit(EXIT_FAILURE);

    while (i < left_size && j < right_size)
    {
        if (left[i] <= right[j])
        {
            temp[k] = left[i];
            i++;
        }
        else
        {
            temp[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left_size)
    {
        temp[k] = left[i];
        i++;
        k++;
    }

    while (j < right_size)
    {
        temp[k] = right[j];
        j++;
        k++;
    }

    for (i = 0; i < left_size + right_size; i++)
        array[i] = temp[i];

    free(temp);
}
