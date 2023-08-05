#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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
	int add = 0;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	for (i = 1; i < argc; i++)
	{
		if (!isdigit(*argv[i]))
		{
			printf("Error\n");
			return (1);
		}

		add += atoi(argv[i]);


		/*printf("inloop %d\n", add);*/
	}
	/*printf("outloop %d\n", add);*/
	printf("%d\n", add);

	return (0);
}
