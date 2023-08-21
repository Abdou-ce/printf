#include "main.h"

/**
 * _printf - custom printf function
 * @format: the format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int total_bytes = 0;
	va_list args;
	char *format_ptr, *start_ptr;
	params_t params = PARAMS_INIT;

	va_start(args, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (format_ptr = (char *)format; *format_ptr; format_ptr++)
	{
		init_params(&params, args);
		if (*format_ptr != '%')
		{
			total_bytes += _putchar(*format_ptr);
			continue;
		}
		start_ptr = format_ptr;
		format_ptr++;
		while (get_flag(format_ptr, &params))
		{
			format_ptr++;
		}
		format_ptr = get_width(format_ptr, &params, args);
		format_ptr = get_precision(format_ptr, &params, args);
		if (get_modifier(format_ptr, &params))
			format_ptr++;
		if (!get_specifier(format_ptr))
			total_bytes += print_from_to(start_ptr, format_ptr,
				params.l_modifier || params.h_modifier ? format_ptr - 1 : 0);
		else
			total_bytes += get_print_func(format_ptr, args, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(args);
	return (total_bytes);
}
