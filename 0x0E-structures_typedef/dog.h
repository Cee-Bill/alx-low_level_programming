#ifndef DOG_H
#define DOG_H

/**
 * struct dog - new struct dog
 * typedef my_dog - replacing struct dog
 * typedef dog_t - replacing my_dog
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

typedef my_dog dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
/*dog_t *new_dog(char *name, float age, char *owner);*/
/*void free_dog(dog_t *d);*/

#endif
