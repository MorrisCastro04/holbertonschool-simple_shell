#include "shell.h"
/*
 * execute: starts the commands
 *
 * Return: Always 0.
 */
int execute(int ac, char **av)
{
	pid_t pid;
	pid = fork();
	if (pid == -1)
	{
		perror ("Error:");
		return;
	}
	else if (pid == 0)
		if (execve(tokens[0], tokens, env) == -1)
		else
		{

