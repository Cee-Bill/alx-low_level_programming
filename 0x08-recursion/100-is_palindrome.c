#include "main.h"

/**
 * strlen_ - string length
 * @s: the string
 * Return: string length | integer
 */

int strlen_(char *s)
{
	if (*s == '\0')
		return (0);
	else
		return (1 + strlen_(s + 1));
}


/**
 * strcompare - string comparison
 * @s: the string
 * @lhs: string from left hand side
 * @rhs: string from right hand side
 * Return: int
 */

int strcompare(char *s, int lhs, int rhs)
{
	if (*(s + lhs) == *(s + rhs))
	{
		if (lhs == rhs || lhs == rhs + 1)
			return (1);
		return (0 + strcompare(s, lhs + 1, rhs - 1));
	}
	return (0);
}


/**
 * is_palindrome - checks if if a string is a palindrome
 * @s: the string
 * Return: int
 */

int is_palindrome(char *s)
{
	if (*s == '\0')
		return (1);
	return (strcompare(s, 0, strlen_(s) - 1));
}
