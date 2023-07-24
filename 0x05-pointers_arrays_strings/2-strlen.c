#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: string to be calculated
 * Return: string length
 */

int _strlen(char *s)
{
	int str_len = 0;

	while (*s != '\0')
	{
		str_len++;
		s++;
	}
	return (str_len);
}
