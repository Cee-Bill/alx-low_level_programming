#include "main.h"
#include <stdio.h>

/**
* _strlen_recursion - returns the length of a string
* @s: string to be counted
* Return: length- interger
*/

int _strlen_recursion(char *s)
{
	int n = 0;

	if (*s == '\0')
		return (0);

	if (*s != '\0')
	{
		n++;
		return (n + _strlen_recursion(s + 1));

	}
	return (n);
}
