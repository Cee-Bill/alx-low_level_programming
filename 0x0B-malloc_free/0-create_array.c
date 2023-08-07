#include "main.h"
#include <stdlib.h>

/**
 * *create_array - creates an array of chars, and initializes it with a /
 * specific char
 * @c: the character to be initialized
 * @size: array size
 *
 * Return: pointer to the array or NULL if it fails
 */

char *create_array(unsigned int size, char c)
{
	char *str_array;
	unsigned int i;

	str_array = malloc(sizeof(char) * size);

	if (size == 0 || str_array == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < size; i++)
	{
		str_array[i] = c;
	}
	return (str_array);
}
