#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <errno.h>
#include <fcntl.h>

/**
 * struct built_ins - A structure for the built in commands and their functions
 * @cmd: The command
 * @f: The command
 */
typedef struct built_ins
{
	char *cmd;
	int (*f)(char *args, char **environ);
} built_ins;

int _puts(char *str);
int _putchar(char c);
int _strcmp(char *str1, char *str2);
int _strlen(char *str);
char *_strcpy(char *source, char *dest);
char **tokenize(char *lp2, int count, char **args);
int _execve(char **args, char **environ, char *lp1);
char *_getenv(char *name, char **environ);
char *get_abs_path(char *cmd, char **environ);
char *_strcat(char *str1, char *str2);
void rem_quotes(char *str, char c);
int (*get_func(char *token))(char *args, char **environ);
int change_dir(char *args, char **environ);
int _printenv(char *args, char **environ);
int _pwd(char *args, char **environ);
int count_tokens(char *lp);
char *_strdup(char *str);

#endif
