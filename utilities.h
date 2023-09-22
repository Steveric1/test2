#ifndef _UTILITIES_H_
#define _UTILITIES_H_

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

#include "handlerror.h"

ssize_t _strchr(const char *s, int c);
char *_strdup(const char *str);
ssize_t _strlen(const char *str);
ssize_t _strlen(const char *str);
char *_strcpy(char *dest, const char *src);
char *_strndup(const char *str, size_t n);
ssize_t _strnlen(const char *str, size_t n);
int _strcmp(const char *s1, const char *s2);
char *_strncpy(char *dest, const char *src, size_t n);
ssize_t find_char_in_str(const char *str, char ch, size_t size);
char *_strncpy(char *dest, const char *src, size_t n);
int _strncmp(const char *s1_es, const char *s2_es, size_t n);
ssize_t _strnlen(const char *str, size_t n);
char *_strndup(const char *str, size_t n);
ssize_t _memchr(const void *s, int c, size_t n);
void *_memcpy(void *dest, const void *src, size_t n);
void *_memdup(const void *str, size_t n);
void *_memset(void *dest, unsigned char chr, size_t n);
static void cnv_to_helper(char **buff, size_t m);
char *convert_str(size_t n);
unsigned int atou(char *s);

/******SHELL MEMORY DEALLOCATION*******/
void free_all(const unsigned int n, ...);
/******SHELL CONCATENATION FUNCTION*******/
char *str_concat(size_t *len, const char *delim, const char *prev, const char *next);
#endif /*_UTILITIES_H_*/