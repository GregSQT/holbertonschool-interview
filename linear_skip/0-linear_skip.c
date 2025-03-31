#include "search.h"
#include <stdio.h>

/**
 * linear_skip - linear search in a skip list
 * @list: skip list
 * @value: value to search for
 * Return: node with value or null if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *express, *prev, *end;

	if (!list || !list->express)
		return (NULL);
	express = list->express;
	prev = list;
	while (express)
	{
		printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
		if (express->n >= value)
		{
			printf("Value found between indexes [%lu] and [%lu]\n",
					prev->index, express->index);
			break;
		}
		else if (express->express == NULL)
		{
			end = express;
			while (end->next != NULL)
				end = end->next;
			printf("Value found between indexes [%lu] and [%lu]\n",
					express->index, end->index);
		}
		prev = express;
		express = express->express;
	}
	while (prev != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}
	return (NULL);
}
