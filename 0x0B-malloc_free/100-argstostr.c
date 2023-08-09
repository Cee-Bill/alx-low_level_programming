#include "main.h"
#include <stdlib.h>

/**
 * *argstostr - concatenates all the arguments of this program.
 * @ac: int argument count
 * @av: char array of arguments
 *
 * Return: pointer to the concatenated string or NULL if it fails
 */

char *argstostr(int ac, char **av)
{
	int i, j, counter, x;
	char *strtoprt;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
			counter++;
		counter++;
	}
	counter += ac;
	strtoprt = malloc(sizeof(char) * (counter));

	if (strtoprt == NULL)
		return (NULL);

	x = 0;
	/*i = 0;*/

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++)
		{
			strtoprt[x] = av[i][j];
			x++;
		}

		strtoprt[x++] = '\n';
		/*x++;*/
	}
	return (strtoprt);
}
