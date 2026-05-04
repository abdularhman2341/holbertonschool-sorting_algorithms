#include "sort.h"

/**
 * swap_nodes - Swaps a node with the one before it in a doubly linked list
 * @list: Pointer to the head of the list
 * @current: The node to move backwards
 */
static void swap_nodes(listint_t **list, listint_t *current)
{
	listint_t *prev_node;

	prev_node = current->prev;

	prev_node->next = current->next;
	if (current->next != NULL)
		current->next->prev = prev_node;

	current->prev = prev_node->prev;
	current->next = prev_node;

	if (prev_node->prev != NULL)
		prev_node->prev->next = current;
	else
		*list = current;

	prev_node->prev = current;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using Insertion sort
 * @list: Pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		while (current->prev != NULL && current->prev->n > current->n)
		{
			swap_nodes(list, current);
			print_list(*list);
		}
		current = current->next;
	}
}
