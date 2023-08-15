#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - frees memory allocated to struct dogs
 * @d: param pointer struct d
 *
 * Return: void.
 */
void free_dog(dog_t *d)
{
	if (d)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}
