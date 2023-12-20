#include "shell.h"
/**
 * 
 * 
 * 
 * 
 * 
*/
char *path(char **env)
{
    int i = 0;
    char *path, *copy_path[10];

    while (env[i])
    {
        if (strncmp(env[i], "PATH", 4) == 0)
        {
            path = strdup(env[i]);
            getTokens(path, copy_path, "=");
            path = NULL;
            path = strdup(copy_path[1]);
        }
        i++;
    }
    return (path);
}