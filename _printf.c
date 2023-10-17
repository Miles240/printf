#include "main.h"

/**
 * _printf - prints out foramated strings and intergers
 * @format: param
 * Return: the length of the outputed data
*/

int _printf(const char *format, ...)
{
	int chars_printed = 0;
	va_list args;
	char buffer[1024];
	int buffer_index = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'c':
				chars_printed += print_char(va_arg(args, int));
				break;
			case 's':
				chars_printed += print_string(va_arg(args, char *));
				break;
			case 'd':
			case 'i':
				chars_printed += print_int(va_arg(args, int));
				break;
			case 'u':
				chars_printed += print_unsigned(va_arg(args, unsigned int));
				break;
			case 'o':
				chars_printed += print_octal(va_arg(args, unsigned int));
				break;
			case 'x':
				chars_printed += print_hexa(va_arg(args, unsigned int), 0);
				break;
			case 'X':
				chars_printed += print_hexa(va_arg(args, unsigned int), 1);
				break;
			case '%':
				chars_printed += print_char('%');
				break;
			}
		}
		else
		{
			buffer[buffer_index++] = *format;
			chars_printed++;
		}
		if (buffer_index >= 1024)
		{
			write(1, buffer, buffer_index);
			buffer_index = 0;
		}
		format++;
	}
	if (buffer_index > 0)
	{
		write(1, buffer, buffer_index);
	}
	va_end(args);
	return (chars_printed);
}
