#include "tsh.h"

void execute_command(char *args[]) {
    int exec_cmd = execve(args[0], args, NULL);
    if (exec_cmd == -1) {
        perror("execve failed");
        exit(1);
    }
}
