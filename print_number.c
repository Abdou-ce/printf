#include "main.h"

/**
 * _isdigit - checks if the character is a digit
 * @c: character to be checked
 *
 * Return: 1 if digit, 0 otherwise
*/

int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: string to be checked
 *
 * Return: length of string
*/

int _strlen(char *s)
{
	int y = 0;

	while (*s++)
		y++;

	return (y);
}

/**
 * print_number - prints a number with options
 * @str: the base number as a string
 * @params: the parameter struct
 *
 * Return: the number of characters printed
*/

int print_number(char *str, params_t *params)
{
	unsigned int y = _strlen(str);
	int neg = (!params->unsign && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		y--;
	}
	if (params->precision != UINT_MAX)
	{
		for (; y < params->precision; y++)
			*--str = '0';
	}
	if (neg)
		*--str = '-';

	if (!params->minus_flag)
		return (print_number_right_shift(str, params));
	else
		return (print_number_left_shift(str, params));
}

/**
 * print_number_right_shift - prints a number right aligned
 * @str: the base number as a string
 * @params: the parameter struct
 *
 * Return: the number of characters printed
*/

int print_number_right_shift(char *str, params_t *params)
{
	unsigned int x = 0, neg, neg2, y = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *str == '-');
	if (neg && x < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		neg = 0;
	if ((params->plus_flag && !neg2) ||
		(!params->plus_flag && params->space_flag && !neg2))
		y++;
	if (neg && pad_char == '0')
		x += _putchar('-');
	if (params->plus_flag && !neg2 && pad_char == '0' && !params->unsign)
		x += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !neg2 &&
		!params->unsign && params->zero_flag)
		x += _putchar(' ');
	while (y++ < params->width)
		x += _putchar(pad_char);
	if (neg && pad_char == ' ')
		x += _putchar('-');
	if (params->plus_flag && !neg2 && pad_char == ' ' && !params->unsign)
		x += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !neg2 &&
		!params->unsign && !params->zero_flag)
		x += _putchar(' ');
	x += _puts(str);

	return (x);
}

/**
 * print_number_left_shift - prints a numberleft aligned
 * @str: the base number as a string
 * @params: the parameter struct
 *
 * Return: the number of characters printed
*/

int print_number_left_shift(char *str, params_t *params)
{
	unsigned int x = 0, neg, neg2, y = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *str == '-');

	if (neg && x < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		neg = 0;

	if (params->plus_flag && !neg2 && !params->unsign)
		x += _putchar('+'), y++;

	else if (params->space_flag && !neg2 && !params->unsign)
		x += _putchar(' '), y++;
	x += _puts(str);

	for (; y < params->width; y++)
		x += _putchar(pad_char);

	return (x);
}
