#include "main.h"

/**
 * handle_pointer - prints address
 * @list: argument pointer
 * @arguments: the parameters struct
 *
 * Return: bytes printed
 */
int handle_pointer(va_list list, arguments_t *arguments)
{
	unsigned long int x = va_arg(list, unsigned long int);
	char *str;

	if (!x)
		return (_puts("(nil)"));
	str = convert(x, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, arguments);
	*--str = 'x';
	*--str = '0';
	return (print_number(str, arguments));
}

/**
 * handle_string_reverse - prints string in reverse
 * @ap: string
 * @arguments: the parameters struct
 *
 * Return: number bytes printed
 */
int handle_string_reverse(va_list ap, arguments_t *arguments)
{
	int len, sum = 0;
	char *str = va_arg(ap, char *);
	(void)arguments;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			sum += _putchar(*str);
	}
	return (sum);
}

/**
 * handle_rot13 - prints string in rot13
 * @ap: string
 * @arguments: the parameters struct
 *
 * Return: number bytes printed
 */
int handle_rot13(va_list ap, arguments_t *arguments)
{
	int x, index;
	int count = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ap, char *);
	(void)arguments;

	x = 0;
	index = 0;
	while (a[x])
	{
		if ((a[x] >= 'A' && a[x] <= 'Z') || (a[x] >= 'a' && a[x] <= 'z'))
		{
			index = a[x] - 65;
			count += _putchar(arr[index]);
		}
		else
			count += _putchar(a[x]);
		x++;
	}
	return (count);
}
