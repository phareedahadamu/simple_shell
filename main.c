#include "main.h"

/**
 * main - Driver function
 * @argc: unused
 * @argv: Argument vector / tokenized strings
 * @environ: String array of environ variables
 * Return: Exit status
 */

int main(__attribute__((unused)) int argc, char **argv, char **environ)
{
	char *lp1 = NULL, *lp2 = NULL;
	int i = 0, count = 0, status = 0;
	ssize_t read_val;
	size_t n = 0;

	while (1)
	{
		if (isatty(0))
			_puts("Shell$ ");
		read_val = getline(&lp1, &n, stdin);
		if (read_val < 0)
			break;
		lp1[read_val - 1] = '\0';
		rem_quotes(lp1, '"');
		if (_strcmp(lp1, "\n") == 0)
			continue;
		if (_strcmp(lp1, "exit\n") == 0)
		{
			free(lp1);
			exit(status);
		}
		lp2 = _strdup(lp1);
		count = count_tokens(lp1);
		argv = malloc(sizeof(char *) * (count + 1));
		argv = tokenize(lp2, count, argv);
		free(lp2);
		if (get_func(argv[0]) != NULL)
			status = get_func(argv[0])(argv[1], environ);
		else
			status = _execve(argv, environ, lp1);
		i = 0;
		while (argv[i] != NULL)
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
	free(lp1);
	exit(status);
}
