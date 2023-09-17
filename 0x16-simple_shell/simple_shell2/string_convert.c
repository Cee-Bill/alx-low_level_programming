#include "shell.h"

/**
 * _atoi - string to int conversion.
 * @s: char * | str to be converted
 * Return: int | char count of the string, or 0 if failed
 */

int _atoi(char *s)
{
	int i = 0, sign = 1, output = 0;

	while (s[i] == ' ' || s[i] == '\t')
		i++;

	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}

	while (s[i] >= '0' && s[i] <= '9')
	{
		output = output * 10 + (s[i] - '0');
		i++;
	}
	return (output * sign);
}

/**
 * check_interactive - check if in interactive mode
 * @info: def struct | &info
 * Return: 1 if true, and 0 if not
 */

int check_interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}


/**
 * is_delim - checks for delim char
 * @c: char to be check
 * @delim: char * | delim
 * Return: 1 if true and 0 if not
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
		{
			return (1);
		}
	return (0);
}

/**
 * _isalpha - checks for alpha char
 * @c: char
 * Return: 1 if alpha char and 0 if not
 */

int _isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}


/**
 * _str_len - calculates string length
 * @s: char | string to be counted
 * Return: int | length count
 */

int _str_len(char *s)
{
	int len = 0;

	if (!s)
		return (0);

	for (; s[len] != '\0'; len++)
		continue;
	return (len);
}
