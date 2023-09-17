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

/**
 * find_builtin - finds a builtin command
 * @info: struct | param struct
 * Return: -1 if builtin not found, 0 if executed successfully,and 1 if found
 * but not successful, and -2 if builtin signals exit()
 */
int find_builtin(info_t *info)
{
	int i, built_in_ret = -1;
	builtin_funcs builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (i = 0; builtintbl[i].type; i++)
	{
		if (_strcmp(info->argv[0], builtintbl[i].type) == 0)
		{
			info->line_count++;
			built_in_ret = builtintbl[i].func(info);
			break;
		}
	}
	return (built_in_ret);
}

/**
 * find_cmd - finds a command in PATH
 * @info: struct param
 * Return: void
 */
void find_cmd(info_t *info)
{
	char *path = NULL;
	int i, k = 0;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}

	for (i = 0; info->arg[i]; i++)
	{
		if (!is_delim(info->arg[i], " \t\n"))
		{
			k++;
		}
	}
	if (!k)
	{
		return;
	}

	path = _find_path(info, _getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		fork_cmd(info);
	}
	else
	{
		if ((check_interactive(info) || _getenv(info, "PATH=") ||
		     info->argv[0][0] == '/') && _is_cmd(info, info->argv[0]))
		{
			fork_cmd(info);
		}
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "not found\n");
		}
	}
}

/**
 * fork_cmd - forks an exec thread to run cmd
 * @info: the parameter & return info struct
 *
 * Return: void
 */
void fork_cmd(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{

			free_info(info, 1);
			exit(126);
		}
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
			{
				print_error(info, "Permission denied\n");
			}
		}
	}
}
