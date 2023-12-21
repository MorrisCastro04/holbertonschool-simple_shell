#include "shell.h"
/**
 * add_path - create the full path for the cmd
 * @tokens: the command
 * @path_tok: the path from the enviroment
 * Return: Return the full path
 */
char *add_path(char **tokens, char **path_tok)
{
	char *cmd;
	int i = 0;
	struct stat buffer;
	/*Iterate through each directory in the PATH*/
	while (path_tok[i])
	{
		cmd = strcat(path_tok[i], "/");
		strcat(cmd, tokens[0]);
		/*Check if the command exists with the update path*/
		if (stat(cmd, &buffer) == 0)
		{
			tokens[0] = cmd;
			break;
		}
		i++;
	}
	return (tokens[0]);
}
