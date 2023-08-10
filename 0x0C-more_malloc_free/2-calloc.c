#include "main.h"
#include <stdlib.h>

/**
 * *_calloc -  allocates memory for an array, using malloc
 * @nmemb: integer for number of elemnts
 * @size: integer | byte size of each element
 *
 * Return: pointer to the allocated memory.
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc(nmemb * size);

	if (ptr == NULL)
		return (NULL);
	*ptr = 0;
	return (ptr);
}
