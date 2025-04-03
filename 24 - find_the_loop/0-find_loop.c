#include "lists.h"
/**
 * find_listint_loop - looks for loop in linked list
 * @head: head node of linked list
 * Return: first node of loop, or NULL if no loop exists
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *a = head;
	listint_t *b = head;

	while (b && b->next)
	{
		a = a->next;
		b = b->next->next;

		if (a == b)
			break;
	}

	if (a != b)
		return (NULL);

	a = head;

	while (a != b)
	{
		a = a->next;
		b = b->next;
	}

	return (a);
}
