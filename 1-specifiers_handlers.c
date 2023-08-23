#include "main.h"

/**
 * handle_unsigned - prints unsigned integer numbers
 * @ap: argument pointer
 * @arguments: the parameters struct
 *
 * Return: bytes printed
 */
int handle_unsigned(va_list ap, arguments_t *arguments)
{
	unsigned long l;

	if (arguments->long_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (arguments->shrt_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	arguments->unsigned_var = 1;
	return (print_number(convert(l, 10, CONVERT_UNSIGNED, arguments), arguments));
}

/**
 * handle_hex - prints unsigned hex numbers in lowercase
 * @ap: the argument pointer
 * @arguments: the parameters struct
 *
 * Return: bytes printed
 */
int handle_hex(va_list ap, arguments_t *arguments)
{
	unsigned long l;
	int x = 0;
	char *str;

	if (arguments->long_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (arguments->shrt_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, arguments);
	if (arguments->hashtag_arg && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	arguments->unsigned_var = 1;
	return (x += print_number(str, arguments));
}

/**
 * handle_HEX - prints unsigned hex numbers in uppercase
 * @ap: the argument pointer
 * @arguments: the parameters struct
 *
 * Return: bytes printed
 */
int handle_HEX(va_list ap, arguments_t *arguments)
{
	unsigned long l;
	int x = 0;
	char *str;

	if (arguments->long_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (arguments->shrt_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED, arguments);
	if (arguments->hashtag_arg && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	arguments->unsigned_var = 1;
	return (x += print_number(str, arguments));
}
/**
 * handle_binary - prints unsigned binary number
 * @ap: the argument pointer
 * @arguments: the parameters struct
 *
 * Return: bytes printed
 */
int handle_binary(va_list ap, arguments_t *arguments)
{
	unsigned int n = va_arg(ap, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, arguments);
	int x = 0;

	if (arguments->hashtag_arg && n)
		*--str = '0';
	arguments->unsigned_var = 1;
	return (x += print_number(str, arguments));
}

/**
 * handle_octal - prints unsigned octal numbers
 * @ap: the argument pointer
 * @arguments: the parameters struct
 *
 * Return: bytes printed
 */
int handle_octal(va_list ap, arguments_t *arguments)
{
	unsigned long l;
	char *str;
	int x = 0;

	if (arguments->long_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (arguments->shrt_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	str = convert(l, 8, CONVERT_UNSIGNED, arguments);

	if (arguments->hashtag_arg && l)
		*--str = '0';
	arguments->unsigned_var = 1;
	return (x += print_number(str, arguments));
}
