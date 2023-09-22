#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_

#include <stdlib.h>
#include "utilities.h"
#include "shellhelpertype.h"

/**
  * struct dict - singly linked list of key-value pairs
  * @key: variable name
  * @val: value of variable
  * @next: pointer to the next node
  */
struct shell_dict
{
	char *key;
	char *value;
	struct shell_dict *link;
};

char *get_value(shell_dict_t *head, const char *key);
shell_dict_t *get_node(shell_dict_t *head, const char *key);
shell_dict_t *add_dict_to_the_end(shell_dict_t **headptr, const char *key, const char *value);
shell_dict_t *delete_nodes(shell_dict_t **headptr, const char *key);
void free_dictionary(shell_dict_t **headptr);

#endif /*_DICTIONARY_H_*/