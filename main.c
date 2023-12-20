#include "shell.h"
/**
 * 
 * 
 * 
 * 
*/
int main(int ac, char **av)
{
    char *buf = NULL, *tokens[10], *path;
    size_t count = 0;
    ssize_t nread;
    pid_t child_pid;
    int status, i;

    (void)ac, (void)av;
    while (1)
    {
        if (isatty(STDIN_FILENO))
            write(STDOUT_FILENO, "$ ", 2);

        nread = getline(&buf, &count, stdin);
        if (nread == -1)
        {
            exit(EXIT_SUCCESS);
        }
        getTokens(buf, tokens);
        path = file_path(tokens[0]);
        child_pid = fork();
        if(child_pid == -1)
        {
            perror("Child process failed");
            exit(EXIT_FAILURE);
        }
        else if (child_pid == 0)
        {
            if (execve(path, tokens, NULL) == -1)
            {
                perror("./hsh");
                exit(EXIT_FAILURE);
            }
        }
        else
            wait(&status);
        free(path);
        for (i = 0; tokens[i]; i++)
            free(tokens[i]);
    }
    return (0);
}