#include <stdio.h>

void first() __attribute__((constructor));

/**
 * first - prints a string before the main function is executed.
 * Return: void
 */

void first(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
