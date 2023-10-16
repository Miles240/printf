#include "main.h"

/**
 * _printf - prints a formatted string to the stdout
 * @format: ...
 *
 * Return: formatted string
 */

int _printf(const char *format, ...)
{
	char c;
	char *str;
	int chars_printed = 0;
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'c':
				c = va_arg(args, int);
				write(1, &c, 1);
				chars_printed++;
				break;
			case 's':
				str = va_arg(args, char *);
				write(1, str, strlen(str));
				chars_printed += strlen(str);
				break;
			case '%':
				write(1, "%", 1);
				chars_printed++;
				break;
			}
		}
		else
		{
			write(1, format, 1);
			chars_printed++;
		}
		format++;
	}
	va_end(args);
	return (chars_printed);
}
