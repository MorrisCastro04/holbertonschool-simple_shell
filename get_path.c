#include "shell.h"
/**
 * 
 * 
 * 
 * 
*/
char *add_path(char **tokens, char **path_tok)
{
    char *cmd;
    int i = 0;
    struct stat buffer;

    while (path_tok[i])
    {
        cmd = strcat(path_tok[i], "/");
        strcat(cmd, tokens[0]);
        if (stat(cmd, &buffer) == 0)
        {
            tokens[0] = cmd;
            break;
        }
        i++;
    }
    return (tokens[0]);
}