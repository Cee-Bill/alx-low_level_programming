#include "main.h"

/**
 * _puts_recursion - prints a string, followed by a new line
 * @s: string to be printed
 * Retrun: void
 */

void _puts_recursion(char *s)
{
	if (!*s)
	{
		_putchar('\n');
		return;
	}

	else
	{
		_putchar(*s);
		s++;
		_puts_recursion(s);
	}
}
