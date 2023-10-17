#include "main.h"
#include "function.h"

Specifier specifiers[] = {
	 {'c', print_char_wrapper},
	 {'s', print_string_wrapper},
	 {'d', print_int_wrapper},
	 {'i', print_int_wrapper},
	 {'u', print_unsigned_wrapper},
	 {'o', print_octal_wrapper},
	 {'x', print_hexa_wrapper},
	 {'X', print_hexa_wrapper},
	 {'%', print_percent_wrapper}};

int _printf(const char *format, ...)
{
	long unsigned int i;
	int chars_printed = 0, buffer_index = 0;
	char buffer[1024];

	va_list args;
	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			for (i = 0; i < sizeof(specifiers) / sizeof(specifiers[0]); i++)
			{
				if (*format == specifiers[i].specifier)
				{
					chars_printed += specifiers[i].printer(args);
					break;
				}
			}
			if (i == sizeof(specifiers) / sizeof(specifiers[0]))
			{
				buffer[buffer_index++] = '%';
				buffer[buffer_index++] = *format;
				chars_printed += 2;
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
	return chars_printed;
}
