#include "main.h"
/**
 * * print_from_to - prints a range of char addresses
 * @start: starting address
 * @stop: stopping address
 * @except: except address
 *
 * Return: number bytes printed
*/
int print_from_to(char *start, char *stop, char *except)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != except)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}

/**
 * print_number - prints a number with options
 * @str: the base number as a string
 * @arguments: the parameter struct
 *
 * Return: chars printed
 */
int print_number(char *str, arguments_t *arguments)
{
	unsigned int i = _strlen(str);
	int neg = (!arguments->unsigned_var && *str == '-');

	if (!arguments->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (arguments->precision != UINT_MAX)
		while (i++ < arguments->precision)
			*--str = '0';
	if (neg)
		*--str = '-';
	if (!arguments->minus_arg)
		return (handle_justify_right(str, arguments));
	else
		return (handle_justify_left(str, arguments));
}

/**
 * handle_justify_right - prints a number with options
 * @str: the base number as a string
 * @arguments: the parameter struct
 *
 * Return: chars printed
 */
int handle_justify_right(char *str, arguments_t *arguments)
{
	unsigned int x = 0, neg, neg2, y = _strlen(str);
	char pad_char = ' ';

	if (arguments->zero_arg && !arguments->minus_arg)
		pad_char = '0';
	neg = neg2 = (!arguments->unsigned_var && *str == '-');
	if (neg && x < arguments->width && pad_char == '0' && !arguments->minus_arg)
		str++;
	else
		neg = 0;
	if ((arguments->plus_arg && !neg2) ||
			(!arguments->plus_arg && arguments->space_arg && !neg2))
		y++;
	if (neg && pad_char == '0')
		x += _putchar('-');
	if (arguments->plus_arg && !neg2 && pad_char == '0'
			&& !arguments->unsigned_var)
		x += _putchar('+');
	else if (!arguments->plus_arg && arguments->space_arg && !neg2 &&
			!arguments->unsigned_var && arguments->zero_arg)
		x += _putchar(' ');
	while (y++ < arguments->width)
		x += _putchar(pad_char);
	if (neg && pad_char == ' ')
		x += _putchar('-');
	if (arguments->plus_arg && !neg2 && pad_char == ' '
			&& !arguments->unsigned_var)
		x += _putchar('+');
	else if (!arguments->plus_arg && arguments->space_arg && !neg2 &&
			!arguments->unsigned_var && !arguments->zero_arg)
		x += _putchar(' ');
	x += _puts(str);
	return (x);
}

/**
 * handle_justify_left - prints a number with options
 * @str: the base number as a string
 * @arguments: the parameter struct
 *
 * Return: chars printed
 */
int handle_justify_left(char *str, arguments_t *arguments)
{
	unsigned int x = 0, neg, neg2, y = _strlen(str);
	char pad_char = ' ';

	if (arguments->zero_arg && !arguments->minus_arg)
		pad_char = '0';
	neg = neg2 = (!arguments->unsigned_var && *str == '-');
	if (neg && x < arguments->width && pad_char == '0' && !arguments->minus_arg)
		str++;
	else
		neg = 0;

	if (arguments->plus_arg && !neg2 && !arguments->unsigned_var)
		x += _putchar('+'), y++;
	else if (arguments->space_arg && !neg2 && !arguments->unsigned_var)
		x += _putchar(' '), y++;
	x += _puts(str);
	while (y++ < arguments->width)
		x += _putchar(pad_char);
	return (x);
}
