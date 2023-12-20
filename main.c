#include "shell.h"
/**
 * 
 * 
 * 
 * 
*/
int main(int ac, char **av,char **env)
{
    char *buf = NULL, *tokens[10];
    size_t count = 0;
    ssize_t nread;

    (void)ac, (void)av;
    while (1)
    {
        if (isatty(STDIN_FILENO))
            write(STDOUT_FILENO, "$ ", 2);

        nread = getline(&buf, &count, stdin);
        if (nread == EOF)
        {
            free(buf);
            exit(EXIT_SUCCESS);
        }
        getTokens(buf, tokens, " \n");
        if(tokens[0] != NULL)
        {
            cmd_exist(tokens, env);
        }
    }
    return (0);
}