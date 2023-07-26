#include <stdio.h>

/**
 * print_array - prints n elements of an array of integers
 * @a: integer input param
 * @n: array length
 * Return: the array elemnts
 */

void print_array(int *a, int n)
{
	int array_index;

	for (array_index = 0; array_index < n; array_index++)
	{
		printf("%d", a[array_index]);
		if (array_index != (n - 1))
		{
			printf(", ");
		}
	}
	putchar('\n');
}
