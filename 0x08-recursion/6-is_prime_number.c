#include "main.h"
/**
  * is_prime_number - checks if a number is a prime
 * @i: int t
 * @n: the numcer to be checked
 * Return: returns 1 if the input integer is a prime number
 * Otherwise, 0
 */
int prime_check(int n, int i);

int is_prime_number(int n)
{
	return (prime_check(n, 1));
}

/**
 * prime_check - preliminary func
 * @n: the numcer to be checked
 * @i: counter
 * Return: returns 1 if the input integer is a prime number
 * Otherwise, 0
 */

int prime_check(int n, int i)
{
	if (n <= 1)
		return (0);
	if ((n % i == 0) && (i > 1))
		return (0);
	if ((n / i) < i)
		return (1);
	return (prime_check(n, i + 1));
}
