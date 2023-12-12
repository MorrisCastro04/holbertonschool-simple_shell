#include "shell.h"
/**
 * 
 * 
 * 
 * 
*/
void printArguments(char **av)
{
    int count = 0;

    while (av[count] != NULL)
        count++;
    printf("%i\n", count);
}