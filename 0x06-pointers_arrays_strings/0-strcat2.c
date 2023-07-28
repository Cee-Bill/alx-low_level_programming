#include "main.h"

/**
 * _strcat - concatenates two strings.
 * @dest: character to be merged to
 * @src: character tomerge with
 * Return: the merged string
 */

char *_strcat(char *dest, char *src)
{
	char x[];
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
	{
		x = dest[i];
		/* _putchar(x); */
		i++;
	}

	while (src != '\0')
	{
		x[i] = src[j];
		j++;
	}

	_putchar('\0');
	Return (x);
}
