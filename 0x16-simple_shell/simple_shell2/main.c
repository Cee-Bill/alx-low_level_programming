#include "shell.h"

/**
 * str_to_words - splits strings into words and ignores repeated delims
 * @str: the input string
 * @d: the delimiter string
 * Return: pointer to an array of strings
 * or NULL on failure
 */

char **str_to_words(char *str, char *d)
{
	int i, j, k, m, _num_words = 0;
	char **s;

	if (str == NULL || str[0] == '\0')
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; str[i] != '\0'; i++)
	{
		if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) ||
		     str[i + 1] == '\0'))
			_num_words++;
	}
	if (_num_words == 0)
		return (NULL);
	s = malloc((_num_words + 1) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < _num_words; j++)
	{
		while (is_delim(str[i], d))
		       i++;
		k = 0;
		while (!is_delim(str[i + k], d) && str[i + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = '\0';
	}
	s[j] = NULL;
	return (s);
}

/* *
 * **strtow2 - splits a string into words
 * @str: the input string
 * @d: the delimiter
 * Return: a pointer to an array of strings, or NULL on failure
 */
/*
char **strtow2(char *str, char d)
{
    int i, j, k, m, numwords = 0;
    char **s;

    if (str == NULL || str[0] == '\0')
        return NULL;

    for (i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] != d && str[i + 1] == d) ||
            (str[i] != d && !str[i + 1]) || str[i + 1] == d)
            numwords++;
    }

    if (numwords == 0)
        return NULL;

    s = malloc((numwords + 1) * sizeof(char *));
    if (!s)
        return NULL;

    for (i = 0, j = 0; j < numwords; j++)
    {
        while (str[i] == d)
            i++;

        k = 0;
        while (str[i + k] != d && str[i + k] && str[i + k] != d)
            k++;

        s[j] = malloc((k + 1) * sizeof(char));
        if (!s[j])
        {
            for (k = 0; k < j; k++)
                free(s[k]);

            free(s);
            return NULL;
        }

        for (m = 0; m < k; m++)
            s[j][m] = str[i++];

        s[j][m] = '\0';
    }

    s[j] = NULL;
    return s;
}
*/

/**
 * _free - frees allocated memory
 * @ptr: &pointer to free
 * Return: 1 if successful, and otherwise, 0.
 */
int _free(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

/**
 * main - entry point of this custom shell
 * @argc: int | arguement count
 * @argv: char * | array pointer to list of provided arguments
 * Return: 0 on success and 1 on error.
 * Decription: this shell will handle both interactive and
 * non-interactive modes, parse user input and execute commands, and also
 * peform error handling and environment variable handling.
 */

int main(int argc, char **argv)
{
	info_t _info;
	/* info_t _info[] = { INFO_INIT };*/
	int fd = 2;

	fd += 3;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				fprintf(stderr, "%s: 0: Can't open %s\n",
					argv[0], argv[1]);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		_info.readfd = fd;
	}
	get_env_list(&_info);
	list_history(&_info);
	hsh(&_info, argv);

	return (EXIT_SUCCESS);
}
