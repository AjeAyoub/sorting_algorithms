#include "deck.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @node1: Pointer to the first node.
 * @node2: Pointer to the second node.
 */
void swap_nodes(deck_node_t *node1, deck_node_t *node2)
{
    if (node1->prev)
        node1->prev->next = node2;
    if (node2->next)
        node2->next->prev = node1;

    node1->next = node2->next;
    node2->prev = node1->prev;

    node1->prev = node2;
    node2->next = node1;
}

/**
 * sort_deck - Sorts a deck of cards in ascending order.
 * @deck: Pointer to the head of the doubly linked list.
 */
void sort_deck(deck_node_t **deck)
{
    deck_node_t *current;
    int swapped;

    if (deck == NULL || *deck == NULL)
        return;

    do
    {
        swapped = 0;
        current = *deck;

        while (current->next)
        {
            if ((current->card->kind > current->next->card->kind) ||
                (current->card->kind == current->next->card->kind &&
                 strcmp(current->card->value, current->next->card->value) > 0))
            {
                swap_nodes(current, current->next);
                if (!current->prev)
                    *deck = current;
                swapped = 1;
                print_deck(*deck);
            }
            else
            {
                current = current->next;
            }
        }
    } while (swapped);
}
