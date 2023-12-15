#include "sort.h"
/**
 * selection_sort - sorting array using selection sort
 * @array: array to sort
 * @size: size of the array
 *
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		if (min == i)
		{
			continue;
		}
		swap(&array[i], &array[min]);
		print_array(array, size);
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
