#ifndef _MYQUOTE_H_
#define _MYQUOTE_H_

#include <stdlib.h>
#include <stdbool.h>
#include "utilities.h"

typedef enum quote
{
    QUOTE_NONE   = 0x0,
    QUOTE_WORD   = 0x1,
    QUOTE_DOUBLE = 0x2,
    QUOTE_SINGLE = 0x4,
    QUOTE_ESCAPE = 0x8
}quote_state;

typedef size_t (*quote_state_fp)(const char *, quote_state *);

quote_state_fp quote_factory(quote_state str);
quote_state quote_proc(char c);

size_t quote_double(const char *str, quote_state *state);
size_t quote_single(const char *str, quote_state *state);
size_t quote_escape(const char *str, quote_state *state);
size_t quote_none(const char *str, quote_state *state);
size_t quote_word(const char *str, quote_state *state);
size_t quote_str_len(const char *str, quote_state state);

/********SHELL QUOTE UTILITIES********/
int _isspecial_double(char c);
bool _isspace(int c);
bool _isquote(int c);
bool _isnumber(const char *s);
bool _isident(int c);
bool _isdigit(int c);
bool _isalpha(int c);
bool _isalnum(int c);

char *dequote(const char *str);
size_t dequote_len(const char *str);
#endif /*_MYQUOTE_H_*/