#include "main.h"

/**
 * _puts - prints a string with a new line
 * @str: the string to print
 *
 * Return: void
*/

int _puts(char *str)
{
	char *y = str;

	while (*str)
		_putchar(*str++);

	return (str - y);
}

/**
 * _putchar - writes the character c to the stdout
 * @c: character to print
 *
 * Return: On success 1.
 *	On error, -1 is returned, and errno ise set appropriately
*/

int _putchar(int c)
{
	static char buf[OUTPUT_BUF_SIZE];
	static int x;

	if (c == BUF_FLUSH)
	{
		write(1, buf, x);
		x = 0;
	}
	else
	{
		buf[x++] = c;
		if (x >= OUTPUT_BUF_SIZE)
		{
			write(1, buf, x);
			x = 0;
		}
	}

	return (1);
}
