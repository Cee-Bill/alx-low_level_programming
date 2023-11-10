#include "lists.h"

/**
 * print_dlistint - prints all the elements of a dlistint_t list
 * @h: pointer to head node
 * Return: the number of nodes.
 */
size_t print_dlistint(const dlistint_t *h)
{
    int nodes = 0;

    if (h == NULL)
        return(nodes);

    while (h != NULL)
                {
                        printf("%d\n", h->n);
                        nodes++;
                        h = h->next;
                }

        return (nodes);
}
