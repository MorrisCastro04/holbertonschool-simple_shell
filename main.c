#include "shell.h"

/**
 *
 *
 *
 */
int main(int ac __attribute__((unused)), char **av, char **env)
{
    char *buffer = NULL, **token;
    size_t n = 0;
    int i;

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
            break;
        }
        token = getTokens(buffer, " \n");
        if (token[0] != NULL)
        {
            if (strcmp(token[0], "env") == 0)
            {
                for (i = 0; env[i]; i++)
                {
                    write(1, env[i], strlen(env[i]));
                    write(1, "\n", 1);
                }
                continue;
            }
            execution(token, env);
        }
    }
    return (0);
}