#include "shell.h"

/**
 * _find_path - searched for a command in the PATH
 * @info: struct info
 * @_path: char * | PATH
 * @cmd: command to be searched
 * Return: pointer to thecommand's PATH or NULL if not found
 */
char *find_path(info_t *info, char *_path, char *cmd)
{
	char *path;
	int i = 0, _curr_pos = 0;

	if (!_path)
		return (NULL);
	if ((_str_len(cmd) > 2) && _starts_with(cmd, "./"))
	{
		if (_is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!_path[i] || _path[i] == ':')
		{
			path = _dup_chars(_path, _curr_pos, i);
			if (!*path)
				_str_cat(path, cmd);
			else
			{
				_str_cat(path, "/");
				_str_cat(path, cmd);
			}
			if (_is_cmd(info, path))
				return (path);
			if (!_path[i])
				break;
			_curr_pos = i;
		}
		i++;
	}
	return (NULL);
}
