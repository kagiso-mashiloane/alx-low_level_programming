#include "lists.h"
/**
 * find_listint_loop - that finds the loop in a linked list.
 * @head: linked list to search for
 * Return:  The address of the node where the loop starts,
 * or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *start = head;
	listint_t *stop = head;

	if (!head)
	return (NULL);

	while (stop && start && start->next)
	{
		start = start->next->next;
		stop = stop->next;
		if (start == stop)
		{
			stop = head;
			while (stop != start)
			{
				stop = stop->next;
				start = start->next;
			}
			return (start);
		}
	}
	return (NULL);
}
