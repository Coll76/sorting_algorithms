#include "sort.h"
/**
 * swap - swaps values
 * @a: first value
 * @b: second value
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * selection_sort - sorts an array of integers in
 * ascending order using the Selection sort algorithm
 * @array: array of integers
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
	for (j = i + 1; j < size; j++)
	{
		if (array[j] < array[min])
		{
		min = j;
		continue;
		}
	}
		if (min != i)
		{
		swap(&array[i], &array[min]);
		print_array(array, size);
		}
	}
}
