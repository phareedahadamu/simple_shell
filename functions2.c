#include "main.h"

/**
 * _strcat - A function that concatenates a string to another
 * @str1: the string to be increased
 * @str2: contents will be added to str1 end
 * Return: str1 on success
 */
char *_strcat(char *str1, char *str2)
{
	int i, j = 0;

	if (str2 == NULL)
		return (str1);
	for (i = (_strlen(str1)); str2[j] != '\0'; i++)
	{
		str1[i] = str2[j];
		j++;
	}
	str1[i] = '\0';
	return (str1);
}

/**
 * tokenize - A function that breaks a string down to indidual tokens
 * @lp2: The string
 * @count: The number of tokens
 * @args: The string array where the string tokens will be stored
 * Return: The string array
 */
char **tokenize(char *lp2, int count, char **args)
{
	char *token = NULL;
	int i = 0;

	if (lp2 == NULL || args == NULL)
		return (NULL);
	token = strtok(lp2, " \n");
	for (i = 0; i < count; i++)
	{
		args[i] = _strdup(token);
		token = strtok(NULL, " \n");
	}
	args[i] = NULL;
	return (args);
}

/**
 * _execve - A function that creates a child process and execute a command
 * @args: An array of commands
 * @environ: Environment variable
 * @lp1: Line pointer to be freed
 * Return: 0 if execution was successful else -1
 */
int _execve(char **args, char **environ, char *lp1)
{
	pid_t fid = fork();
	char *abs_path = NULL, *msg = NULL;
	int status;

	if (fid == -1)
		return (status);
	if (fid == 0)
	{
		abs_path = get_abs_path(args[0], environ);
		if (abs_path == NULL)
		{
			msg = print_err(args);
			free(msg);
			free_args(args, lp1);
			exit(127);
		}
		else
		{
			if (access(abs_path, F_OK) == 0)
			{
				execve(abs_path, args, environ);
				free_args(args, lp1);
				exit(0);
			}
			else
			{
				perror("Access error");
				free_args(args, lp1);
				exit(2);
			}
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
		free(abs_path);
	}
	return (status);
}

/**
 * _getenv - A funtion that gets the values of an environment variable
 * @name: name of the environment variable
 * @environ: The string array of environ variables
 * Return: The retrieved value of the env var
 */
char *_getenv(char *name, char **environ)
{
	char *env = NULL, *token;
	int i = 0, j = 0;

	while (environ[i] != NULL)
	{
		env = environ[i];
		while (env[j] == name[j] && env[j] != '=' && name[j] != '\0')
			j++;
		if (name[j] == '\0')
		{
			token = strtok(env, "=");
			token = strtok(NULL, "\n");
			return (token);
		}
		i++;
	}
	return (NULL);
}

/**
 * get_abs_path - A function that gets the absolute path of a command
 * @cmd: The command
 * @environ: The string array of environ variables
 * Return: The abs path if it exists else NULL
 */
char *get_abs_path(char *cmd, char **environ)
{
	char *path = NULL, *abs_path = NULL, *token = NULL;
	struct stat buffer;

	path = _getenv("PATH", environ);
	token = strtok(path, ":");
	while (token != NULL)
	{
		abs_path = malloc((_strlen(token)) + (_strlen(cmd)) + 2);
		_strcpy(token, abs_path);
		_strcat(abs_path, "/");
		_strcat(abs_path, cmd);
		if (stat(abs_path, &buffer) == 0)
			return (abs_path);
		free(abs_path);
		token = strtok(NULL, ":");
	}
	if (stat(cmd, &buffer) == 0)
		return (cmd);
	return (NULL);
}
