#include "main.h"

/**
 * handle_flag - finds the flag func
 * @s: the format string
 * @arguments: the parameters struct
 *
 * Return: if flag was valid
 */
int handle_flag(char *s, arguments_t *arguments)
{
	int x = 0;

	switch (*s)
	{
		case '+':
			x = arguments->plus_arg = 1;
			break;
		case ' ':
			x = arguments->space_arg = 1;
			break;
		case '#':
			x = arguments->hashtag_arg = 1;
			break;
		case '-':
			x = arguments->minus_arg = 1;
			break;
		case '0':
			x = arguments->zero_arg = 1;
			break;
	}
	return (x);
}

/**
 * handle_modifier - finds the modifier func
 * @s: the format string
 * @arguments: the parameters struct
 *
 * Return: if modifier was valid
 */
int handle_modifier(char *s, arguments_t *arguments)
{
	int x = 0;

	switch (*s)
	{
		case 'h':
			x = arguments->shrt_modifier = 1;
			break;
		case 'l':
			x = arguments->long_modifier = 1;
			break;
	}
	return (x);
}

/**
 * handle_width - gets the width from the format string
 * @s: the format string
 * @arguments: the parameters struct
 * @ap: the argument pointer
 *
 * Return: new pointer
 */
char *handle_width(char *s, arguments_t *arguments, va_list ap)
{
	int x = 0;

	if (*s == '*')
	{
		x = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			x = x * 10 + (*s++ - '0');
	}
	arguments->width = x;
	return (s);
}

/**
 * handle_precision - gets the precision from the format string
 * @p: the format string
 * @arguments: the parameters struct
 * @ap: the argument pointer
 *
 * Return: new pointer
 */
char *handle_precision(char *p, arguments_t *arguments, va_list ap)
{
	int x = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		x = va_arg(ap, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			x = x * 10 + (*p++ - '0');
	}
	arguments->precision = x;
	return (p);
}
