#ifndef _CMD_H_
#define _CMD_H_

#include <stdlib.h>
#include "myquote.h"
#include "utilities.h"
#include "strtok.h"
#include "shellhelpertype.h"

/**
 * struct command - Structure representing a linked list of commands.
 * @link: Pointer to the next command.
 * @b_tree: Pointer to a binary tree of commands.
 * @tokens: Array of tokens for each command in the tree.
 */
struct command
{
        struct command *link;
        struct cmd_btree *b_tree;
        char **tokens;
};

/**
 * struct cmd_btree - Structure representing a binary tree of commands.
 * @success: Pointer to the command to execute upon failure.
 * @failure: Pointer to the command to execute upon success.
 * @ntmodified: Pointer to a simple command with no separators.
 */
struct cmd_btree
{
        struct cmd_btree *success;
        struct cmd_btree *failure;
        const char *const *ntmodified;
};

command_t *_update_cmd(command_t **ptr, char *split, size_t count);
command_t *at_the_end(command_t **the_end, const char *cmd);
command_t *del_cmd_at_pos(command_t **head, size_t pos);
char **remove_cmd(command_t **head);
void free_command_lst(command_t **head);
void free_command_btree(cmd_btree_t **headptr);

/**
 * struct cmd_t - Structure to represent command processing information.
 * @cmd_count: The count of tokens found in the command string.
 * @quote_len: The length of the current quoted section.
 * @delim_indx: The index of the delimiter within a quoted section.
 * @state: The current quote_state for parsing the command string.
 */
typedef struct cmd_t
{
        size_t cmd_count;
        size_t quote_len;
        ssize_t delim_indx;
        quote_state state;
} cmd_t;

size_t cmd_to_split(char *cmd);

#endif /* _CMD_H_ */


