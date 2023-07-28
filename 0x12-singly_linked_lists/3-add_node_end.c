#include <string.h>
#include "lists.h"

/**
 * newNodEnd - Adds a new node at the end
 *	of a list_t list.
 * Return:  the address of the new element
 * Otherwise - NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	char *dup;
	int i;
	list_t *new, *last;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	dup = strdup(str);
	if (str == NULL)
	{
		free(new);
		return (NULL);
	}
	for (i = 0; str[i];)
		i++;
	new->str = dup;
	new->i = i;
	new->next = NULL;

	if (*head == NULL)
		*head = new;
	else
	{
		last = *head;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
	return (*head);
}
