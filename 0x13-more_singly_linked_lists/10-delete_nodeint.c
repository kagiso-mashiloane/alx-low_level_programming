#include "lists.h"
/**
 * delete_nodeint_at_index -  that deletes the node at index,
 * index of a listint_t linked list
 * @head: listint_t linked list
 * @index:  is the index of the node that should,
 * be deleted. Index starts at 0
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *element = *head;
	listint_t *present = NULL;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);
	if (index == 0)
	{
		*head = (*head)->next;
		free(element);
		return (1);
	}
	while (i < index - 1)
	{
	if (!element || !(element->next))
		return (-1);
	element = element->next;
	i++;
	}
	present = element->next;
	element->next = present->next;
	free(present);

	return (1);
}
