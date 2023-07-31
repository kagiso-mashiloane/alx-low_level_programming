#include "lists.h"
/**
 * print_listint - prints all the elements of,
 * a listint_t list
 * @h: the type list of  listint_t to print
 * Return:the  number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t len = 0;

	while (h)
	{
		h = h->next;
		len++;
		printf("%d\n", h->n);
	}
	return (len);
}
