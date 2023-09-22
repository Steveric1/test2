#ifndef _HANDLERROR_H_
#define _HANDLERROR_H_

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#include "utilities.h"

void perrorl(const char *msg, ...);

/**
 * struct error - Structure to store error information.
 * @buf: Buffer to store the error message.
 * @len: Length of the error message.
 * @linenum_error: Line number where the error occurred.
 * @str_ret: String representation of the error.
 */

typedef struct error
{
	char *buf;
	size_t len;
	char *linenum_error;
	const char *str_ret;
} error_t;

void handle_error(const char *av, size_t linenum, const char *error_m, ...);
#endif /*_HANDLERROR_H_*/
