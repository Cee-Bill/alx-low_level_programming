#include "main.h"

/**
 * print_number - print integers
 * @n: expected integer to be printed
 * Return: 0 for success
 */

void print_number(int n)
{
	if (n >= 9)
	{
		_putchar(n / 10);
		_putchar(n % 10);
	}
	else if (n < 0)
	{
		n = -n;
		if (n <= 9)
		{
			_putchar('-');
			_putchar(n);
		}
		else
		{
			_putchar('-');
			_putchar(n / 10);
			_putchar(n % 10);
		}
	}
	else if (n == 0)
		_putchar(n);

	_putchar('\n');
}
