#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 *
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *current, *prev, *temp;

	current = (*list)->next;

	while (current)
	{
		prev = current->prev;
		while (prev != NULL && prev->n > current->n)
		{
			temp = prev->prev;

			if (temp != NULL)
				temp->next = current;

			prev->prev = current;
			prev->next = current->next;

			if (current->next != NULL)
				current->next->prev = prev;

			current->prev = temp;
			current->next = prev;

			if (temp == NULL)
				*list = current;
			else
				temp->next = current;

			print_list(*list);
			prev = current->prev;
		}
		current = current->next;
	}
}
