#include "main.h"

/**
 * print_char - prints a character
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: the number of characters printed
*/

int print_char(va_list ap, params_t *params)
{
	char pad_char = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(ap, int);

	if (params->minus_flag)
		sum += _putchar(ch);

	while (pad++ < params->width)
		sum += _putchar(pad_char);

	if (!params->minus_flag)
		sum += _putchar(ch);

	return (sum);
}

/**
 * print_int - prints an integer
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: the number of characters printed
*/

int print_int(va_list ap, params_t *params)
{
	long l;

	if (params->l_modifier)
		l = va_arg(ap, long);

	else if (params->h_modifier)
		l = (short int)va_arg(ap, int);
	else
		l = (int)va_arg(ap, int);

	return (print_number(convert(l, 10, 0, params), params));
}

/**
 * print_string - prints a string
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: the number of characters printed
*/
int print_string(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *), pad_char = ' ';
	unsigned int pad = 0, sum = 0, x = 0, y;

	(void)params;
	if (!str)
	{
		str = NULL_STRING;
	}

	y = pad = _strlen(str);
	if (params->precision < pad)
		y = pad = params->precision;

	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (x = 0; x < pad; x++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	while (y++ < params->width)
		sum += _putchar(pad_char);
	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (x = 0; x < pad; x++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}

	return (sum);
}

/**
 * print_percent - prints the percent character
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number of characters printed
*/

int print_percent(va_list ap, params_t *params)
{
	(void)ap;
	(void)params;

	return (_putchar('%'));
}

/**
 * print_S - pritns the custom format specifier
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
*/

int print_S(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *);
	char *hex;
	int sum = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));

	while (*str)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*str, 16, 0, params);

			if (!hex[1])
				sum += _putchar('0');
			sum += _puts(hex);
		}
		else
		{
			sum += _putchar(*str);
		}
		str++;
	}

	return (sum);
}
