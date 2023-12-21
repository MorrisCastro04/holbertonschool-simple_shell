#include "shell.h"
/**
 * print_env - funcion to print the enviroment
 * @env: pointer to the enviroment
 */
void print_env(char **env)
{
	int i;
	/**Loop through each enviroment variable*/
	for (i = 0; env[i]; i++)
	{
		/*Write the current enviroment variable*/
		write(1, env[i], strlen(env[i]));
		/*Move to the next line*/
		write(1, "\n", 1);
	}
}
/**
 * ifexit - check if the cmd is exit
 * @tokens: pointer to array where the cmd is.
 * Return: Return 0 if exit othewise 1
 */
int ifexit(char **tokens)
{
	int i;
	/*Check if the command is "exit"*/
	if (strcmp(tokens[0], "exit") == 0)
	{
		/*Free memory for each token*/
		for (i = 0; tokens[i] != NULL; i++)
			free(tokens[i]);
		exit(0);
	}
	return (1);
}
