#include "sort.h"

/**
 * swap_two_nodes - Swaps two given nodes of type listint_t. (doubly linked)
 *
 * @h: A pointer to the head of the list.
 * @n1: A pointer to the first node.
 * @n2: A pointer to the second node.
 */
void swap_two_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
	{
		n2->next->prev = *n1;
	}
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
	{
		(*n1)->prev->next = n2;
	}
	else
	{
		*h = n2;
	}
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list using insertion sort
 * algorithm.
 *
 * @list: The given list to sort.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	iter = (*list)->next;
	while (iter != NULL)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap_two_nodes(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
		iter = tmp;
	}
}
