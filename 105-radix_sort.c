#include "sort.h"

/**
 * radix_sort - sorts an array of integers in ascending order using Radix sort
 * @array: array to sort
 * @size: size of the array
 * Arth: Mahmud
 */
void radix_sort(int *array, size_t size)
{
    int i, j, max_num = 0, digit;
    int *count, *output;

    if (!array || size < 2)
        return;

    /* Find the maximum number in the array */
    for (i = 0; i < (int)size; i++)
        max_num = (array[i] > max_num) ? array[i] : max_num;

    /* Allocate memory for the count and output arrays */
    count = malloc(sizeof(int) * 10);
    output = malloc(sizeof(int) * size);

    /* Loop through each significant digit */
    for (digit = 1; max_num / digit > 0; digit *= 10)
    {
        /* Initialize count array */
        for (i = 0; i < 10; i++)
            count[i] = 0;

        /* Count occurrences of each digit in array */
        for (i = 0; i < (int)size; i++)
            count[(array[i] / digit) % 10]++;

        /* Compute running sum of counts */
        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];

        /* Build output array */
        for (i = (int)size - 1; i >= 0; i--)
        {
            j = (array[i] / digit) % 10;
            output[count[j] - 1] = array[i];
            count[j]--;
        }

        /* Copy output array to input array */
        for (i = 0; i < (int)size; i++)
            array[i] = output[i];

        /* Print array after each significant digit */
        print_array(array, size);
    }

    /* Free memory */
    free(count);
    free(output);
}
