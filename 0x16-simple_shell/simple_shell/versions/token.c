#include "tsh.main"

void tokenize_input(char *buffer, char *args[], int *arg_count) {
    char *cmd_tok = strtok(buffer, " ");
    *arg_count = 0;

    while (cmd_tok != NULL) {
        if (*arg_count >= MAX_ARGS) {
            printf("Too many args\n");
            break;
        }
        args[(*arg_count)++] = cmd_tok;
        cmd_tok = strtok(NULL, " ");
    }
    args[*arg_count] = NULL; /* NULL-terminate the args array */
}
