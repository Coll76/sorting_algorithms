#include "sort.h"
/**
 * swap - swaps values
 * @a: first value
 * @b: second value
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * lomuto_partition - performs lomuto partition
 * @high: ending index of array
 * @low: starting index of current partition
 * @arr: array to partition
 * Return: index of pivot
 */
int lomuto_partition(size_t high, size_t low, int *arr)
{
	size_t i, j;
	int pivot;

	pivot = arr[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
		i++;
		swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}
/**
 * quick_sorthelper - helper for quick sort
 * @high: ending index of array
 * @low: starting index of current partition
 * @arr: array to find pivot
 */
void quick_sorthelper(int low, int high, int *arr)
{
	if (low < high)
	{
	size_t pivot_index = lomuto_partition(high, low, arr);

	print_array(arr + low, high - low + 1);
	quick_sorthelper(low, pivot_index - 1, arr);
	quick_sorthelper(pivot_index + 1, high, arr);
	}
}
/**
 * quick_sort - function that sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	quick_sorthelper(0, size - 1, array);
}
