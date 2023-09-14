#include "hsh.h"

/*
 * main - a custom UNIX command line interpreter
 * @shell_status: int | to determine if the shell has been launched.
 * 1 for on and 0 for off.
 * Return: 0
 */

int main(void)
{
	int shell_status = 1, tok = 0, exec_cmd;
	char *buffer = NULL, *cmd_tok, *buffer_cpy;
	ssize_t user_input;
	size_t buff_size = 0;

	while (shell_status)
	{
		/* Display "ready for use" prompt, $ */
		printf("$ ");

		/* read the inputed command */
		user_input = getline(&buffer, &buff_size, stdin);

		if (!user_input)
		{
			printf("failed\n");
			break;
		}
		else if (user_input == -1)
		{
			printf("exiting shell\n");
			return (-1);
		}
		else if (user_input != -1)
		{
			/*for (i = 0; buffer[i] != '\0'; i++)
			{
				if (buffer[i] == '\n')
				{
					buffer[i] = '\0';
					break;
				}
				printf("buffer[i] : %c\n", buffer[i]);
				}*/
			printf("user_input %ld\n", user_input);
			printf("test string %s\n", buffer);

			/* tokenize input using space as the delim */
			buffer_cpy = malloc(sizeof(char) * (user_input));
			if (buffer_cpy == NULL)
				return (-1);

			strcpy(buffer_cpy, buffer);
			cmd_tok = strtok(buffer_cpy, " ");

			while (cmd_tok != NULL)
			{
				/*tok++;*/
				printf("tok: %d\n", tok);
				printf("token: %s\n", cmd_tok);
				/*cmd_tok = strtok(NULL, " ");*/

				/* execute the command */
				if (tok == 0)
				{
					exec_cmd = execve(cmd_tok, &cmd_tok, NULL);
					if (exec_cmd == -1)
						printf("execve failed");
				}
			}
			tok++;
			cmd_tok = strtok(NULL, " ");

			if (cmd_tok == NULL)
				printf("No more tokens found");

		}
		printf("\n");
	}

	free(buffer_cpy);
	free(buffer);

	return (0);
}
