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
When parsing a format string in the custom printf-like implementation, these functions are responsible for handling specific format specifiers encountered (e.g., %c, %d, %s). They format and print the corresponding data based on the formatting options and flags specified within the format string.

7-"print_number.c"
This set of utility functions is designed to support the functionality of a custom printf-like implementation. These functions handle tasks related to character digit checking, string length calculation, and formatting and printing of numbers.

Included Functions
int _isdigit(int c): Checks whether a character is a digit (0-9).

int _strlen(char *s): Returns the length of a string.

int print_number(char *str, params_t *params): Prints numbers with various formatting options.

int print_number_right_shift(char *str, params_t *params): Prints numbers right-aligned with padding.

int print_number_left_shift(char *str, params_t *params): Prints numbers left-aligned with padding.

Function Purpose
These utility functions are essential components of a custom printf-like implementation. They are used to manage and format data that is passed as arguments to the custom _printf function. They handle tasks like checking if a character is a digit, calculating the length of a string, and formatting and printing numbers with various alignment and padding options.

8-"simple_printers.c"
This set of utility functions provides additional capabilities for a custom printf-like implementation. These functions allow for printing specific ranges of characters, reversing strings, and performing ROT13 encoding.

Included Functions
int print_from_to(char *start, char *stop, char *except): Prints characters in a specified range of memory addresses while excluding a specific address.

int print_rev(va_list ap, params_t *params): Prints a string in reverse order.

int print_rot13(va_list ap, params_t *params): Prints a string using the ROT13 cipher algorithm.

Function Purpose
These utility functions enhance the capabilities of the custom printf-like implementation. They offer functionalities such as selective printing of characters within a range, reversing strings, and applying the ROT13 cipher for text encoding.

9-"specifier.c"
This set of functions is responsible for identifying format specifiers, parsing formatting options, and determining the corresponding formatting function. These functions enable the core functionality of formatting and printing various data types based on the provided format string.

Included Functions
int (*get_specifier(char *s))(va_list ap, params_t *params): Identifies the appropriate formatting function based on a given format specifier character.

int get_print_func(char *s, va_list ap, params_t *params): Retrieves the formatting function corresponding to a format specifier and invokes it with the provided arguments.

int get_flag(char *s, params_t *params): Identifies and sets formatting flags based on the characters present in the format string.

int get_modifier(char *s, params_t *params): Identifies and sets modifier flags based on the characters in the format string.

char *get_width(char *s, params_t *params, va_list ap): Extracts and assigns the width from the format string, accounting for variable arguments.

Function Purpose
These functions work together to identify and parse format specifiers, extract formatting options, and manage various formatting flags and modifiers. They ensure that the correct formatting function is invoked and that the output is formatted as specified.
