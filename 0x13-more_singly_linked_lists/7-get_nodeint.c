#include "lists.h"
/**
 * get_nodeint_at_index - that returns the nth node,
 * of a listint_t linked list.
 * @head: listint_t linked list.
 * @index: index is the index of the node,
 * starting at 0
 * Return: the node does not exist, return NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *element = head;
	unsigned int k = 0;

	while (element && k < index)
	{
		element = element->next;
		k++;
	}
	return (element ? element : NULL);
}
