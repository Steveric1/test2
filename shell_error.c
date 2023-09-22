#include "handlerror.h"

/**
  * perrorl - print a formatted message to standard error
  * @msg: error message
  * @...: NULL-terminated list of context strings to prepend
  */
void perrorl(const char *msg, ...)
{
	const char *str;
	va_list context;

	va_start(context, msg);
	while ((str = va_arg(context, char *)))
	{
		write(STDERR_FILENO, str, _strlen(str));
		write(STDERR_FILENO, ": ", 2);
	}
	va_end(context);

	if (msg)
		write(STDERR_FILENO, msg, _strlen(msg));
	write(STDERR_FILENO, "\n", 1);
}

/**
 * handle_error - Handle and print error messages.
 * @av: The program name.
 * @linenum: The line number where the error occurred.
 * @error_m: The error message format.
 * Return: void
 */
void handle_error(const char *av, size_t linenum, const char *error_m, ...)
{
	error_t err;
	err.linenum_error = convert_str(linenum);
	err.str_ret = NULL;
	va_list arg;

	if (av)
	    write(STDERR_FILENO, av, _strlen(av));
	write(STDERR_FILENO, ": ", 3);
	if (err.linenum_error)
	    write(STDERR_FILENO, err.linenum_error, _strlen(err.linenum_error));
	write(STDERR_FILENO, ": ", 3);
	
	va_start(arg, error_m);
	while ((err.str_ret = va_arg(arg, char *)))
	{
		write(STDERR_FILENO, err.str_ret, _strlen(err.str_ret));
		write(STDERR_FILENO, ": ", 3);
	}
	va_end(arg);

	if (error_m)
	   write(STDERR_FILENO, error_m, _strlen(error_m));
	write(STDERR_FILENO, ": ", 3);

	free(err.linenum_error);
}