#ifndef _STRTOK_H_
#define _STRTOK_H_

#include <stdlib.h>
#include "myqoute.h"
#include "utilities.h"
#include "shellhelpertype.h"

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
// char **arrjoin(char **arr1, char **arr2);

#endif /*_STRTOK_H_*/