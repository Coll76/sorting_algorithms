#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *ins_point;

	if (*list == NULL || list == NULL)
	{
		return;
	}
	current = (*list)->next;
	while (current != NULL)
	{
		ins_point = current->prev;
	while (ins_point != NULL && ins_point->n > current->n)
	{
		if (ins_point->prev != NULL)
		{
			ins_point->prev->next = current;
		}
		else
		{
			*list = current;
		}
		current->prev = ins_point->prev;
		ins_point->prev = current;
		ins_point->next = current->next;
		print_list(*list);

		if (current->next != NULL)
		{
		current->next->prev = ins_point;
		}
		current->next = ins_point;
		ins_point = current->prev;
	}
current = current->next;

print_list(*list);
	}
}
