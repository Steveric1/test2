#include "cmd.h"

/**
 * cmd_to_split - Split a command string into tokens,
 *  considering quoting and escape characters.
 * @cmd: The input command string to be split.
 *
 * Return: The number of tokens found in the command string.
 */
size_t cmd_to_split(char *cmd)
{
    cmd_t split;
    if (!cmd)
        return (0);
    split.cmd_count = 1;
    do
    {
        while (*cmd && (split.state = quote_proc(*cmd)) != QUOTE_NONE)
        {
            if (split.state & QUOTE_WORD)
            {
                split.quote_len = quote_word(cmd, NULL);
                split.delim_indx = find_char_in_str(cmd, ';', split.quote_len);
                if (split.delim_indx != -1)
                {
                    split.quote_len = split.delim_indx;
                    *(cmd++ + split.quote_len) = '\0';
                    ++split.cmd_count;
                }
                cmd += split.quote_len;
            }
            else if (split.state & QUOTE_ESCAPE)
            {
                if (*(cmd + 1) == '\n')
                   _strcpy(cmd, cmd + 2);
                else if (*(++cmd) != '\0')
                    ++cmd;
            }
            else
            {
                cmd += quote_str_len(cmd + 1, split.state) + 1;
                if (*cmd && (split.state & (QUOTE_DOUBLE | QUOTE_SINGLE)))
                    ++cmd;
            }
        }
    } while (*(cmd += quote_str_len(cmd, QUOTE_NONE)));
    
    return (split.cmd_count);
}