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
