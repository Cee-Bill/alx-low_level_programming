#include "shell.h"

/**
 * *_strn_cat - string concatenation
 * @dest: the first string
 * @src: the second string
 * @n: the amount of bytes to be maximally used
 * Return: the concatenated string
 */
char *_strn_cat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0, j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++, j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}


/**
 * *_str_chr - char finder
 * @s: string to be searched
 * @c: char to be found
 * Return: pointer to s
 */

char *_str_chr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}




/**
 * *_strn_cpy - makes a copy of a string
 * @dest: char * | destination string
 * @src: char * | source string
 * @n: int | char count to be copied
 * Return: concatenated string
 */
char *_strn_cpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}
