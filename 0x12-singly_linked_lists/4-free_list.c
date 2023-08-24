#include <stdlib.h>
#include "lists.h"

/**
 * free_list - frees a list_t list
 * @head: the struct list to be freed;
 */

void free_list(list_t *head)
{
	list_t *node_curr;

	(void) node_curr;

	while (head)
	{
		node_curr = head->next;
		free(head->str);
		free(head);
		head = node_curr;
	}
}
