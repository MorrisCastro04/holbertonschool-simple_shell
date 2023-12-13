#include "shell.h"

/**
 *
 *
 *
 */
int main(int ac __attribute__((unused)), char **av)
{
    char *buffer = NULL;
    size_t n = 0;

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
        }
    }
    return (0);
}