#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
void printArguments(char **);
char **getTokens(char *, char *);
int execution(char **tokens, char **env);
#endif
