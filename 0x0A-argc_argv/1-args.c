#include "main.h"
#include <stdio.h>

/**
 * main - entry point
 * @argc: arg count integer
 * @argv: char array of args
 * Return: 0 for success
 */

int main(int argc, char *argv[])
{
	(void)argv;

	printf("%d\n", argc - 1);

	return (0);
}
