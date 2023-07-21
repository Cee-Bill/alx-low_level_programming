#include <stdio.h>
#include "main.h"

/**
 * main - entry point
 * Description: prints the numbers 1 to 100
 * prints for  multiples of three and buzz for multipples of 5
 * prints fizzbuzz for multiples of both
 * Return: 0 for success
 */

int main(void)
{
	int i;

	for (i = 1; i <= 100; i++)
	{
		if (i % 15 == 0)
			printf("FizzBuzz");
		else if (i % 3 == 0)
			printf("Fizz");
		else if (i % 5 == 0)
			printf("Buzz");
		else
			printf("%i", i);
		if (i < 100)
			printf(" ");
	}
	printf("\n");
	return (0);
}
