#include <string.h>
#include "lists.h"

/**
 * add_node_end - Adds a new node at the end
 *	of a list_t list.
 *@head :new node at the end
 *      of a list_t list.
 *@str :char of new node at the end
 *      of a list_t list.
 * Return:  the address of the new element
 * Otherwise - NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	char *dup;
	list_t *new;
	int len;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	dup = strdup(str);
	if (str == NULL)
	{
		free(new);
		return (NULL);
	}
	for (len = 0; str[len];)
		len++;

	new->str = dup;
	new->len = len;
	new->next = *head;

	*head = new;
	return (new);
}
