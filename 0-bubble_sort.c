#include "sort.h"

/**
 * bubble_sort - sorting an array using bubble sort
 * where we go through the array in 2 nested loops
 * to compare each two numbers and sort them in order
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	bool swapped;

	for (i = 0; i < size; i++)
	{
		swapped = false;
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
				swapped = true;
			}
		}
		if (swapped == false)
			break;
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
