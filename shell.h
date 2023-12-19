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
#include <sys/stat.h>
void free_tokens(char **);
char **getTokens(char *, char *);
char *file_path(char *);
char *file_loc(char *, char *);
int startWithSlash(const char *);
#endif
