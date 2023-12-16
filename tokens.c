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
char **getTokens(char *ptr, char *delim)
{
	char *token = NULL, **tokens = NULL;
	long unsigned int i = 0;
	size_t capacity = MAX_TOKENS;
	/*Asigna memoria para el array de tokens*/
	tokens = malloc(sizeof(char *) * capacity);
	if (!tokens)
	{
		perror("Error allocating memory");
		exit(EXIT_FAILURE);
	}
	/*divide la cadena de texto en tokens*/
	token = strtok(ptr, delim);

	while (token)
	{
		/*Verifica si se necesita realocar memoria para mas token*/
		if(i >= capacity -1)
		{
			capacity *= 2;
			tokens = realloc(tokens, sizeof(char *)* capacity);
			if (!tokens)
			{
				perror("error reallocating memory");
				exit(EXIT_FAILURE);
			}
		}
		/*Asigna memoria para el token actual*/
		tokens[i] = malloc(sizeof(char) * strlen(token) + 1);
		if (!tokens[i])
		{
			perror("Error allocating memory");
			exit(EXIT_FAILURE);
		}
		/*copia el token a la memeria asignada*/
		strcpy(tokens[i], token);
		i++;
		token = strtok(NULL, delim);
	}

	tokens[i] = NULL;
	return (tokens);
}
