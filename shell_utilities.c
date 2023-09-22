#include "utilities.h"

/**
 * _strchr - locates a character in a string
 * @s: string to be searched
 * @c: character to be located
 * Return: pointer to the first occurrence of the character c in the string s
 */
ssize_t _strchr(const char *s, int c)
{
	ssize_t i;

	if (s == NULL)
		return (-1);
	for (i = 0; s[i] != '\0'; ++i)
	{
		if (s[i] == c)
			return (i);
	}
	return (-1);
}

/**
 * _strdup - duplicates a string
 * @str: string to duplicate
 * Return: pointer to the new string
 */

char *_strdup(const char *str)
{
	char *new_str = NULL;
	ssize_t i, len = 0;

	if (str == NULL)
		return (NULL);
	len = _strlen(str);
	new_str = malloc(sizeof(char) * (len + 1));

	if (new_str == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		new_str[i] = str[i];
	new_str[i] = '\0';

	return (new_str);
}

/**
 * _strlen - calculate the length of a string
 * @str: the string to calculate the length of
 * Return: the length of the string
 */
ssize_t _strlen(const char *str)
{
	const char *pos = str;

	if (!str)
		return (-1);

	while (*pos)
		++pos;

	return (pos - str);
}

/**
 * _strcmp - function that compare two string
 * @s1: The first string to compare
 * @s2: The second string to compare
 * Return: s1 - s2
 */
int _strcmp(const char *s1, const char *s2)
{
	int e;

	for (e = 0; s1[e] && s2[e]; e++)
	{
		if (s1[e] != s2[e])
		{
			return (s1[e] - s2[e]);
		}
	}
	return (s1[e] - s2[e]);
}

/**
 * _strcpy - copies the string pointed to by src to dest
 * @dest: destination string
 * @src: source string
 * Return: pointer to dest
 */
char *_strcpy(char *dest, const char *src)
{
	int e;

	for (e = 0; src[e] != '\0'; e++)
		dest[e] = src[e];
	dest[e] = src[e];
	return (dest);
}
