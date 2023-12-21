#include "shell.h"
/**
 *
 *
 *
 */
int cmd_exist(char **tokens, char **env)
{
    int status;
    pid_t child_pid;
    struct stat buffer;
    char *path_tok, *cmd[100];

    if (stat(tokens[0], &buffer) != 0)
    {
        path_tok = path(env);
        getTokens(path_tok, cmd, ":");
        tokens[0] = add_path(tokens, cmd);
        if (stat(tokens[0], &buffer) != 0)
        {
            return (0);
        }
    }
    child_pid = fork();
    if (child_pid == -1)
    {
        perror("Child process failed");
    }
    else if (child_pid == 0)
    {
        if (execve(tokens[0], tokens, NULL) == -1)
        {
            perror("./hsh");
        }
    }
    else
        wait(&status);
    return(1);
}