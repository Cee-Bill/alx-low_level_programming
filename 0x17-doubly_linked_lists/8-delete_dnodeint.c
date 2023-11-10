#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at a given position in a doubly linked list
 * @head: Pointer to the head of the doubly linked list
 * @index: Index of the node to be deleted, starting at 0
 *
 * Return: 1 if succeeded, -1 if failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *temp, *prev;
    unsigned int i;

    if (!head || !(*head))
        return (-1);

    temp = *head;

    if (index == 0)
    {
        *head = temp->next;
        if (*head)
            (*head)->prev = NULL;
        free(temp);
        return (1);
    }

    for (i = 0; i < index; i++)
    {
        if (!temp)
            return (-1);
        temp = temp->next;
    }

    if (!temp)
        return (-1);

    prev = temp->prev;
    prev->next = temp->next;

    if (temp->next)
        temp->next->prev = prev;

    free(temp);
    return (1);
}
