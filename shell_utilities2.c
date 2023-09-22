#include "utilities.h"

/**
 * _strndup - duplicate the given string
 * @str: the string to duplicate
 * @n: the max number of bytes to copy
 *
 * Description: This function copies at most n bytes. If str is longer
 * than n, only n bytes are copied, and a terminating null byte is added.
 *
 * Return: If str is NULL or if memory allocation fails, return NULL.
 * Otherwise a return a pointer to the dynamically-allocated duplicate.
 */
char *_strndup(const char *str, size_t n)
{
	char *dup;
	size_t len = 0;

	if (!str)
		return (NULL);

	while (n && str[len])
		--n, ++len;

	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);

	dup[len] = '\0';

	while (len--)
		dup[len] = str[len];

	return (dup);
}

/**
 * _strnlen - calculate the length of a string
 * @str: the string to measure
 * @n: the max number of characters to check
 * Return: the lesser of n and the length of the string
 */
ssize_t _strnlen(const char *str, size_t n)
{
	const char *pos = str;

	if (!str)
		return (-1);

	while (n && *pos)
		--n, ++pos;

	return (pos - str);
}

/**
 * _strncmp - compare two strings
 * @s1_es: first string
 * @s2_es: Second string
 * @n: number of bytes to be compared
 * Return: difference between the two strings
 */
int _strncmp(const char *s1_es, const char *s2_es, size_t n)
{
	while (n > 0)
	{
		if (*s1_es == '\0' && *s2_es == '\0')
		{
			return (0);
		}
		else if (*s1_es == *s2_es)
		{
			s1_es++;
			s2_es++;
			n--;
		}
		else
		{
			return (*s1_es - *s2_es);
		}
	}
	return (0);
}

/**
 * _strncpy - copy the string
 * @dest: destination
 * @src: source
 * @n: the max number of bytes to copy
 *
 * Description: This function copies at most n bytes from src to dest. A
 * null byte will NOT be written if not found in the first n bytes
 *
 * Return: a pointer to dest
 */

char *_strncpy(char *dest, const char *src, size_t n)
{
	char *pos = dest;

	for ( ; n && *src; --n)
		*pos++ = *src++;
	if (n)
		*pos = '\0';

	return (dest);
}

/**
 * find_char_in_str - function to find character in a string
 * @ch: character to search
 * @size: size of the string to search
 * 
 * Return -1 if failed
*/
ssize_t find_char_in_str(const char *str, char ch, size_t size)
{
    ssize_t index;

	if (!str)
		return (-1);

	for (index = 0; size && str[index]; --size, ++index)
	{
		if (str[index] == ch)
			return (index);
	}

    return (-1);
}