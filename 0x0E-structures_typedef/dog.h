#ifndef DOG_H
#define DOG_H

/**
 * struct dog - new struct dog
 * typedef my_dog - replacing struct dog
 * @name: member 1 |char *
 * @age: member 2 | int
 * @owner: member 3 | char *
 */

typedef struct dog
{
	char *name;
	float age;
	char *owner;
} my_dog;

#endif
