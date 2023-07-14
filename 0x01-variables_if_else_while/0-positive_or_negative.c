#include <stdlib.h>
#include <time.h>
#include<stdio.h>
/**
 * main- program to assign a random number to int n on each run
 * check if n is a positve or a negative integer
 * Return: returns 0 for success
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
		if (n > 0)
	{
		printf("%d is positive\n", n);
	}
	else if (n == 0)
	{
		printf("%d is zero\n", n);
	}
	else if (n < 0)
	{
		printf("%d is negative\n", n);
	}
	return (0);
}