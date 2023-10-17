#include "main.h"

/**
 * _printf - prints out the characters based on the format
 * @format: param
 *
 * Return: the length of the outputted format
*/

int _printf(const char *format, ...)
{
	int chars_printed = 0;
	char buffer[1024];
	int buffer_index = 0;
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			handle_percent(args, format, &chars_printed, &buffer_index, buffer);
		}
		else
		{
			print_to_buffer(buffer, &buffer_index, &chars_printed, *format);
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
