#include "shell.h"
/**
 *cmd_exist - check if the cmd exist
 *@tokens: pointer to the command
 *@env: pointer to the enviroment
 *Return: return 0 if cmd do not exist othewise 1
 */
int cmd_exist(char **tokens, char **env)
{
	int status;
	pid_t child_pid;
	struct stat buffer;
	char *path_tok, *cmd[100];
	/*Check if the command exist in the current directory*/
	if (stat(tokens[0], &buffer) != 0)
	{
		/*Get the PATH variable and tokenize it*/
		path_tok = path(env);
		getTokens(path_tok, cmd, ":");
		/*Update the command with the full path*/
		tokens[0] = add_path(tokens, cmd);
		/*Check if the command exists after updating the path*/
		if (stat(tokens[0], &buffer) != 0)
			return (0);
	}
	/*Fork a child process*/
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Child process failed");
	}
	else if (child_pid == 0)
	{
		/*Execute the command*/
		if (execve(tokens[0], tokens, NULL) == -1)
		{
			perror("./hsh");

			/* exit(EXIT_FAILURE);*/
		}
	}
	else
		wait(&status);
	/*free(path_tok);*/
	return (1);
}
