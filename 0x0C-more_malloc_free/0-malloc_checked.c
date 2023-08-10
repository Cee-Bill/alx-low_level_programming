#include "main.h"
#include <stdlib.h>

/**
 * *malloc_checked - allocates memory using malloc
 * @b: integer memory to be allocated
 *
 * Return: Always 0.
 */

void *malloc_checked(unsigned int b)
{
	void *ptr;

	ptr = malloc(b);
	if (ptr != NULL)
		return (ptr);
	exit(98);
}
