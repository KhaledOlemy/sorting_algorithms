#include "sort.h"
/**
 * insertion_sort_list - insertion sort function
 * @list: doubly linked list to sort
 *
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node, *looper;

	if (!(*list) || !(*list)->next)
	{
		return;
	}
	looper = (*list)->next;
	while (looper)
	{
		node = looper;
		while (node->prev)
		{
			if (node->prev->n > node->n)
			{
				swap_nodes(node->prev, node);
				if (!node->prev)
				{
					*list = node;
				}
				print_list(*list);
			}
			else
			{
				node = node->prev;
			}
		}
		looper = looper->next;
	}
}

/**
 * swap_nodes - swap 2 doubly linked list nodes.
 * @node1: node 1 to swap with node 2
 * @node2: node 2 to swap with node 1
 *
 * Return: Nothing
 */
void swap_nodes(listint_t *node1, listint_t *node2)
{
	if ((node1)->prev)
	{
		(node1)->prev->next = node2;
	}
	if ((node2)->next)
	{
		(node2)->next->prev = node1;
	}

	(node1)->next = (node2)->next;
	(node2)->prev = (node1)->prev;

	(node1)->prev = node2;
	(node2)->next = node1;
}
