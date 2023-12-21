#include "shell.h"
/**
 * path - looks for the path in enviorment
 * @env: pointer to the enviorment
 * Return: Return the first part of the path for the cmd
 */
char *path(char **env)
{
	int i = 0;
	char *path, *copy_path[10];
	/*Iterate through each enviroment variable*/
	while (env[i])
	{
		/*Check if the variable is PATH*/
		if (strncmp(env[i], "PATH", 4) == 0)
		{
			/*Copy the PATH variable and tokenize it*/
			path = strdup(env[i]);
			getTokens(path, copy_path, "=");
			path = NULL;
			path = strdup(copy_path[1]);
		}
		i++;
	}
	return (path);
}
