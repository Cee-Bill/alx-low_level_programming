#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/**
 * main- program to assign a random number of int n and compare the last digit
 * with 0, 5, 6
 * int last_n holds the last digit of int_n
 * Return: returns 0 for success
 */
int main(void)
{
	int n;
	int last_n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	last_n = n % 10;
	if (last_n > 5)
		printf("Last digit of %d is %d and is greater than 5\n",
		n, last_n);
	else if (last_n == 0)
		printf("Last digit of %d is %d and is 0\n", n, last_n);
	else if (last_n < 6)
		printf("Last digit of %d is %d and is less than 6 and not 0\n",
		n, last_n);
	return (0);
}
