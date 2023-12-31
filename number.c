#include "main.h"

/**
 * convert - converts a number to a string with a specified base
 * @num: the number to be converted
 * @base: the base for the conversion
 * @flags: formatting flags
 * @params: the parameter struct
 *
 * Return: pointer to the resulting string
*/

char *convert(long int num, int base, int flags, params_t *params)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long y = num;
	(void)params;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		y = -num;
		sign = '-';
	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	for (; y != 0; y /= base)
	{
		*--ptr = array[y % base];
	}
	if (sign)
		*--ptr = sign;

	return (ptr);
}

/**
 * print_unsigned - prints unsigned integer numbers
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: The number of bytes printed
*/

int print_unsigned(va_list ap, params_t *params)
{
	unsigned long l;

	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);

	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);

	else
		l = (unsigned int)va_arg(ap, unsigned int);
	params->unsign = 1;

	return (print_number(convert(l, 10, CONVERT_UNSIGNED, params), params));
}

/**
 * print_address - prints addresses in hexadecimal format
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: the number of bytes printed
*/

int print_address(va_list ap, params_t *params)
{
	unsigned long int x = va_arg(ap, unsigned long int);
	char *str;

	if (!x)
		return (_puts("(nil)"));

	str = convert(x, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--str = 'x';
	*--str = '0';

	return (print_number(str, params));
}
