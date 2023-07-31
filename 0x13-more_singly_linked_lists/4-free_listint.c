#include "lists.h"
/**
 * free_listint - that frees a listint_t list
 * @head: free the listint_t list.
 */
void free_listint(listint_t *head)
{
	listint_t *element;

	while (head)
	{
		head = element;
		free(head);
		element = head->next;
	}
}
