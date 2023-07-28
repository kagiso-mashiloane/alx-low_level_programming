#include "lists.h"
/**
 * list_len - Finds the number of elements in
 * a linked list_t list.
 * @h: number of elements in list_t list.
 * Return: the number of elements in,
 * a linked list_t list.
 */
size_t list_len(const list_t *h)
{
	size_t elements_no = 0;

	while (h)
	{
		elements_no++;
		h = h->next;
	}
	return (elements_no);
}
