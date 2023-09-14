#include "tsh.h"

int main(void) {
    int shell_status = 1;
    char *buffer = NULL;
    char *args[MAX_ARGS + 1];  // +1 for the NULL terminator
    int arg_count = 0;
    size_t buff_size = 0;
    ssize_t user_input;
    pid_t _pid;
    int _pid_status;

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

        tokenize_input(buffer, args, &arg_count);

        if (arg_count > 0) {
            /* Fork a child process */
            _pid = fork();

            if (_pid == 0) {
                /* Child process: execute the command */
                execute_command(args);
            } else if (_pid > 0) {
                /* Parent process: wait for child process */
                waitpid(_pid, &_pid_status, 0);
            } else {
                perror("Fork failed");
            }
        }
