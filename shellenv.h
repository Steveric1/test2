#ifndef _SHELLENV_H_
#define _SHELLENV_H_

#include <stdlib.h>
#include "dictionary.h"
#include "utilities.h"
#include "shellhelpertype.h"

typedef shell_dict_t env_t;

shell_dict_t *build_dict_from_env_caller(char **env);
shell_dict_t *build_dict_from_env(shell_dict_t **head_ptr, char **env);
char **build_env_array(shell_dict_t *ptr);

#endif /*_SHELLENV_H_*/
