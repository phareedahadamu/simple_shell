#include "main.h"

/**
 * rem_quotes - A function that removes quote marks from a string
 * @str: The string
 * @c: The quote marks
 */
void rem_quotes(char *str, char c)
{
	int i, len, j;

	len = strlen(str);
	for (i = 0; i < len; i++)
	{
		if (str[i] == c)
		{
			for (j = i; j < len; j++)
			{
				str[j] = str[j + 1];
			}
			len--;
			i--;
		}
	}
}

/**
 * get_func - A function that checks if a command is built in and assigns the
 *            fuction to execute if it is
 * @token: The command
 * Return: A pointer to the assigned function on success else NULL
 */
int (*get_func(char *token))(char *args, char **environ)
{
	built_ins bi_f[] = {
	{"cd", change_dir},
	{"pwd", _pwd},
	{"env", _printenv},
	{NULL, NULL}
	};
	int i = 0;

	while (bi_f[i].cmd != NULL)
	{
		if (_strcmp(token, bi_f[i].cmd) != 0)
			i++;
		else
			return (bi_f[i].f);
	}
	return (NULL);
}

/**
 * change_dir - A built in function that changes directories
 * @args: The directory to be entered
 * @environ: The environment variables
 * Return: 0 on success else -1
 */
int change_dir(char *args, char **environ)
{
	int len;
	char cwd[PATH_MAX], *home, *token;

	if (args == NULL)
	{
		home = _getenv("HOME", environ);
		token = strtok(home, "=");
		token = strtok(NULL, "\n");
		chdir(token);
		return (0);
	}
	if (_strcmp(args, "-") == 0)
	{
		getcwd(cwd, sizeof(cwd));
		len = _strlen(cwd);
		while (cwd[len - 1] != '/')
		{
			cwd[len - 1] = '\0';
			len--;
		}
		cwd[len - 1] = '\0';
		chdir(cwd);
		return (0);
	}
	if (chdir(args) == -1)
	{
		perror("chdir error:");
		return (-1);
	}
	return (0);
}

/**
 * _pwd - A function that prints the currend working directory
 * @args: The argument
 * @environ: The environment variables
 * Return: 0 on success else -1
 */
int _pwd(char *args, char **environ)
{
	char cwd[PATH_MAX];
	int i = 0;

	(void)args;
	(void)environ;
	getcwd(cwd, sizeof(cwd));
	if (cwd == NULL)
	{
		perror("pwd error");
		return (-1);
	}
	while (cwd[i] != '\0')
	{
		_putchar(cwd[i]);
		i++;
	}
	_putchar('\n');
	return (0);
}

/**
 * _printenv - A function that prints the environment
 * @args: The argument
 * @environ: The environ variables
 * Return: 0 on success
 */
int _printenv(char *args, char **environ)
{
	size_t i = 0, j;
	char *env = NULL;

	(void)args;
	while (environ[i] != NULL)
	{
		env = environ[i];
		j = 0;
		while  (env[j] != '\0')
		{
			_putchar(env[j]);
			j++;
		}
		_putchar('\n');
		i++;
	}
	return (0);
}
