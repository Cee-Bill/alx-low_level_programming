#include "main.h"

/**
 * _strpbrk - locates the first occurrence in the string s of any of the
 * bytes in the string accept
 * @s: The string to be searched
 * @accept: The set of bytes to be searched for
 * Return: If a set is matched - a pointer to the matched byte
 * NULL if no match is found.
 */

char *_strpbrk(char *s, char *accept)
{
	int i;

	while (*s)
	{
		for (i = 0; accept[i]; i++)
		{
			if (*s == accept[i])
				return (s);
		}

		s++;
	}
	return ('\0');
}
