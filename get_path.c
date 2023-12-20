#include "shell.h"
/**
 * 
 * 
 * 
 * 
*/
char *file_loc(char *path, char *file_name)
{
    char *path_copy, *token, *path_buffer = NULL;
    struct stat file_path;

    path_copy = strdup(path);
    token = strtok(path_copy, ":");

    while(token)
    {
        if (path_buffer)
        {
            free(path_buffer);
            path_buffer = NULL;
        }
        path_buffer = malloc(strlen(token) + strlen(file_name) + 1);
        if (!path_buffer)
        {
            perror("Error malloc failed");
            exit(EXIT_FAILURE);
        }
        strcpy(path_buffer, token);
        strcat(path_buffer, "/");
        strcat(path_buffer, file_name);

        if (stat(path_buffer, &file_path) == 0 && access(path_buffer, X_OK) == 0)
        {
            free(path_copy);
            return (path_buffer);
        }
        token = strtok(NULL, ":");
    }
    free(path_copy);
    if (path_buffer)
        free(path_buffer);
    return (NULL);
}