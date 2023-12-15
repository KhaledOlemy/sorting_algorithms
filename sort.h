#ifndef _SORT_H_
#define _SORT_H_
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


void bubble_sort(int *array, size_t size);
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void swap_nodes(listint_t **node1, listint_t **node2);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void swap(int *val1, int *val2);
void quick_sort(int *array, size_t size);
int divide(int array[], int low, int high);
void quick_sort_do(int *array, int low, int high);
#endif
