#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void bitonic_merge(int *array, int low, int cnt, int dir);

void bitonic_sort_recursive(int *array, int low, int cnt, int dir)
{
    if (cnt > 1)
    {
        int k = cnt / 2;
        bitonic_sort_recursive(array, low, k, !dir);
        bitonic_sort_recursive(array, low + k, cnt - k, dir);
        bitonic_merge(array, low, cnt, dir);
    }
}

void bitonic_merge(int *array, int low, int cnt, int dir)
{
    if (cnt > 1)
    {
        int k = cnt / 2;
        for (int i = low; i < low + k; i++)
        {
            if ((array[i] > array[i + k]) == dir)
            {
                int temp = array[i];
                array[i] = array[i + k];
                array[i + k] = temp;
            }
        }
        bitonic_merge(array, low, k, dir);
        bitonic_merge(array, low + k, cnt - k, dir);
    }
}

void bitonic_sort(int *array, size_t size)
{
    bitonic_sort_recursive(array, 0, size, 1);
}

int main()
{
    int array[] = {1, 3, 2, 6, 5, 8, 7, 9};
    size_t size = sizeof(array) / sizeof(array[0]);

    printf("Original array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    bitonic_sort(array, size);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
