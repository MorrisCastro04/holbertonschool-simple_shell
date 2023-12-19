#include "shell.h"
/**
 * 
 * 
 * 
 * 
*/
int main(int ac, char **av)
{
    char *buf = NULL, **tokens, *path;
    size_t count = 0;
    ssize_t nread;
    pid_t child_pid;
    int status;

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
        tokens = getTokens(buf, " \n");
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
        free_tokens(tokens);
        free(path);
    }
    free(buf);
    return (0);
}