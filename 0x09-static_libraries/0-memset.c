#include "main.h"

/**
 * *_memset - fills memory with a constant byte
 * fills the first n bytes of the memory area pointed to by s with the
 * constant byte b
 * @s: pointer memory param to be filled
 * @b: char to copy
 * @n: integer number of times to copy
 * Return: pointer to char s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}

	return (s);
}
