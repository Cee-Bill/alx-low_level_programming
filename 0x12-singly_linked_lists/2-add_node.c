#include <stdlib.h>
#include <string.h>
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
 * add_node - adds a new node at the beginning of a list
 * @head: pointer to the pointer to the  head node
 * @str: pointer to the new string to be added
 * Return: address of the new element, or NULL if it failed
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node = malloc(sizeof(list_t));

	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->str = strdup(str);
	new_node->len = str_len(str);
	new_node->next = *head;

	*head = new_node;

	return (*head);
}
