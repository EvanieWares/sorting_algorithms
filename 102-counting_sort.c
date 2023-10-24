#include "sort.h"

/**
 * get_array - creates a new array
 * @size: size of the new array
 *
 * Return: newly created array
 */
int *get_array(size_t size)
{
	int *array = (int *)malloc(size * sizeof(int));

	if (array == NULL)
	{
		exit(1);
	}
	return (array);
}

/**
 * set_count - sets values to the count array
 * @array: the main array
 * @count: the count array
 * @k: the largest number in the main array
 * @size: size of the main array
 */
void set_count(int *array, int *count, size_t k, size_t size)
{
	size_t i;

	for (i = 0; i <= k; i++)
	{
		count[i] = 0;
	}

	for (i = 0; i < size; i++)
	{
		++count[array[i]];
	}

	for (i = 1; i <= (size_t)k; i++)
	{
		count[i] = count[i] + count[i - 1];
	}
	print_array(count, k + 1);
}

/**
 * get_k - returns the largest number in an array
 * @array: the array
 * @size: size of the array
 *
 * Return: largest number in the array
 */
int get_k(int *array, size_t size)
{
	int k;
	size_t i = 1;

	k = array[0];
	while (i < size)
	{
		if (k < array[i])
		{
			k = array[i];
		}
		i++;
	}
	return (k);
}

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 *
 * @array: the array to sort
 * @size: the size of the array
 */
void counting_sort(int *array, size_t size)
{
	int k, *count, *sorted;
	size_t i;

	if (size < 2)
	{
		return;
	}

	k = get_k(array, size);

	count = get_array(k + 1);
	set_count(array, count, k, size);
	sorted = get_array(size);

	i = size - 1;
	for (i = size - 1; i != SIZE_MAX; i--)
	{
		sorted[--count[array[i]]] = array[i];
	}

	for (i = 0; i < size; i++)
	{
		array[i] = sorted[i];
	}
	free(sorted);
	free(count);
}
