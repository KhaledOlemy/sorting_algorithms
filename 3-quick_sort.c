#include "sort.h"
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

/**
 * quick_sort - wrapper function to quick sort
 * @array: array to sort
 * @size: size of the array
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_do(array, 0, size - 1, size);
}

/**
 * quick_sort_do - actual quick sorting function
 * @array: array to sort
 * @low: low boundary to sort starting from
 * @high: high boundary to sort till
 * @size: size to print array
 *
 * Return: Nothing
 */
void quick_sort_do(int *array, int low, int high, size_t size)
{
	int pivot, i;

	if (low < high)
	{
		pivot = low;
		for (i = low; i < high; i++)
		{
			if (array[i] <= array[high])
			{
				if (pivot != i)
				{
					swap(&array[pivot], &array[i]);
					print_array(array, size);
				}
				pivot++;

			}
		}
		if (pivot != high)
		{
			swap(&array[pivot], &array[high]);
			print_array(array, size);
		}
		quick_sort_do(array, low, pivot - 1, size);
		quick_sort_do(array, pivot + 1, high, size);
	}
}
