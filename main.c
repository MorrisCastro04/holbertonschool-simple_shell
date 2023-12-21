#include "shell.h"
/**
 * main - a simple copy of shell
 * @ac: number of arguments in av
 * @av: array of pointers
 * @env: pointer to the enviroment
 * Return: always return 0
 */
int main(int ac, char **av, char **env)
{
	char *buf = NULL, *tokens[10];
	size_t count = 0;
	ssize_t nread;

	(void)ac, (void)av;
	/*interactive mode*/
	while (1)
	{
		/*Print prompt if running in terminal*/
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		/*Read input from the user*/
		nread = getline(&buf, &count, stdin);
		if (nread == EOF)
		{
			free(buf);
			exit(EXIT_SUCCESS);
		}
		/*Tokenize the input*/
		getTokens(buf, tokens, " \n");
		/*Check for built-in commands*/
		if (tokens[0] != NULL)
		{
			/*Print enviromnet variables*/
			if (strcmp(tokens[0], "env") == 0)
			{
				print_env(env);
				continue;
			}
			/*Check for the "exit command"*/
			if (ifexit(tokens) == 1)
				cmd_exist(tokens, env);
		}
	}
	return (0);
}
