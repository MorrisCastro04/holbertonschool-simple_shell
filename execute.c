#include "shell.h"
/**
 * 
 * 
 * 
 * 
*/
int execution(char **tokens, char **env)
{
    if(execve(tokens[0], tokens, env) == -1)
    {
        perror("./hsh");
    }
    return (1);
}