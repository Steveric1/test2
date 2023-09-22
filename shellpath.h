#ifndef SHELLPATH_H
#define SHELLPATH_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

#include "shell.h"
#include "shelllst.h"
#include "utilities.h"
#include "shellhelpertype.h"

// char *search_path(info_t *info, directory_t *path);
char *handle_path(info_t *path_info, directory_t *path_dir);

#endif /*SHELLPATH_H*/