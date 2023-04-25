#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in
 *                        ascending order using the Insertion sort algorithm
 * @list: The list to be sorted
 * Arth: Mahmud
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *curr, *temp;

    if (!list || !*list || !(*list)->next)
        return;

    curr = (*list)->next;

    while (curr != NULL)
    {
        temp = curr->prev;

        while (temp != NULL && temp->n > curr->n)
        {
            /* Swap the nodes */
            if (temp->prev != NULL)
                temp->prev->next = curr;
            else
                *list = curr;

            curr->prev = temp->prev;
            temp->prev = curr;
            temp->next = curr->next;

            if (curr->next != NULL)
                curr->next->prev = temp;

            curr->next = temp;
            print_list(*list);

            temp = curr->prev;
        }
        curr = curr->next;
    }
}
