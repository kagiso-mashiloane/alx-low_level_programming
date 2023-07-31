#include "lists.h"
/**
 * add_nodeint_end -  that adds a new node at,
 * the end of a listint_t list.
 * @head:the first element in pointer list
 * @n: insert data in the new element.
 * Return: the address of the new element, or NULL if it failed
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *element = *head;
	listint_t *new_ele;

	new_ele = malloc(sizeof(listint_t));
	if (!new_ele)
		return (NULL);
	new_ele->n = n;
	new_ele->next = NULL;

	if (*head == NULL)
	{
		*head = new_ele;
		return (new_ele);
	}
	while (element->next)
		element = element->next;
	element->next = new_ele;
	return (new_ele);
}
