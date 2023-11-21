#include "sort.h"

/**
 * heap_sort - Sorts an array of integers in ascending order using the
 * sift-down heap sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    build_heap(array, size);

    for (int end = size - 1; end > 0; end--)
    {
        /* Swap root and last element */
        swap(&array[0], &array[end]);
        print_array(array, size);

        /* Restore heap property */
        sift_down(array, 0, end, size);
    }
}

/**
 * build_heap - Builds a max heap from the given array.
 * @array: The array to be turned into a heap.
 * @size: The size of the array.
 */
void build_heap(int *array, size_t size)
{
    for (int start = (size - 1) / 2; start >= 0; start--)
    {
        sift_down(array, start, size - 1, size);
    }
}

/**
 * sift_down - Sifts down the element at index 'start' to maintain heap property.
 * @array: The array representing the heap.
 * @start: The index to start sifting down from.
 * @end: The end index of the heap.
 * @size: The size of the array.
 */
void sift_down(int *array, int start, int end, size_t size)
{
    int root = start;

    while (2 * root + 1 <= end)
    {
        int child = 2 * root + 1;
        int swap_idx = root;

        /* Find the larger child to swap with the root */
        if (array[swap_idx] < array[child])
            swap_idx = child;
        if (child + 1 <= end && array[swap_idx] < array[child + 1])
            swap_idx = child + 1;

        /* If root is the larger child, no need to swap further */
        if (swap_idx == root)
            return;

        /* Swap root and larger child */
        swap(&array[root], &array[swap_idx]);
        print_array(array, size);

        /* Move to the next level in the heap */
        root = swap_idx;
    }
}

/**
 * swap - Swaps two elements in an array.
 * @a: Pointer to the first element.
 * @b: Pointer to the second element.
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
