#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - entry point
 * @argc: integer arg count
 * @argv: char arrays of passed args
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int a;
	int b, mul;

	if (argc < 3)
	{
		printf("Error\n");
		return (1);
	}

	a = atoi(argv[1]);
	b = atoi(argv[2]);
	mul = a * b;
	printf("%d\n", mul);

	return (0);
}
