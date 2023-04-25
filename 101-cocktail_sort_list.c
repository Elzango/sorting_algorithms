/**
 * cocktail_sort_list - Sorts a doubly linked list using Cocktail Shaker sort algorithm
 * @list: Double pointer to the head of the linked list
 * Arth: Mahmud
 */

void cocktail_sort_list(listint_t **list)
{
    listint_t *left, *right, *curr;
    int swapped = 1;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    while (swapped == 1) {
        swapped = 0;
        for (left = *list; left->next != NULL; left = left->next) {
            if (left->n > left->next->n) {
                if (left == *list)
                    *list = left->next;
                swap_nodes(left, left->next);
                swapped = 1;
                print_list(*list);
            }
        }

        if (swapped == 0)
            break;

        swapped = 0;
        for (right = left->prev; right != NULL; right = right->prev) {
            if (right->prev != NULL && right->n < right->prev->n) {
                swap_nodes(right->prev, right);
                swapped = 1;
                print_list(*list);
            }
        }
    }
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @node1: Pointer to first node
 * @node2: Pointer to second node
 */
void swap_nodes(listint_t *node1, listint_t *node2)
{
    if (node1->prev != NULL)
        node1->prev->next = node2;
    if (node2->next != NULL)
        node2->next->prev = node1;

    node1->next = node2->next;
    node2->prev = node1->prev;

    node1->prev = node2;
    node2->next = node1;
}
