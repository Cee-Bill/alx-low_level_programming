#include "main.h"
#include <stdlib.h>

/**
 * **alloc_grid - returns a pointer to a 2 dimensional array of integers
 * @width: int param 1
 * @height: int param 2
 * Return: integer pointer to the array or NULL if either param is 0.
 */

int **alloc_grid(int width, int height)
{
	int **_2d_arr;
	int i, j;

	if (width <= 0 || height <= 0)
		return  (NULL);

	_2d_arr = (int **) malloc(sizeof(int *) * height);

	if (_2d_arr == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		_2d_arr[i] = (int *) malloc(sizeof(int) * width);
		if (_2d_arr[i] == NULL)
		{
			free(_2d_arr);
			for (; i >= 0; i--)
				free(_2d_arr[i]);
			return (NULL);
		}
	}
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
			_2d_arr[i][j] = 0;
	}
	return (_2d_arr);
}
