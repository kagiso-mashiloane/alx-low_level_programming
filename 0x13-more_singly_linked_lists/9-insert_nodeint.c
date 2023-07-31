#include "lists.h"
/**
 * insert_nodeint_at_index - that inserts a new node,
 * at a given position.
 * @head: new node in the list of a pointer
 * @idx:  is the index of the list where the,
 * new node should be added. Index starts at 0
 * @n: new node where data is inserted
 * Return: the address of the new node,
 *or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *element = *head;
	listint_t *new_ele;
	unsigned int i;

	new_ele = malloc(sizeof(listint_t));
	if (!new_ele || !head)
		return (NULL);
	new_ele->n = n;
	new_ele->next = NULL;

	if (idx == 0)
	{
		new_ele->next = *head;
		*head = new_ele;
		return (new_ele);
	}

	for (i = 0; element && i < idx; i++)
	{
		if (i == idx - 1)
		{
			new_ele->next = element->next;
			element->next = new_ele;
			return (new_ele);
		}
		else
			element = element->next;
	}
	return (NULL);
}
