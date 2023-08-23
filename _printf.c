#include "main.h"

/**
 * _printf - prints anything
 * @format: the format string
 *
 * Return: number of bytes printed
 */

int _printf(const char *format, ...)
{
	int sum = 0;
	va_list ap;
	char *x, *start;
	arguments_t arguments = ARGUMENTS_INIT;

	va_start(ap, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (x = (char *)format; *x; x++)
	{
		init_arguments(&arguments, ap);
		if (*x != '%')
		{
			sum += _putchar(*x);
			continue;
		}
		start = x;
		x++;
		while (handle_flag(x, &arguments))
		{
			x++;
		}
		x = handle_width(x, &arguments, ap);
		x = handle_precision(x, &arguments, ap);
		if (handle_modifier(x, &arguments))
			x++;
		if (!get_handler(x))
			sum += print_from_to(start, x,
					arguments.long_modifier || arguments.shrt_modifier ? x - 1 : 0);
		else
			sum += get_print_handler(x, ap, &arguments);
	}
	_putchar(BUF_FLUSH);
	va_end(ap);
	return (sum);
}
