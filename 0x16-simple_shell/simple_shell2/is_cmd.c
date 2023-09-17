#include "shell.h"

/**
 * _is_cmd - checks if file/comand is executable
 * @info: the info struct
 * @path: path to the file
 * Return: 1 if tru or 0 if otherwise
 */

int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
	{
		return (0);
	}

	if (st.st_mode & S_IFREG)
		return (1);

	return (0);
}
