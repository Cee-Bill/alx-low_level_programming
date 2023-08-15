#include "dog.h"

/**
 * init_dog - initializes a variable of type struct dog
 * @d: param 1 | struct pointer dog
 * @name: param 2 | char pointer
 * @age: param 3 | float
 * @owner: param 4 | char pointer
 *
 * Return: Always 0.
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	d->name = name;
	d->age = age;
	d->owner = owner;
}
