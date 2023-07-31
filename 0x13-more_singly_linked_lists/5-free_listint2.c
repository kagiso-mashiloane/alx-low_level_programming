#include "lists.h"
/**
 * free_listint2 - that frees a listint_t list.
 * @head: sets the head to NULL
 */
void free_listint2(listint_t **head)
{
	listint_t *element;

	if (head == NULL)
		return;
	while (*head)
	{
		element = (*head)->next;
		free(*head);
		*head = element;
	}
	*head = NULL;
}
