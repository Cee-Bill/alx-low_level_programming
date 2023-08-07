#include "main.h"
#include <stdlib.h>

/**
 * *_strdup - returns a pointer to a new string which is a duplicate of str
 * @str: the original string to be duplicated
 *
 * Return: a pointer t the new duplicate, or NULL if str is empty
 */

char *_strdup(char *str)
{
	char *str_dup;
	unsigned int i = 0;
	unsigned int j = 0;

	if (!str)
		return (NULL);

	while (str[i])
		i++;

	str_dup = malloc(sizeof(char) * (i + 1));

	if (str_dup == NULL)
		return (NULL);

	for (; str[j]; j++)
	{
		str_dup[j] = str[j];
	}

	return (str_dup);
}
