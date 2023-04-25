#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers using the counting sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 * Arth: Mahmud
 */
void counting_sort(int *array, size_t size)
{
    int max_value = 0, i;
    int *counting_array, *sorted_array;

    /* Find the largest value in the array */
    for (i = 0; i < (int) size; i++)
    {
        if (array[i] > max_value)
            max_value = array[i];
    }

    /* Create a counting array with k + 1 elements */
    counting_array = malloc(sizeof(int) * (max_value + 1));
    if (!counting_array)
        return;

    /* Initialize the counting array with 0's */
    for (i = 0; i <= max_value; i++)
        counting_array[i] = 0;

    /* Count the occurrences of each value in the array */
    for (i = 0; i < (int) size; i++)
        counting_array[array[i]]++;

    /* Modify the counting array to include the number of values less than each element */
    for (i = 1; i <= max_value; i++)
        counting_array[i] += counting_array[i - 1];

    /* Create a sorted array with the same size as the original array */
    sorted_array = malloc(sizeof(int) * size);
    if (!sorted_array)
    {
        free(counting_array);
        return;
    }

    /* Sort the array by iterating over it backwards and using the counting array */
    for (i = (int) size - 1; i >= 0; i--)
    {
        sorted_array[counting_array[array[i]] - 1] = array[i];
        counting_array[array[i]]--;
    }

    /* Copy the sorted array back into the original array */
    for (i = 0; i < (int) size; i++)
        array[i] = sorted_array[i];

    /* Print the counting array */
    printf("Counting array: ");
    print_array(counting_array, max_value + 1);

    /* Free the memory used by the arrays */
    free(counting_array);
    free(sorted_array);
}
