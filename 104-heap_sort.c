#include "sort.h"

/**
 * sift_down - Repair the heap whose root element is at index 'start'
 * @array: The array to sort
 * @size: Number of elements in @array
 * @start: The root index of the heap to repair
 * @end: The max index of the heap section being sorted
 * Arth: Mahmud
 */
void sift_down(int *array, size_t size, size_t start, size_t end)
{
	size_t root = start, child, swap;
	int temp;

	while (2 * root + 1 <= end)
	{
		child = 2 * root + 1;
		swap = root;

		if (array[swap] < array[child])
			swap = child;
		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;
		if (swap == root)
			return;
		temp = array[root];
		array[root] = array[swap];
		array[swap] = temp;
		print_array(array, size);
		root = swap;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using the Heap sort algorithm
 * @array: The array to sort
 * @size: Number of elements in @array
 */
void heap_sort(int *array, size_t size)
{
	size_t start, end;

	if (!array || size < 2)
		return;
	for (start = (size - 2) / 2; start > 0; start--)
		sift_down(array, size, start, size - 1);
	sift_down(array, size, 0, size - 1);
	for (end = size - 1; end > 0; end--)
	{
		int temp = array[end];
		array[end] = array[0];
		array[0] = temp;
		print_array(array, size);
		sift_down(array, size, 0, end - 1);
	}
	int temp = array[end];
	array[end] = array[0];
	array[0] = temp;
	print_array(array, size);
}
