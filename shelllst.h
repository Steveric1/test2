#ifndef _SHELLLST_H_
#define _SHELLLST_H_

#include <stdlib.h>
#include "utilities.h"
#include "shellhelpertype.h"

struct directory
{
	char *path;
	struct directory *link;
};

directory_t *path_wrapper(const char *path, char delim);
directory_t *path_to_list(directory_t **tail_ptr, const char *path, char delim);
directory_t *add_at_beg(directory_t **headptr, const char *path);
directory_t *dir_at_the_end(directory_t **dir_head, const char *path);
void free_dir(directory_t **head_ptr);

#endif /*_SHELLLST_H_*/