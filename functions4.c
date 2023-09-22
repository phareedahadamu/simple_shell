#include "main.h"

/**
 * count_tokens - A functions that counts the number of tokens in a string
 * @lp: The string
 * Return: The number of tokens
 */

int count_tokens(char *lp)
{
	int count = 0;
	char *token = NULL;

	token = strtok(lp, " \n");
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, " \n");
	}
	return (count);
}

/**
 * _strdup - A function that duplicates a string
 * @str: The string to be duplicated
 * Return: The duplicated string on success else NULL
 */
char *_strdup(char *str)
{
	int i = 0;
	char *str1 = NULL;

	if (str == NULL)
		return (NULL);
	str1 = malloc(sizeof(char) * (_strlen(str) + 1));
	if (str1 == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		str1[i] = str[i];
		i++;
	}
	str1[i] = '\0';
	return (str1);
}

/**
 * free_args - A function that frees args
 * @args: The arguments to be freed
 * @lp1: The line pointer to be freed
 */
void free_args(char **args, char *lp1)
{
	int i = 0;

	free(lp1);
	while (args[i] != NULL)
	{
		free(args[i]);
		i++;
	}
	free(args);
	fflush(stdout);
}

/**
 * print_err - A function that prints error message to stdout
 * @args: Arguments
 * Return: The error message to be freed
 */
char *print_err(char **args)
{
	char *msg = NULL, *pre = "./hsh: 1: ", *post = ": not found\n";

	msg = malloc(sizeof(char) * (_strlen(args[0]) + 23));
	_strcpy(pre, msg);
	_strcat(msg, args[0]);
	_strcat(msg, post);
	write(2, msg, (_strlen(msg)));
	return (msg);
}

/**
 * freeargs - A function that frees args
 * @argv: The arguments to be freed
 */
void freeargs(char **argv)
{
	int i = 0;

	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}
