#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm.
 * @list: A pointer to the head of the doubly linked list.
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped = 1;
    listint_t *current;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    while (swapped)
    {
        swapped = 0;
        /* Traverse the list from left to right */
        for (current = *list; current->next != NULL; current = current->next)
        {
            if (current->n > current->next->n)
            {
                swap_nodes(current, current->next, list);
                swapped = 1;
                print_list(*list);
            }
        }

        if (!swapped)
            break;

        swapped = 0;
        /* Traverse the list from right to left */
        for (; current->prev != NULL; current = current->prev)
        {
            if (current->n < current->prev->n)
            {
                swap_nodes(current->prev, current, list);
                swapped = 1;
                print_list(*list);
            }
        }
    }
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @left: The left node.
 * @right: The right node.
 * @list: A pointer to the head of the doubly linked list.
 */
void swap_nodes(listint_t *left, listint_t *right, listint_t **list)
{
    if (left->prev != NULL)
        left->prev->next = right;

    if (right->next != NULL)
        right->next->prev = left;

    left->next = right->next;
    right->prev = left->prev;

    left->prev = right;
    right->next = left;

    if (left == *list)
        *list = right;
}
