#include "main.h"

int _printf(const char *format, ...)
{
	char c, *str, num_str[12], binary_str[33];
	int chars_printed = 0, num, len, buffer_index = 0;
	unsigned int num2;
	va_list args;
	char buffer[1024]; // Local buffer

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
				buffer[buffer_index++] = c;
				chars_printed++;
				break;
			case 's':
				str = va_arg(args, char *);
				while (*str != '\0')
				{
					buffer[buffer_index++] = *str;
					str++;
					chars_printed++;
				}
				break;
			case '%':
				buffer[buffer_index++] = '%';
				chars_printed++;
				break;
			case 'd':
			case 'i':
				num = va_arg(args, int);
				len = sprintf(num_str, "%d", num);
				for (int i = 0; i < len; i++)
				{
					buffer[buffer_index++] = num_str[i];
				}
				chars_printed += len;
				break;
			case 'u':
				num2 = va_arg(args, unsigned int);
				len = sprintf(num_str, "%u", num2);
				for (int i = 0; i < len; i++)
				{
					buffer[buffer_index++] = num_str[i];
				}
				chars_printed += len;
				break;
			case 'o':
				num2 = va_arg(args, unsigned int);
				len = sprintf(num_str, "%o", num2);
				for (int i = 0; i < len; i++)
				{
					buffer[buffer_index++] = num_str[i];
				}
				chars_printed += len;
				break;
			case 'x':
				num2 = va_arg(args, unsigned int);
				len = sprintf(num_str, "%x", num2);
				for (int i = 0; i < len; i++)
				{
					buffer[buffer_index++] = num_str[i];
				}
				chars_printed += len;
				break;
			case 'X':
				num2 = va_arg(args, unsigned int);
				len = sprintf(num_str, "%X", num2);
				for (int i = 0; i < len; i++)
				{
					buffer[buffer_index++] = num_str[i];
				}
				chars_printed += len;
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
	return chars_printed;
}
