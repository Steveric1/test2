#include "myqoute.h"

/**
 * quote_factory - function pointer string processor helper
 * @state: state
 * 
 * Return: state with associated c
*/
quote_state_fp quote_factory(quote_state state)
{
   switch (state)
    {
        case QUOTE_NONE:
           return (quote_none);
        case QUOTE_DOUBLE:
           return (quote_double);
        case QUOTE_SINGLE:
           return (quote_single);
        case QUOTE_ESCAPE:
           return (quote_escape);
        case QUOTE_WORD:
           return (quote_word);
    }
   return (NULL);
}

/**
 * quote_str_len - get the length of state
 * @str: string
 * @state: state
 * 
 * Return: length
*/
size_t quote_str_len(const char *str, quote_state state)
{
   return (quote_factory(state)(str, NULL));
}


/**
 * quote_proc - character processor function
 * @c: character to process
 * 
 * Return: the state of character base on the processor
*/
quote_state quote_proc(char c)
{
	if (_isspace(c))
	   return (QUOTE_NONE);
	else if (c == '"')
	   return (QUOTE_DOUBLE);
	else if (c == '\'')
	   return (QUOTE_SINGLE);
	else if (c == '\\')
	   return (QUOTE_ESCAPE);
	else
	   return (QUOTE_WORD);
}


/**
 * dequote - dequote a string
 * @str: the string to dequote
 * Return: If memory allocation fails, return NULL.
 * Otherwise return a dequoted copy of str.
 */
char *dequote(const char *str)
{
	char *new;
	size_t len = 0, state_len;
	quote_state state;

	if (!str)
		return (NULL);

	new = malloc(sizeof(char) * (dequote_len(str) + 1));
	if (!new)
		return (NULL);

	while (*str)
	{
		state = quote_proc(*str);
		str += (1 && (state & (QUOTE_DOUBLE | QUOTE_SINGLE | QUOTE_ESCAPE)));
		state_len = quote_str_len(str, state);
		if (state & QUOTE_DOUBLE)
		{
			for ( ; state_len; --state_len)
			{
				if (quote_proc(*str++) & QUOTE_ESCAPE)
				{
					if (*str == '\n')
					{
						++str, --state_len;
						continue;
					}
					if (_isspecial_double(*str))
						++str, --state_len;
				}
				new[len++] = str[-1];
			}
		}
		_memcpy(new + len, str, state_len);
		len += state_len;
		str += state_len;
		str += (*str && (state & (QUOTE_DOUBLE | QUOTE_SINGLE)));
	}
	new[len] = '\0';
	return (new);
}


/**
 * dequote_len - compute the length of a string after dequoting
 * @str: the string to evaluate
 * Return: Return the length of str after dequoting
 */
size_t dequote_len(const char *str)
{
	size_t len = 0, state_len;
	quote_state state;

	while (*str)
	{
		state = quote_proc(*str);
		str += (1 && (state & (QUOTE_DOUBLE | QUOTE_SINGLE | QUOTE_ESCAPE)));
		state_len = quote_str_len(str, state);
		if (state & QUOTE_DOUBLE)
		{
			for ( ; state_len; --state_len)
			{
				if (quote_proc(*str++) & QUOTE_ESCAPE)
				{
					if (*str == '\n')
					{
						++str, --state_len;
						continue;
					}
					if (_isspecial_double(*str))
						++str, --state_len;
				}
				len++;
			}
		}
		len += state_len;
		str += state_len;
		str += (*str && (state & (QUOTE_DOUBLE | QUOTE_SINGLE)));
	}
	return (len);
}