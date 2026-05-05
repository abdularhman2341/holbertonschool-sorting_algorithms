#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Partitions a subarray using the Lomuto scheme
 * @array: The full array (used for printing)
 * @size: Size of the full array
 * @low: Starting index of the partition
 * @high: Ending index of the partition (pivot position)
 *
 * Return: The final index of the pivot after partitioning
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot, i, j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap_ints(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if ((i + 1) != high)
	{
		swap_ints(&array[i + 1], &array[high]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * lomuto_sort - Recursively sorts a partition using quick sort
 * @array: The full array
 * @size: Size of the full array
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 */
void lomuto_sort(int *array, size_t size, int low, int high)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, size, low, high);
		lomuto_sort(array, size, low, pivot_index - 1);
		lomuto_sort(array, size, pivot_index + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using
 *              the Quick sort algorithm (Lomuto partition scheme)
 * @array: The array to be sorted
 * @size: Number of elements in @array
 *
 * Description: Pivot is always the last element of the partition.
 *              Prints the array after each swap.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, (int)size - 1);
}
