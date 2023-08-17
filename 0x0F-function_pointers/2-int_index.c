#include <stdio.h>
#include "function_pointers.h"

/**
 * int_index - searches for an integer.
 * @array: array of integers to be searched
 * @size: the number of elements in the array
 * @cmp: pointer to the function to be used to compare values
 *
 * Return: returns the index of the first element for which the cmp function
 * does not return 0, and -1 if no element matches.
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i = 0, ret_val = 0;

	if (size <= 0 || cmp == NULL || array == NULL)
		return (-1);

	for (; i < size; i++)
	{
		cmp(array[i]);
		if (cmp(array[i]) != 0)
		{
			ret_val = i;
			return (ret_val);
		}
	}
	return (-i);
}
