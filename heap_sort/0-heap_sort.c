#include "sort.h"
/**
 * heapify - create heap
 * @array: input array
 * @size: size of array
 * @i: index
 * @n: full size of array
 */

 
void heapify(int *array, size_t size, int i, size_t n)
{
	int temp, largest = i;
	int l = 2 * i + 1, r = 2 * i + 2;

	if (l < (int)size && array[l] > array[largest])
		largest = l;

	if (r < (int)size && array[r] > array[largest])
		largest = r;

	if (largest != i)
	{
		if (array[i] != array[largest])
		{
			temp = array[i];
			array[i] = array[largest];
			array[largest] = temp;
			print_array(array, n);
		}
		heapify(array, size, largest, n);
	}
}
/**
 * heap_sort - sort array using heap sort
 * @array: input array
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	int i, temp;

	for (i = size / 2 - 1; i >= 0; i--)
	{
		heapify(array, size, i, size);
	}

	for (i = size - 1; i >= 0; i--)
	{
		if (array[0] != array[i])
		{
			temp = array[0];
			array[0] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
		heapify(array, i, 0, size);
	}
}