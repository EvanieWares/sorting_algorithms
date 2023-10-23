#include "sort.h"

/**
 * swap_two_ints - swaps two integers
 *
 * @a: the first integer.
 * @b: the second integer.
 */
void swap_two_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - Sorts an array of integers using the Bubble Sort
 * algorithms.
 *
 * @array: The given array to sort.
 * @size: The size of the array. (the number of elements)
 */
void bubble_sort(int *array, size_t size)
{
	size_t len;
	size_t i;
	bool bubbly;

	len = size;
	bubbly = false;
	if (array == NULL || size < 2)
	{
		return;
	}
	while (!bubbly)
	{
		bubbly = true;
		i = 0;
		while (i < len - 1)
		{
			if (array[i] > array[i + 1])
			{
				swap_two_ints(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
			i++;
		}
		len--;
	}
}
