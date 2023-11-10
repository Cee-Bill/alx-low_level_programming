#include "lists.h"

/**
 * size_t dlistint_len - returns the length of dlistint_t list
 * @h: pointer to head node
 * Return: the length of nodes.
 */
size_t dlistint_len(const dlistint_t *h)
{
        int nodes = 0;

        if (h == NULL)
                return(nodes);

        while (h != NULL)
        {
                nodes++;
                h = h->next;
        }

        return (nodes);
}
