#ifndef SHELL_H
#define SHELL_H
#define MAX_TOKENS 10
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
void free_tokens(char **);
void printArguments(char **);
char **getTokens(char *, char *);
int execute(char **, char **);
#endif
