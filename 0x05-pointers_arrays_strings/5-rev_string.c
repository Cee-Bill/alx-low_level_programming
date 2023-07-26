#include "main.h"

/**
 * rev_string - reverses a string
 * @s: string to be reversed
 * Return: reversded string
 */

void rev_string(char *s)
{
	int len, a, half;
	char len2;

	for (len = 0; s[len] != '\0'; len++)
		;
	a = 0;
	half = len / 2;

	while (half--)
	{
		len2 = s[len - a - 1];
		s[len - a - 1] = s[a];
		s[a] = len2;
		a++;
	}
}
