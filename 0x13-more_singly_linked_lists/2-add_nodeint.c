#include "lists.h"
/**
 * add_nodeint - That adds a new node at the,
 * beginning of a listint_t list.
 * @head: pointer to the first node in the list
 * @n: insert in that new node
 * Return:the address of the new element, or NULL if it failed.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_ele;

	new_ele = malloc(sizeof(listint_t));
	if (!new_ele)
		return (NULL);
	new_ele->n = n;
	*head = new_ele;
	new_ele->next = *head;

	return (new_ele);
}
