#include "sort.h"

/**
 * merge - merges two sub-arrays
 *
 * @array: the array to merge to
 * @left: left array
 * @right: right array
 * @l_size: size of the left array
 * @r_size: size of the right array
 */
void merge(int *array, int *left, int *right, size_t l_size, size_t r_size)
{
	size_t i = 0, j = 0, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, l_size);
	printf("[right]: ");
	print_array(right, r_size);

	while (i < l_size && j < r_size)
	{
		if (left[i] <= right[j])
		{
			array[k] = left[i];
			i++;
		}
		else
		{
			array[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < l_size)
	{
		array[k] = left[i];
		i++;
		k++;
	}
	while (j < r_size)
	{
		array[k] = right[j];
		j++;
		k++;
	}
	printf("[Done]: ");
	print_array(array, k);
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 *
 * @array: the array to sort
 * @size: the size of the array
 */
void merge_sort(int *array, size_t size)
{
	size_t i, mid = size / 2;
	int *left, *right, *temp;

	if (size < 2)
	{
		return;
	}

	left = array;
	right = array + mid;

	merge_sort(left, mid);
	merge_sort(right, size - mid);

	temp = (int *)malloc(size * sizeof(int));
	if (temp == NULL)
	{
		exit(1);
	}

	merge(temp, left, right, mid, size - mid);

	for (i = 0; i < size; i++)
	{
		array[i] = temp[i];
	}
	free(temp);
}
