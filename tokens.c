#include "shell.h"
/**
 * getTokens - fill the array with tokens
 * @ptr: string to create the tokens
 * @tokens: array of pointers to fill with the tokens
 * @delim: the delimitacion for the tokens
 */
void getTokens(char *ptr, char **tokens, char *delim)
{
	char *token = NULL;
	int i = 0;
	/*Tokenize the input string*/
	token = strtok(ptr, delim);

	while (token)
	{
		/*Store the token in the array*/
		tokens[i] = token;
		/*Move to the next token*/
		token = strtok(NULL, delim);
		i++;
	}
	/*NULL-terminate array*/
	tokens[i] = NULL;
}
