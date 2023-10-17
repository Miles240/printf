#include "main.h"

/**
 * handle_percent - .....
 * @args: param one
 * @format: param two
 * @char_printed: param three
 * @buffer_index: param four
 * @buffer: param five
 * 
*/

void handle_percent(va_list args, const char *format, int *chars_printed, int *buffer_index, char buffer[])
{
	format++;
	switch (*format)
	{
	case 'c':
		print_char_impl(args, buffer, buffer_index, chars_printed);
		break;
	case 's':
		print_string_impl(args, buffer, buffer_index, chars_printed);
		break;
	case 'd':
	case 'i':
		print_integer_impl(args, buffer, buffer_index, chars_printed);
		break;
	case 'u':
		print_unsigned_impl(args, buffer, buffer_index, chars_printed);
		break;
	case 'o':
		chars_printed += print_octal(va_arg(args, unsigned int));
		break;
		break;
	case 'x':
	case 'X':
		chars_printed += print_hexa(va_arg(args, unsigned int), *format == 'X');
		break;
	case '%':
		break;
	}
}
