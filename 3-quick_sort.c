#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using
 *              the Quick sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 * Arth: Mahmud
 */
void quick_sort(int *array, size_t size)
{
    if (array && size > 1)
        quicksort_helper(array, 0, size - 1, size);
}

/**
 * quicksort_helper - The recursive function that implements Quick Sort
 * @array: The array to be sorted
 * @low: The lower bound of the partition being sorted
 * @high: The upper bound of the partition being sorted
 * @size: The size of the entire array
 */
void quicksort_helper(int *array, int low, int high, size_t size)
{
    int pivot;

    if (low < high)
    {
        pivot = partition(array, low, high, size);
        quicksort_helper(array, low, pivot - 1, size);
        quicksort_helper(array, pivot + 1, high, size);
    }
}

/**
 * partition - The function that partitions the array for Quick Sort
 * @array: The array to be sorted
 * @low: The lower bound of the partition being sorted
 * @high: The upper bound of the partition being sorted
 * @size: The size of the entire array
 *
 * Return: The index of the pivot element
 */
int partition(int *array, int low, int high, size_t size)
{
    int pivot, i, j, temp;

    pivot = array[high];
    i = low - 1;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            /* Swap the elements */
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;

            if (i != j)
                print_array(array, size);
        }
    }

    /* Move the pivot to its sorted position */
    temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    if (i + 1 != high)
        print_array(array, size);

    return (i + 1);
}
