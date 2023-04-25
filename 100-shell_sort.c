#include "sort.h"
#include <stdio.h>

/**
 * shell_sort - sorts an array of integers in ascending order using
 *              the Shell sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */
void shell_sort(int *array, size_t size)
{
    size_t i, j, gap = 1;
    int tmp;

    if (!array || size < 2)
        return;

    /* Calculate the maximum gap */
    while (gap < size / 3)
        gap = gap * 3 + 1;

    /* Decrease the gap until it becomes 1 */
    for (; gap >= 1; gap = (gap - 1) / 3)
    {
        /* Perform insertion sort with current gap */
        for (i = gap; i < size; i++)
        {
            tmp = array[i];
            for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
                array[j] = array[j - gap];
            array[j] = tmp;
        }
        print_array(array, size);
    }
}

