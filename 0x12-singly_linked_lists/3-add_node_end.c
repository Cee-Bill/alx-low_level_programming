#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * str_len - count string
 * @str: string to be counted
 * Return: the count
 */

unsigned int str_len(const char *str)
{
	unsigned int i = 0;

	while (*str)
		str++, i++;
	return (i);
}

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: pointer pointer to the struct list
 * @str: the string data to be added
 * Return: the address of the new element, or NULL if it failed
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *copy_node = *head;
	list_t *node_end = malloc(sizeof(list_t));

	if (node_end == NULL)
		return (NULL);

	node_end->str = strdup(str);
	node_end->len = str_len(str);
	node_end->next = NULL;

	if (*head == NULL)
	{
		*head = node_end;
		return (node_end);
	}

	while (copy_node->next != NULL)
		copy_node = copy_node->next;

	copy_node->next = node_end;

	return (node_end);
}
