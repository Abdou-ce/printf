#include "main.h"

/**
 * my_printf - custom printf function
 * @format: the format string
 *
 * Return: number of characters printed
 */
int my_printf(const char *format, ...)
{
	int total_bytes = 0;
	va_list args;
	char *format_ptr, *start_ptr;
	params_t custom_params = PARAMS_INIT;

	va_start(args, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (format_ptr = (char *)format; *format_ptr; format_ptr++)
	{
		init_params(&custom_params, args);
		if (*format_ptr != '%')
		{
			total_bytes += my_putchar(*format_ptr);
			continue;
		}
		start_ptr = format_ptr;
		format_ptr++;
		while (my_get_flag(format_ptr, &custom_params))
		{
			format_ptr++;
		}
		format_ptr = my_get_width(format_ptr, &custom_params, args);
		format_ptr = my_get_precision(format_ptr, &custom_params, args);
		if (my_get_modifier(format_ptr, &custom_params))
			format_ptr++;
		if (!my_get_specifier(format_ptr))
			total_bytes += my_print_from_to(start_ptr, format_ptr,
				custom_params.l_modifier || custom_params.h_modifier ? format_ptr - 1 : 0);
		else
			total_bytes += my_get_print_func(format_ptr, args, &custom_params);
	}
	my_putchar(BUF_FLUSH);
	va_end(args);
	return (total_bytes);
}
