#include "main.h"

/**
 * _print_from_to - prints a range of char addresses
 * @custom_start: starting address
 * @custom_stop: stopping address
 * @custom_except: except address
 *
 * Return: number bytes printed
 */
int _print_from_to(char *custom_start, char *custom_stop, char *custom_except)
{
	int custom_sum = 0;

	while (custom_start <= custom_stop)
	{
		if (custom_start != custom_except)
			custom_sum += custom_putchar(*custom_start);
		custom_start++;
	}
	return (custom_sum);
}

/**
 * custom_print_rev - prints string in reverse
 * @custom_ap: string
 * @custom_params: the parameters struct
 *
 * Return: number bytes printed
 */
int custom_print_rev(va_list custom_ap, params_t *custom_params)
{
	int custom_len, custom_sum = 0;
	char *custom_str = va_arg(custom_ap, char *);
	(void)custom_params;

	if (custom_str)
	{
		for (custom_len = 0; *custom_str; custom_str++)
			custom_len++;
		custom_str--;
		for (; custom_len > 0; custom_len--, custom_str--)
			custom_sum += custom_putchar(*custom_str);
	}
	return (custom_sum);
}

/**
 * custom_print_rot13 - prints string in rot13
 * @custom_ap: string
 * @custom_params: the parameters struct
 *
 * Return: number bytes printed
 */
int custom_print_rot13(va_list custom_ap, params_t *custom_params)
{
	int custom_i, custom_index;
	int custom_count = 0;
	char custom_arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *custom_a = va_arg(custom_ap, char *);
	(void)custom_params;

	custom_i = 0;
	custom_index = 0;
	while (custom_a[custom_i])
	{
		if ((custom_a[custom_i] >= 'A' && custom_a[custom_i] <= 'Z')
		    || (custom_a[custom_i] >= 'a' && custom_a[custom_i] <= 'z'))
		{
			custom_index = custom_a[custom_i] - 65;
			custom_count += custom_putchar(custom_arr[custom_index]);
		}
		else
			custom_count += custom_putchar(custom_a[custom_i]);
		custom_i++;
	}
	return (custom_count);
}
