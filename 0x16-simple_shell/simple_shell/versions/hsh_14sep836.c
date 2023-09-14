#include "hsh.h"

/*
 * main - a custom UNIX command line interpreter
 * @shell_status: int | to determine if the shell has been launched.
 * 1 for on and 0 for off.
 * Return: 0
 */

int main(void)
{
	int shell_status = 1, tok = 0, i, exec_cmd, _pid_status, arg_count = 0;
	int _max_arg = 64;
	char *buffer = NULL, *cmd_tok;
	char **args = NULL;
	ssize_t user_input;
	size_t buff_size = 0;
	pid_t _pid;

	while (shell_status)
	{
		/* Display "ready for use" prompt, $ */
		printf("$ ");

		/* read the inputed command */
		user_input = getline(&buffer, &buff_size, stdin);

		/* error or EOF is encountered */
		if (user_input == -1)
		{
			printf("exiting shell\n");
			return (0);
		}
		else if (user_input <= 1)
		{
			for (i = 0; i < user_input; i++)
			{
				if (buffer[i] == '\n')
				{
					buffer[i] = '\0';
					break;
				}
				printf("buffer[i] : %c\n", buffer[i]);
			}
			continue;
			printf("user_input %ld\n", user_input);
			printf("test string %s\n", buffer);

			/* tokenize input using space as the delim */
			cmd_tok = strtok(buffer, " ");
			args = malloc((_max_arg + 1) * sizeof(char *));
			if (args == NULL)
			{
				perror("malloc for args failed");
				return (1);
			}

			while (cmd_tok != NULL)
			{
				args[arg_count++] = cmd_tok;
				printf("tok: %d\n", tok);
				printf("token: %s\n", cmd_tok);
				cmd_tok = strtok(NULL, " ");

				if (arg_count >= _max_arg)
				{
					perror("Too many args\n");
					free(args);
					break;
				}
			}
			args[arg_count] = NULL;

				/* forking a child process */
				_pid = fork();

				if (_pid == 0)
				{

					/* execute the command */
					exec_cmd = execve(args[0], args, NULL);
					if (exec_cmd == -1)
					{
						perror("execve failed");
						exit(1);
					}
				}
				else if (_pid > 0)
				{
					/* wait for child process */
					_pid_status = waitpid(_pid, &_pid_status, 0);
				}
				else
					perror("Fork failed");

			}

		/*cmd_tok = strtok(NULL, " ");*/

		free(args);
		/*if (cmd_tok == NULL)
		  printf("No more tokens found");*/

		}
		printf("\n");
		/*return (0);*/

		if (buffer != NULL)
			free(buffer);

		return (0);
}
