#include "shell.h"
/**
 * tokenization - extract tokens from the getline command
 *
 * @ptr: String of the command line
 * @delim: Delimiter
 *
 * Return: the array of tokens
 *
 */
void getTokens(char *ptr, char **tokens)
{
	char *token = NULL;
	int i = 0;
	/*divide la cadena de texto en tokens*/
	token = strtok(ptr, " \n");

	while (token)
	{
		tokens[i] = token;
		token = strtok(NULL, " \n");
        i++;
	}

	tokens[i] = NULL;
}