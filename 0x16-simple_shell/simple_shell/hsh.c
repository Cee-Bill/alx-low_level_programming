#include "hsh.h"

/*
 * main - a custom UNIX command line interpreter
 * @shell_status: int | to determine if the shell has been launched.
 * 1 for on and 0 for off.
 * Return: 0
 */

int main(void)
{
	int shell_status = 1, exec_cmd, arg_count = 0, _pid_status;
        char *buffer = NULL, *args[MAX_ARGS + 1], *cmd_tok;
        size_t buff_size = 0;
        ssize_t user_input;
        pid_t _pid;
	/*char *envp[] = {"HOME=/","PATH=/bin:/usr/bin", NULL};*/
	char *envp[] = {"PATH=/root/alx-low_level_programming/",NULL};

        while (shell_status) {
                /* Display "ready for use" prompt, $ */
                printf("$ ");

                /* Read the inputed command */
                user_input = getline(&buffer, &buff_size, stdin);

                /* Check for error or EOF */
                if (user_input == -1) {
                        printf("exiting shell\n");
                        break;
                }

                /* Remove the newline character if present */
                if (user_input > 0 && buffer[user_input - 1] == '\n') {
                        buffer[user_input - 1] = '\0';
                }

                /* Tokenize input using space as the delimiter */
                arg_count = 0;
                cmd_tok = strtok(buffer, " ");

                while (cmd_tok != NULL) {
                        if (arg_count >= MAX_ARGS) {
                                printf("Too many args\n");
                                break;
                        }
                        args[arg_count++] = cmd_tok;
                        cmd_tok = strtok(NULL, " ");
                }

                args[arg_count] = NULL; /* NULL-terminate the args array */

                if (arg_count > 0) {
                        /* Fork a child process */
                        _pid = fork();

                        if (_pid == 0) {
                                /* Child process: execute the command */
                                exec_cmd = execve(args[0], &args[0], envp);

                                fprintf(stderr, "line 63\n");
				if (exec_cmd == -1) {
                                        perror("execve failed");
                                        exit(1);
                                }
                        } else if (_pid > 0) {
                                /* Parent process: wait for child process */
				printf("line 70 execcmd%d:\n", exec_cmd);
                                waitpid(_pid, &_pid_status, 0);
                        } else {
                                perror("Fork failed");
                        }
                }

                /* Free dynamically allocated memory */
                free(buffer);
                buffer = NULL;
        }

        return 0;
}
