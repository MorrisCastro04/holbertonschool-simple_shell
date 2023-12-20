#include "shell.h"
/**
 * 
 * 
 * 
 * 
*/
int startWithSlash(const char *str)
{
    if(str != NULL && str[0] == '/')
        return (1);
    return (0);
}
/**
 * 
 * 
 * 
 * 
 * 
*/
char *file_path(char *file_name)
{
    char *path = getenv("PATH");
    char *full_path;

    if (startWithSlash(file_name) && access(file_name, X_OK) == 0)
        return (strdup(file_name));

    if (!path)
    {
        perror("path not found");
        return (NULL);
    }
    full_path = file_loc(path, file_name);
    if (full_path == NULL)
    {
        write(2, file_name, strlen(file_name));
        write(2, ": command not found\n", 19);
        return (NULL);
    }
    return (full_path);
}