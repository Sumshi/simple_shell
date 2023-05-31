#include "main.h"

/**
 * _strncmp - a function that compares two strings.
 * @str1: the first string to compare.
 * @str2: the second string to compare.
 * @n: number of bytes to compare.
 *
 * Return: 0 if the two strings are the same and if not
 * it returns the diffrence between the first two different characters.
 */
int _strncmp(char *str1, char *str2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		if (str1[i] == '\0')
			return (0);
	}
	return (0);
}

/**
 * _strlen - function that count the lenght of a string.
 * @str: string to be counted.
 *
 * Return: lenght and -1 if it fails.
 */
int _strlen(char *str)
{
	size_t len;

	if (!str)
		return (-1);
	len = 0;
	while (str[len] != '\0')
		len++;

	return (len);
}

/**
 * _strdup - function that duplicates a string.
 * @str: string to duplicate.
 *
 * Return: the new string (duplicate)
 */
char *_strdup(const char *str)
{
	size_t i, len = strlen(str) + 1;
	char *new_str = malloc(len);

	if (new_str == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < len; i++)
	{
		new_str[i] = str[i];
	}
	return (new_str);
}

/**
 * _strcmp - a function that compares two strings.
 * @s1: the first string to compare.
 * @s2: the second string to compare.
 * Return: 0 if the two strings are the same and if not
 * it returns the diffrence between the first two different characters.
 */
int _strcmp(char *s1, char *s2)
{
	int i, k, result;

	i = 0;
	result = 0;
	while (s1[i] != '\0')
		i++;
	for (k = 0; k <= i; k++)
	{
		if (s1[k] != s2[k])
		{
			result = s1[k] - s2[k];
			break;
		}
	}
	return (result);
}

/**
 * _strcat - a function that appends the src string to the dest string,
 * overwriting the terminating null byte (\0) at the end of dest,
 * and then adds a terminating null byte.
 * @path: the pointer that will be appended by command.
 * @command: the pointer that will be appended to path.
 * Return: a pointer to the resulting string dest.
 */
char *_strcat(char *path, char *command)
{
	int y;
	unsigned int i, j, path_len, command_len, sizebuff;
	char *p;

	(void) y;
	path_len = _strlen(path);
	command_len = _strlen(command);
	sizebuff = path_len + command_len + 2;
	p = malloc(sizeof(char) * sizebuff);
	if (!p)
	{
		y = write(STDERR_FILENO, "Error: malloc failed\n", 22);
		exit(98);
	}
	for (i = 0; i < path_len; i++)
		p[i] = path[i];
	p[i] = '/';
	for (i++, j = 0; j < command_len; j++)
		p[i + j] = command[j];
	p[i + j] = '\0';
	return (p);
}
