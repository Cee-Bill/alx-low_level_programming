#include "main.h"
/**
 * _islower- checks for lowercase character.
 * @c: expected ASCII character
 * Return: 1 if lowercase is found, and 0 if otherwise
 */
int _islower(int c)
{
	if (c >= 97 && c <= 122)
	{
		return (1);
	}
	else
	{
		return (0);
	}
	_putchar('\n');
}
