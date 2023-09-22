#ifndef _STRTOK_H_
#define _STRTOK_H_

#include <stdlib.h>
#include "myqoute.h"
#include "utilities.h"
#include "shellhelpertype.h"

/**
 * struct strtok - Structure to tokenize a string.
 * @tokens: An array of pointers to tokens.
 * @store_tok: The original string being tokenized.
 * @state: The current quote_state for parsing the string.
 *
 * This structure is used to tokenize a string and store the resulting tokens,
 * the original string, and the current quote state for parsing.
 */

struct strtok
{
	char **tokens;
	const char *store_tok;
	quote_state state;
};

size_t tok_counter(const char *s);
char **my_token(const char *tok);
void release_mem(char ***str);
char **arrdup(char **arr);

#endif /*_STRTOK_H_*/
