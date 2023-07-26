#include "main.h"

/**
 * puts_half - prints half of a string
 * @str: string to be printed
 * Return: the half string
 */

void puts_half(char *str)
{
	int full, half;

	full = 0;
	while (str[full] != '\0')
	{
		full++;
	}

	half = full / 2;

	if (half < full)
	{
		_putchar(str[half]);
		half++;
	}
	_putchar('\n');
}
