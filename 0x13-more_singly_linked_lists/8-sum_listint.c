#include "lists.h"
/**
 * sum_listint -  that returns the sum of all the,
 * data (n) of a listint_t linked list
 * @head: listint_t linked list.
 * Return: Return 0
 */
int sum_listint(listint_t *head)
{
	 listint_t *element = head;
	int sum = 0;

	while (element)
	{
		sum += element->n;
		element = element->next;
	}
	return (sum);
}
