#include "main.h"
#include <stdlib.h>

/**
 * *str_concat - concatenates two strings
 * @s1: char param 1
 * @s2: char param 2
 *
 * Return: pointer tp the concatenated strings
 */

char *str_concat(char *s1, char *s2)
{
	char *str_new;
	unsigned int i, j;

	i = 0;
	j = 0;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;

	str_new = malloc(sizeof(char) * (i + j + 1));

	if (str_new == NULL)
		return (NULL);

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		str_new[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str_new[i] = s2[j];
		i++;
		j++;
	}
	str_new[i] = '\0';
	return (str_new);
}
