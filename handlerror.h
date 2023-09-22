#ifndef _HANDLERROR_H_
#define _HANDLERROR_H_

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#include "utilities.h"

void perrorl(const char *msg, ...);

typedef struct error
{
    char *buf;
    size_t len;
    char *linenum_error;
	const char *str_ret;
} error_t;

void handle_error(const char *av, size_t linenum, const char *error_m, ...);
#endif /*_HANDLERROR_H_*/