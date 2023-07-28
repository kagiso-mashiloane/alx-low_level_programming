#include <stdio.h>
#include "lists.h"
/**
 * print_list - Prints all the elements of a list_t list.
 * @L: The list_t list.
 * Return:number of nodes in h.
 */
size_t print_list(const list_t *h)
{
	size_t Nnodes = 0;

	while (h)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%d] %s\n", h->len, h->str);
		Nnodes++;
		h = h->next;
	}
	return (Nnodes);
}
