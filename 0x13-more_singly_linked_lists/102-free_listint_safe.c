#include "lists.h"
/**
 * free_listint_safe - that frees a listint_t list.
 * @h: can free lists with a loop
 * You should go though the list only once
 * Return: the size of the list that was free’d
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *element;
	size_t num = 0;
	int buff;

	if (!h || !*h)
		return (0);
	while (*h)
	{
		buff = *h - (*h)->next;
		if (buff > 0)
		{
			element = (*h)->next;
			free(*h);
			*h = element;
			num++;
		}
		else
		{
			free(*h);
			*h = NULL;
			num++;
			break;
		}
	}
	*h = NULL;
	return (num);
}
