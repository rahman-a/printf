#include "main.h"

/**
 * handle_char - prints character
 * @ap: argument pointer
 * @arguments: the parameters struct
 *
 * Return: number chars printed
 */

int handle_char(va_list ap, arguments_t *arguments)
{
	char pad_char = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(ap, int);

	if (arguments->minus_arg)
		sum += _putchar(ch);
	while (pad++ < arguments->width)
		sum += _putchar(pad_char);
	if (!arguments->minus_arg)
		sum += _putchar(ch);
	return (sum);
}

/**
 * handle_int - prints integer
 * @ap: argument pointer
 * @arguments: the parameters struct
 *
 * Return: number chars printed
 */
int handle_int(va_list ap, arguments_t *arguments)
{
	long l;

	if (arguments->long_modifier)
		l = va_arg(ap, long);
	else if (arguments->shrt_modifier)
		l = (short int)va_arg(ap, int);
	else
		l = (int)va_arg(ap, int);
	return (print_number(convert(l, 10, 0, arguments), arguments));
}

/**
 * handle_string - prints string
 * @ap: argument pointer
 * @arguments: the parameters struct
 *
 * Return: number chars printed
 */
int handle_string(va_list ap, arguments_t *arguments)
{
	char *str = va_arg(ap, char *), pad_char = ' ';
	unsigned int pad = 0, sum = 0, y = 0, x;

	(void)arguments;
	switch ((int)(!str))
	case 1:
		str = NULL_STRING;

	x = pad = _strlen(str);
	if (arguments->precision < pad)
		x = pad = arguments->precision;

	if (arguments->minus_arg)
	{
		if (arguments->precision != UINT_MAX)
			for (y = 0; y < pad; y++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	while (x++ < arguments->width)
		sum += _putchar(pad_char);
	if (!arguments->minus_arg)
	{
		if (arguments->precision != UINT_MAX)
			for (y = 0; y < pad; y++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	return (sum);
}

/**
 * handle_percent - prints string
 * @ap: argument pointer
 * @arguments: the parameters struct
 *
 * Return: number chars printed
 */
int handle_percent(va_list ap, arguments_t *arguments)
{
	(void)ap;
	(void)arguments;
	return (_putchar('%'));
}

/**
 * handle_not_printable - custom format specifier
 * @ap: argument pointer
 * @arguments: the parameters struct
 *
 * Return: number chars printed
 */
int handle_not_printable(va_list ap, arguments_t *arguments)
{
	char *str = va_arg(ap, char *);
	char *hex;
	int sum = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*str, 16, 0, arguments);
			if (!hex[1])
				sum += _putchar('0');
			sum += _puts(hex);
		}
		else
		{
			sum += _putchar(*str);
		}
	}
	return (sum);
}
