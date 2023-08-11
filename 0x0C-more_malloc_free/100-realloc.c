#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * *_realloc - reallocates a memory block using malloc and free
 * @ptr: void | the address of memory to be re-allocated
 * @old_size: unsigned in | size in bytes, of the allocated space for ptr
 * @new_size: unsigned in | size, in bytes of the new memory block
 * Return: Nothing.
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *ptr_new;

	unsigned int i;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		ptr_new = malloc(new_size);
		if (ptr_new == NULL)
			return (NULL);
		return (ptr_new);
	}

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	ptr_new = malloc(new_size);
	if (ptr_new == NULL)
		return (NULL);

	for (i = 0; i < old_size && i < new_size; i++)
		((char *)ptr_new)[i] = ((char *)ptr)[i];

	free(ptr);
	return (ptr_new);
}
