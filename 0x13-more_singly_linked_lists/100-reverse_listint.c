#include "lists.h"
/**
 * reverse_listint - that reverses a listint_t linked list
 * @head: listint_t linked list
 * Return: a pointer to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *later = NULL;
	listint_t *next = NULL;

	while (*head)
	{
		next = (*head)->next;
		(*head)->next = later;
		later = *head;
	*head = next;
	}
	*head = later;
	return (*head);
}
