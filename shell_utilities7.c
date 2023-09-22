#include "utilities.h" 

/**
 * cnv_to_helper - Helper function to convert a number to a string.
 * @buff: Pointer to the destination buffer.
 * @m: The number to convert.
 * 
 * Return: void
 */
static void cnv_to_helper(char **buff, size_t m)
{
	if (m > 9) /*base case*/
	    cnv_to_helper(buff, m / 10);
	**buff = '0' + m % 10;
	*buff += 1;
	**buff = '\0';
}

/**
 * convert_str - Convert a positive integer to a string.
 * @n: The positive integer to convert.
 * 
 * Return: A pointer to the dynamically allocated string 
 * on success, or NULL on failure.
 */
char *convert_str(size_t n)
{
    error_t error;
    error.len = 1;
    error.buf = NULL;
    size_t temp = n;

    while (temp /= 10)
        error.len++;
    error.buf = malloc(sizeof(error_t) * (error.len + 1));
    if (error.buf == NULL)
        return (NULL);
    cnv_to_helper(&error.buf, n);
    return (error.buf - error.len);
}
