#include "sort.h"

/**
 * swap_two_ints - Swap two integers in an array.
 *
 * @a: The first integer.
 * @b: The second integer.
 */
void swap_two_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Sorts an array of integers in asceding order using
 * Selection sort algorithm.
 *
 * @array: The given array to sort.
 * @size: The size of the array.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
	{
		return;
	}
	i = 0;
	while (i < size)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
		{
			min = (array[j] < *min) ? (array + j) : min;
		}
		if ((array + i) != min)
		{
			swap_two_ints(array + i, min);
			print_array(array, size);
		}
		i++;
	}

}
