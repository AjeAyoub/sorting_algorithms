#include "sort.h"
#include <stdio.h>

/**
 * bitonic_sort - Sorts an array of integers in ascending order
 * using the Bitonic sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    _bitonic_sort(array, 0, size, 1);
}

/**
 * _bitonic_sort - Recursive helper function for bitonic_sort.
 * @array: The array to be sorted.
 * @low: The low index of the sequence.
 * @count: The count of elements to be sorted.
 * @up: A flag to indicate whether the sequence is in increasing order.
 */
void _bitonic_sort(int *array, size_t low, size_t count, int up)
{
    if (count > 1)
    {
        size_t k = count / 2;
        printf("Merging [%lu/%lu] (%s):\n", count, count, up ? "UP" : "DOWN");
        print_array(array + low, count);
