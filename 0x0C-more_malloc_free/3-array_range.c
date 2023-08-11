#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * *array_range - creates an array of integers.
 * @min: param 1 for minimum integer value
 * @max: param 2 for maximum integer value
 * Return: pointer to the newly created array
 */

int *array_range(int min, int max)
{
	int *ptr;
	int i, j = 0, len = 0;

	if (min > max)
		return (NULL);

	len = (max - min) + 1;

	ptr = malloc(sizeof(int) * len);
	if (ptr == NULL)
		return (NULL);

	else
	{
		for (i = min; i <= max; i++)
		{
			ptr[j] = i;
			j++;
		}
	}

	return (ptr);
}
