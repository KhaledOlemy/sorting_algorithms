#include "sort.h"
/**
 * quick_sort - wrapper function to quick sort
 * @array: array to sort
 * @size: size of the array
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	srand(time(NULL));
	quick_sort_do(array, 0, size - 1);
}
/**
 * quick_sort_do - actual quick sorting function
 * @array: array to sort
 * @low: low boundary to sort starting from
 * @high: high boundary to sort till
 *
 * Return: Nothing
 */
void quick_sort_do(int *array, int low, int high)
{
	int pivot, pivot_val, i, j;

	if (low < high)
	{
		pivot = low + (rand() % (high - low));
		if (pivot != high)
		{
			swap(&array[pivot], &array[high]);
		}
		pivot_val = array[high];
		i = low;
		for (j = low; j < high; j++)
		{
			if (array[j] <= pivot_val)
			{
				swap(&array[i], &array[j]);
				i++;
			}
		}
		swap(&array[i], &array[high]);
		pivot = i;
		quick_sort_do(array, low, pivot - 1);
		quick_sort_do(array, pivot + 1, high);
	}
}

/**
 * swap - swaps the 2 values in these their memory locations
 *
 * @val1: memory to value 1
 * @val2: memory to value 2
 *
 * Return: Nothing
 */
void swap(int *val1, int *val2)
{
	int temp;

	temp = *val1;
	*val1 = *val2;
	*val2 = temp;
}
