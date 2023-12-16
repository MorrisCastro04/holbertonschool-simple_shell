#include "shell.h"
/**
 * 
 * 
 * 
 * 
 * 
*/

void free_tokens(char **tokens)
{
    int i;

    if(!tokens)
        return;
    /*liberar memoria para cada token*/
    for (i = 0; tokens[i] != NULL; i++)
        free(tokens[i]);
    free(tokens);
}