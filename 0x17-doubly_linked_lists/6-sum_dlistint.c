#include "lists.h"

/**
 * sum_dlistint - Returns the sum of all the data in a doubly linked list
 * @head: Pointer to the head of the doubly linked list
 *
 * Return: Sum of all data, or 0 if the list is empty
 */
int sum_dlistint(dlistint_t *head)
{
    int sum = 0;

    while (head)
    {
        sum += head->n;
        head = head->next;
    }

    return (sum);
}