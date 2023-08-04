#include "main.h"

/**
 * _strncpy - copies a string
 * @dest: pointer to the destination array where the content is to be copied
 * @src: string to be copied
 * @n: param counter
 * Return: dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i, j;

	for (i = 0; dest[i] <= n; i++)
	{
		for (j = 0; (j <= n) & (src[j] != '\0');)
		{
			dest[i] = src[j];
			j++;
		}
		/*i++;*/
		if (n > src[j])
		{
			dest[i] = '\0';
		}
		i++;
	}
	return (dest);
}
