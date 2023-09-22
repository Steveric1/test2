#include "cmd.h"

/**
 * cmd_btree - Create a binary tree of commands (currently unused).
 * @not_modifed: An array of strings representing commands (unused).
 *
 * Return: Always returns NULL.
 */
command_t *cmd_btree(const char * const *not_modifed  __attribute__((unused)))
{
   return (NULL);
}

/**
/ * update_the_cmd - Process and update a linked list of commands from a string.
 * @cmd: The input string containing multiple commands separated by a delimiter.
 * 
 * Return: A pointer to the head of the linked list containing processed commands.
 *         NULL if the input string is empty or if memory allocation fails.
*/
command_t *_update_the_cmd(const char *cmd)
{
    command_t *head = NULL;
    size_t count;
    char *split = _strdup(cmd);

    if (!split)
        return (NULL);

    count = cmd_to_split(split);

    if (!_update_cmd(&head, split, count))
    {
        free_all(1, split);
        free_command_lst(&head);
        return (NULL);
    }

    free_all(1, split);

    return (head);
}

/**
 * _update_cmd - Process and update a linked list of commands.
 * @ptr: A pointer to the head of the linked list.
 * @split: A string containing commands separated by a delimiter.
 * @count: The number of commands to process.
 *
 * Return: A pointer to the updated linked list after processing.
 */
command_t *_update_cmd(command_t **ptr, char *split, size_t count)
{
    command_t *tail = *ptr;

    while (count > 0)
    {
        if (split == NULL)
            return *ptr;
        tail = at_the_end(ptr, split);

        if (tail == NULL)
            return NULL;
        while (*split++)
            ;
        count--;          
    }
    return (*ptr);
}