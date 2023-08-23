#include "main.h"

/**
 * get_handler - finds the format func
 * @s: the format string
 *
 * Return: the number of bytes printed
 */
int (*get_handler(char *s))(va_list ap, arguments_t *arguments)
{
	handler_func_t specifiers[] = {
		{"c", handle_char},
		{"d", handle_int},
		{"i", handle_int},
		{"s", handle_string},
		{"%", handle_percent},
		{"b", handle_binary},
		{"o", handle_octal},
		{"u", handle_unsigned},
		{"x", handle_hex},
		{"X", handle_HEX},
		{"p", handle_pointer},
		{"S", handle_not_printable},
		{"r", handle_string_reverse},
		{"R", handle_rot13},
		{NULL, NULL}
	};

	int x = 0;

	while (specifiers[x].specifier)
	{
		if (*s == specifiers[x].specifier[0])
		{
			return (specifiers[x].handler);
		}
		x++;
	}
	return (NULL);
}

/**
 * get_print_handler - finds the format func
 * @s: the format string
 * @ap: argument pointer
 * @arguments: the parameters struct
 *
 * Return: the number of bytes printed
 */
int get_print_handler(char *s, va_list ap, arguments_t *arguments)
{
	int (*f)(va_list, arguments_t *) = get_handler(s);

	if (f)
		return (f(ap, arguments));
	return (0);
}

/**
 * init_arguments - clears struct fields and reset buf
 * @arguments: the parameters struct
 * @ap: the argument pointer
 *
 * Return: void
 */
void init_arguments(arguments_t *arguments, va_list ap)
{
	arguments->unsigned_var = 0;
	arguments->plus_arg = 0;
	arguments->space_arg = 0;
	arguments->hashtag_arg = 0;
	arguments->zero_arg = 0;
	arguments->minus_arg = 0;
	arguments->width = 0;
	arguments->precision = UINT_MAX;
	arguments->shrt_modifier = 0;
	arguments->long_modifier = 0;
	(void)ap;
}
