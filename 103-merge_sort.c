#include <stdio.h>
#include <stdlib.h>

/**
 * merge - Merges two sub-arrays of array[]
 * @array: Pointer to the first element of the array
 * @low: Starting index of the first sub-array
 * @mid: Ending index of the first sub-array
 * @high: Ending index of the second sub-array
 * @temp: Temporary array used for sorting
 * Arth: Mahmud
 */
void merge(int *array, int low, int mid, int high, int *temp)
{
    int i = low, j = mid + 1, k = 0;

    while (i <= mid && j <= high)
    {
        if (array[i] <= array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }

    while (i <= mid)
        temp[k++] = array[i++];

    while (j <= high)
        temp[k++] = array[j++];

    for (i = low, k = 0; i <= high; i++, k++)
        array[i] = temp[k];
}

/**
 * merge_sort - Sorts an array of integers in ascending order using the Merge sort algorithm
 * @array: Pointer to the first element of the array
 * @size: Size of the array
 * @temp: Temporary array used for sorting
 */
void merge_sort_helper(int *array, size_t size, int *temp)
{
    int mid, i;

    if (size < 2)
        return;

    mid = size / 2;

    merge_sort_helper(array, mid, temp);
    merge_sort_helper(array + mid, size - mid, temp);

    merge(array, 0, mid - 1, size - 1, temp);

    printf("Merging...\n[left]: ");
    for (i = 0; i < mid; i++)
        printf("%d ", array[i]);
    printf("\n[right]: ");
    for (i = mid; i < size; i++)
        printf("%d ", array[i]);
    printf("\n[Done]: ");
    for (i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void merge_sort(int *array, size_t size)
{
    int *temp;

    if (size < 2 || array == NULL)
        return;

    temp = malloc(size * sizeof(int));

    if (temp == NULL)
        return;

    merge_sort_helper(array, size, temp);

    free(temp);
}
