#include "shell.h"
/**
 * 
 * 
 * 
 * 
*/
void print_env(char **env)
{
    int i;

    for (i = 0; env[i]; i++)
    {
        write(1, env[i], strlen(env[i]));
        write(1, "\n", 1);
    }
}
/**
 * 
 * 
 * 
 * 
*/
int ifexit(char **tokens)
{
    int i;

    if (strcmp(tokens[0], "exit") == 0)
    {
        for (i = 0; tokens[i] != NULL; i++)
            free(tokens[i]);
        exit(0);
    }
    return(1);
}