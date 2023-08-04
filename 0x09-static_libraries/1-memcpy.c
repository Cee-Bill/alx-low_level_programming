#include "main.h"

/**
 * *_memcpy - function copies n bytes from memory area src to memory area dest
 * @dest: char dest location to be stored
 * @src: char from memory area
 * @n: unsigned int number of bytes
 * Return: pointer to dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		dest[i] = src[i];
			i++;
	}
	return (dest);
}
