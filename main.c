#include "shell.h"

/**
 *
 *
 *
 */
int main(int ac, char **av, char **env)
{
    char *buffer, **token;
    size_t n = 0;

    (void)ac;
    (void)av;
    while (1)
    {
        /*verifica si la entrada esta asociada a un terminal*/
        if (isatty(0))
            write(1, "$ ", 2);
        /*lee la lina desde stdin y lo almacena en buffer*/
        if (getline(&buffer, &n, stdin) == EOF)
        {
            free(buffer);
            exit(EXIT_SUCCESS);
        }
        /*obtiene los tokens del buffer*/
        token = getTokens(buffer, " \n");
        free(buffer);
        if (token[0] != NULL)
            execute(token, env);
        else
            free(token);
    }
    free_tokens(token);
    return (0);
}