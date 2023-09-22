#include "utilities.h"

/**
 * _memchr - memory character
 * @s: pointer to array of string to search
 * @c: character to search
 * @n: size of array of string
 * Return: pointer to the first occurrence
 * of the found character
*/
ssize_t _memchr(const void *s, int c, size_t n)
{
    unsigned char *str = (unsigned char *)s;
    size_t iterator;

    if (str)
	{
		for (iterator = 0; iterator < n; iterator++)
        {
            if (str[iterator] == (unsigned char)c)
            {
               return (iterator);
            }
        }
	}

    return (-1);
}

/**
 * _memcpy - memory copy function
 * @dest: destination
 * @src: source
 * @n: size
 * Return: void
 */

void *_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *destination = dest;
	const unsigned char *source = src;
	size_t iterator;

	if (dest && src)
	{
		for (iterator = 0; iterator < n; iterator++)
		{
			*destination++ = *source++;
		}
		return (dest);
	}
	return (NULL);
}

/**
 * _memdup - memory duplicate
 * @str: string to duplicate
 * @n: size of string to duplicate
 * 
 * Return: pointer to the calling function if successful
 * or NULL is not
*/
void *_memdup(const void *str, size_t n)
{
    void *duplicate;
    unsigned char *dup;
    const unsigned char *src;
    size_t iterator;

    duplicate = malloc(n);

    if (duplicate == NULL)
        return NULL;
    dup = duplicate;
    src = str;

    for (iterator = 0; iterator < n; iterator++)
    {
        *dup++ = *src++;
    }

    return duplicate;
}

/**
 * _memset - fill a region of memory with a given value
 * @dest: pointer to the beginning of the region
 * @chr: value to write to the region
 * @n: number of bytes to write
 * Return: dest
 */
void *_memset(void *dest, unsigned char chr, size_t n)
{
	unsigned char *mem = dest;

	if (dest)
	{
		while (n--)
			*mem++ = chr;
	}
	return (dest);
}