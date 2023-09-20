#include "main.h"

/**
 * _putchar - A function that inputs a char to stdout
 * @c: The char to be printed
 * Return: 1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - A function that prints a string
 * @str: The string
 * Return: 0 on success
 */
int _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	return (0);
}

/**
 * _strcmp - A function that checks if a string is the same as another
 * @str1: String 1
 * @str2: String 2
 * Return: 0 if the same else -1
 */
int _strcmp(char *str1, char *str2)
{
	int i = 0;

	if (str1 == NULL || str2 == NULL)
		return (-1);
	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (-1);
		i++;
	}
	return (0);
}

/**
 * _strlen - A function that checks the length of a string
 * @str: The string
 * Return: The length
 */
int _strlen(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

/**
 * _strcpy - A function that copies the contents of a string to another
 * @source: The source string
 * @dest: The destination string
 * Return: The destination string
 */
char *_strcpy(char *source, char *dest)
{
	int i = 0;

	if (source == NULL)
		return (NULL);
	while (source[i] != '\0')
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
