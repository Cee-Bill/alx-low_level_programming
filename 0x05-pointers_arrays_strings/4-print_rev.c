#include "main.h"

/**
 * print_rev - prints a string, in reverse
 * @s: string param to be reversed
 * Return: reversed string
 */

void print_rev(char *s)
{
	int str_len = 0;

	while (s[str_len] != '\0')
	{
		str_len++;
	}

	while (str_len--)
	{
		_putchar(s[str_len]);
	}
	_putchar('\n');
}
