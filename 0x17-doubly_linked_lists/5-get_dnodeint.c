#include "lists.h"

/**
 * get_dnodeint_at_index - Gets the nth node of a doubly linked list
 * @head: Pointer to the head of the doubly linked list
 * @index: Index of the node to retrieve
 *
 * Return: Pointer to the nth node, or NULL if the node does not exist
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
    unsigned int i;

    for (i = 0; head && i < index; i++)
        head = head->next;

    return (head);
}
