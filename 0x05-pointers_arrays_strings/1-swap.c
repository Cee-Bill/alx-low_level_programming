#include "main.h"

/**
 * swap_int - swaps the values of two integers
 * @a: integer param 1
 * @b: integer param 2
 * Return: 0 for success
 */

void swap_int(int *a, int *b)
{
	int newVal;

	newVal = *a;
	*a = *b;
	*b = newVal;
}
