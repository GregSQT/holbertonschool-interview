#include "search_algos.h"

/**
 * print_array - prints the array after each iteration
 * @array: array to print
 * @start: first index to print
 * @end: last index to print
 */
void print_array(int *array, int start, int end)
{
	int temp;

	printf("Searching in array: ");

	for (temp = start; temp <= end; temp++)
	{
		if (temp != start)
			printf(", ");
		printf("%d", array[temp]);
	}
	printf("\n");

}
/**
 * recur - recursive binary search
 * @array: input array
 * @size: size of array
 * @value: value to search for
 * @first: starting search index
 * @last: ending search index
 * Return: index of first occurance of value, or -1 if not found
 */
int recur(int *array, size_t size, int value, int first, int last)
{
	int middle;

	if (first <= last)
	{
		middle = (first + last) / 2;

		print_array(array, first, last);

		if (array[middle] < value)
			return (recur(array, size, value, middle + 1, last));
		else if (array[middle] > value)
			return (recur(array, size, value, first, middle));
		else if (array[middle] == value)
		{
			if (array[middle - 1] == value)
				return (recur(array, size, value, first, middle));
			return (middle);
		}
	}
	return (-1);
}

/**
 * advanced_binary - entry point
 * @array: array to search
 * @size: size of array
 * @value: value to search for
 * Return: index of value, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);
	return (recur(array, size, value, 0, size - 1));
}
