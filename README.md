0x11. C - printf

1-"_printf.c"
The _printf function is a custom implementation of the popular printf function found in the C programming language. It offers similar formatting and printing capabilities, allowing users to output formatted text to the standard output stream. This implementation provides a comprehensive set of formatting options and supports various data types, flags, width, precision, and modifiers it features functions like : dynamic formatting, formatting flags, width and precision, modifier support, custom specifiers.

2-"puts.c"
The _puts and _putchar functions are integral components of a custom printf-like implementation. These functions are designed to efficiently manage the output of characters and strings to the standard output stream. By handling buffering and flushing of characters, they optimize the printing process and enhance the performance of the overall program it features functions like : dynamic buffer flushing, buffer management, efficient output handling.

3-"number.c"
The convert, print_unsigned, and print_address functions are integral components of a custom printf-like implementation. These functions are responsible for converting numeric values and addresses into formatted strings and printing them to the standard output stream. They provide essential functionality to handle various types of data representation in a custom printing context.

4-"convert_number.c"
The print_hex, print_HEX, print_binary, and print_octal functions are integral components of a custom printf-like implementation. These functions are responsible for converting and printing unsigned numeric values in different base representations, including hexadecimal (both lowercase and uppercase), binary, and octal.

5-"params.c"
The init_params function is a crucial part of a custom printf-like implementation. It is responsible for initializing the fields of a params_t struct, which holds formatting parameters and flags used during the printing process.

6-"print_functions.c"
This collection of functions is an integral part of a custom printf-like implementation. These functions handle the formatting and printing of different types of data based on format specifiers encountered in the format string.

Included Functions
int print_char(va_list ap, params_t *params): Prints a single character.

int print_int(va_list ap, params_t *params): Prints signed integer numbers.

int print_string(va_list ap, params_t *params): Prints strings.

int print_percent(va_list ap, params_t *params): Prints the percent character '%'.

int print_S(va_list ap, params_t *params): Prints strings while handling non-printable and extended ASCII characters.

Function Purpose
When parsing a format string in the custom printf-like implementation, these functions are responsible for handling specific format specifiers encountered (e.g., %c, %d, %s). They format and print the corresponding data based on the formatting options and flags specified within the format strin.
