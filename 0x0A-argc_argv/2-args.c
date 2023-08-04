#include <stdio.h>

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
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}

	return (0);
}
