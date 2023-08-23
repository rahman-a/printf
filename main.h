#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define NULL_STRING "(null)"

#define ARGUMENTS_INIT { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/**
 * struct arguments - arguments struct
 *
 * @unsigned_var: flag if unsigned value
 *
 * @plus_arg: on if plus_arg specified
 * @space_arg: on if hashtag_arg specified
 * @hashtag_arg: on if _arg specified
 * @zero_arg: on if _arg specified
 * @minus_arg: on if _arg specified
 *
 * @width: field width specified
 * @precision: field precision specified
 *
 * @shrt_modifier: on if h_modifier is specified
 * @long_modifier: on if l_modifier is specified
 *
 */
typedef struct arguments
{
	unsigned int unsigned_var : 1;
	unsigned int plus_arg : 1;
	unsigned int space_arg : 1;
	unsigned int hashtag_arg : 1;
	unsigned int zero_arg : 1;
	unsigned int minus_arg : 1;
	unsigned int width;
	unsigned int precision;
	unsigned int shrt_modifier : 1;
	unsigned int long_modifier : 1;
} arguments_t;

/**
 * struct handler_func - Struct token
 * @specifier: format token
 * @handler: The function associated
 */
typedef struct handler_func
{
	char *specifier;
	int (*handler)(va_list, arguments_t *);
} handler_func_t;

/* define_specifier_handler */
int get_print_handler(char *s, va_list list, arguments_t *arguments);
int (*get_handler(char *s))(va_list list, arguments_t *arguments);

/* 0-specifier_handler */
int handle_char(va_list list, arguments_t *arguments);
int handle_int(va_list list, arguments_t *arguments);
int handle_string(va_list list, arguments_t *arguments);
int handle_percent(va_list list, arguments_t *arguments);
int handle_not_printable(va_list list, arguments_t *arguments);

/* 1-specifier_handler */
int handle_unsigned(va_list list, arguments_t *arguments);
int handle_hex(va_list list, arguments_t *arguments);
int handle_HEX(va_list list, arguments_t *arguments);
int handle_binary(va_list list, arguments_t *arguments);
int handle_octal(va_list list, arguments_t *arguments);

/* 2-specifier_handler */
int handle_pointer(va_list list, arguments_t *arguments);
int handle_string_reverse(va_list list, arguments_t *arguments);
int handle_rot13(va_list list, arguments_t *arguments);

/* 3-specifier_handler */
int handle_flag(char *s, arguments_t *arguments);
int handle_modifier(char *s, arguments_t *arguments);
char *handle_width(char *s, arguments_t *arguments, va_list list);
char *handle_precision(char *p, arguments_t *arguments, va_list list);

/* helper_func */
char *convert(long int num, int base, int flags, arguments_t *arguments);
int _puts(char *str);
int _putchar(int c);
int _isdigit(int c);
int _strlen(char *s);
void init_arguments(arguments_t *arguments, va_list list);

/* print_handlers */
int print_from_to(char *start, char *stop, char *except);
int print_number(char *str, arguments_t *arguments);
int handle_justify_right(char *str, arguments_t *arguments);
int handle_justify_left(char *str, arguments_t *arguments);

/* _prinf.c module */
int _printf(const char *format, ...);

#endif
