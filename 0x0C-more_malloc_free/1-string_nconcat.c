#include "main.h"
#include <stdlib.h>
/**
 * *string_nconcat - concatenates two strings
 * @s1: string 1
 * @s2: string 2
 * @n: number of bytes to be taken from s2
 * Return: Always 0.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *ptr;
	unsigned int s1_len = 0, s2_len = 0, len_ = 0, a = 0, b = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s2[s2_len] != '\0')
		s2_len++;
	while (s1[s1_len] != '\0')
		s1_len++;
	if (n >= s2_len)
		len_ = s1_len + s2_len;
	else if (n < s2_len)
		len_ = s1_len + n;

	ptr = malloc((sizeof(char) * len_) + 1);
	if (ptr == NULL)
		return (NULL);
	for (; a < s1_len; a++)
		ptr[a] = s1[a];
	if (n <= s2_len)
	{
		for (; b <= n; b++)
			ptr[a] = s2[b], a++;
	}

	else if (n > s2_len)
	{
		for (; b <= s2_len; b++)
			ptr[a + b] = s2[b];
	}
	ptr[a] = '\0';
	return (ptr);
}
