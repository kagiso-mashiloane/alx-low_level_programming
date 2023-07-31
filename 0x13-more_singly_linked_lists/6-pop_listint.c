#include "lists.h"
/**
 * pop_listint - that deletes the head node of a listint_t,
 * linked list, and returns the head node’s data (n).
 * @head: the first element is linked to pointer list
 * Return: the linked list is empty return 0
 */
int pop_listint(listint_t **head)
{
	listint_t *element;
	int data;

	if (!head || !*head)
		return (0);
	data = (*head)->n;
	element = (*head)->next;
	free(*head);
	*head = element;
	return (data);
}
