#include "lists.h"
/**
 * print_listint_safe - that prints a listint_t linked list.
 * @head: can print lists with a loop
 * You should go through the list only once
 * If the function fails, exit the program with status 98
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	long int buff;
	size_t num = 0;

	while (head)
	{
		buff = head - head->next;
		num++;
		printf("[%p] %d\n", (void *)head, head->n);
		if (buff > 0)
			head = head->next;
		else
			{
				printf("-> [%p] %d\n", (void *)head->next, head->next->n);
				break;
			}
	}
	return (num);
}

