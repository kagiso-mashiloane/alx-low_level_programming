#include "lists.h"
/**
 * lists- Finds the number of elements in
 * a linked list_t list.
 * @L: The linked list_t list.
 * Return:  number of elements in h.
 */
size_t list_len(const list_t *h)
{
	size_t noElements = 0;

	while (h)
	{
		noElements++;
		h = h->next;
	}
	return (noElements);
}
