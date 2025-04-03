#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge - Merge left and right sub-arrays
 * @A: Full array
 * @L: Left sub-array
 * @R: Right sub-array
 * @size: size of full array
 */
void merge(int *A, int *L, int *R, size_t size)
{
	int i = 0, j = 0, k = 0;
	int l = size / 2, r = size - l;

	printf("Merging...\n[left]: ");
	print_array(L, l);
	printf("[right]: ");
	print_array(R, r);

	while (i < l && j < r)
	{
		if (L[i] < R[j])
			A[k++] = L[i++];
		else
			A[k++] = R[j++];
	}
	while (i < l)
		A[k++] = L[i++];
	while (j < r)
		A[k++] = R[j++];
	printf("[Done]: ");
	print_array(A, size);
}

/**
 * merge_sort - Sort array using top-down merge sort
 * @array: Input array
 * @size: Size of array
 */
void merge_sort(int *array, size_t size)
{
	int i, mid = size / 2, left[100], right[100];

	if (!array || size < 2)
		return;

	for (i = 0; i < mid; i++)
		left[i] = array[i];
	for (i = mid; i < (int)size; i++)
		right[i - mid] = array[i];

	merge_sort(left, mid);
	merge_sort(right, size - mid);
	merge(array, left, right, size);
}
