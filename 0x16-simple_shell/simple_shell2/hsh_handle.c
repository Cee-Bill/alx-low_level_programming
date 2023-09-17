#include "shell.h"

/**
 * hsh_handle - mhandle execution of shell commands
 * @info: struct | command arg
 * @argv: char * | arg vector
 * Return: 0 if successful, and 1 if failed
 */
int hsh_handle(info_t *info, char **argv)
{
	ssize_t _read = 0;
	int _builtin = 0;

	while (_read != -1 && _builtin != -2)
	{
		info_clear(info);
		if (check_interactive(info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		_read = read_line(info);
		if (_read != -1)
		{
			set_info(info, argv);
			_builtin = find_builtin(info);
			if (_builtin == -1)
				find_cmd(info);
		}
		else if (check_interactive(info))
			_putchar('\n');
		free_info(info, 0);
	}
	write_history(info);
	free_info(info, 1);
	if (!check_interactive(info) && info->status)
		exit(info->status);
	if (_builtin == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (_builtin);
}
