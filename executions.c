#include "shell.h"
/*
 * execute: starts the commands
 *
 * Return: Always 0.
 */
int execute(char **tokens, char **env)
{
	int w;
	pid_t pid;

	/*Crea un nuevo proceso hijo*/
	pid = fork();
	if (pid == -1)
	{
		perror("Error:");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/*Intenta ejecutar el comando*/
		if (execve(tokens[0], tokens, env) == -1)
		{
			perror("./hsh");
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&w);
	return (1);
}