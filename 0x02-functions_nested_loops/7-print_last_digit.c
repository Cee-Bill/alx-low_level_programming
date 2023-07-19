#include "main.h"
/**
 * print_last_digit - prints the last digit of a number
 * @num: expected integer value
 * Return: r; the last didgit
 */
int print_last_digit(int num)
{
	int r;

	r = num % 10;

	if (r < 0)
	{
		r *= -1;
		_putchar(r + '0');
		return (r);
	}
	else
	{
		_putchar(r + '0');
		return (r);
	}
}
