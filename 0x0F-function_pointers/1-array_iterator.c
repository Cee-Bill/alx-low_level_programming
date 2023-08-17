#include <stddef.h>
#include "function_pointers.h"

/**
 * array_iterator - executes a function given as a param on each
 * element of an array
 * @array: the array of elements to be eexcuted
 * @size: the array size
 * @action: pointer to the function to be used
 *
 * Return: void.
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i = 0;

	if (array && size && action)
	{
		for (; i < size; i++)
		{
			action(array[i]);
		}
	}
}
