#include "sort.h"
/**
 * merge_compare - core of merge sort algorithm, this function does all
 * the comparisons.
 * @array: array to be sorted
 * @buffer: buffer to store the sorted elements in the array in temporarily
 * @start: beginning of the left part
 * @mid: mid point, end of left part, start of the right part
 * @end: end of right part
 *
 * Return: Nothing.
 */
void merge_compare(int *array, int *buffer, size_t start, size_t mid,
size_t end)
{
	size_t i, j, buff = 0;

	printf("Merging...\n[left]: ");
	print_array(array + start, mid - start);
	printf("[right]: ");
	print_array(array + mid, end - mid);

	i = start;
	j = mid;
	for (; i < mid && j < end; buff++)
	{
		if (array[i] < array[j])
		{
			buffer[buff] = array[i];
			i++;
		}
		else
		{
			buffer[buff] = array[j];
			j++;
		}
	}
	for (; i < mid; i++)
	{
		buffer[buff] = array[i];
		buff++;
	}
	for (; j < end; j++)
	{
		buffer[buff] = array[j];
		buff++;
	}
	buff = 0;
	for (i = start; i < end; i++)
	{
		array[i] = buffer[buff];
		buff++;
	}
	printf("[Done]: ");
	print_array(array + start, end - start);
}
/**
 * merge_sort_do - recursive approach for merge sort algorithm,
 * here array is divided into halves recursively.
 * @array: array to be sorted.
 * @buffer: buffer to store the sorted array in temporarily
 * @start: start point of the left part
 * @end: end point of the right part
 *
 * Return: Nothing.
 */
void merge_sort_do(int *array, int *buffer, size_t start, size_t end)
{
	size_t mid;

	if ((end - start) <= 1)
	{
		return;
	}
	mid = start + (end - start) / 2;
	merge_sort_do(array, buffer, start, mid);
	merge_sort_do(array, buffer, mid, end);
	merge_compare(array, buffer, start, mid, end);
}
/**
 * merge_sort - wrapper function for merge_sort_do, this is the start point of
 * merge sorting algorithm
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: Nothing.
*/
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || !*array || size < 2)
		return;
	buffer = malloc(sizeof(int) * (int) size);
	if (!buffer)
	{
		return;
	}
	merge_sort_do(array, buffer, 0, size);
	free(buffer);
}
