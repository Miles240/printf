#include "main.h"

/**
 * _printf - prints a formatted string to the stdout
 * @format: ...
 *
 * Return: formatted string
 */

int _printf(const char *format, ...)
{
	char c, *str, num_str[12], binary_str[33];
	int chars_printed = 0, i, num, len;
	unsigned int num2;
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

			case 'd':
				num = va_arg(args, int);
				len = sprintf(num_str, "%d", num);
				write(1, num_str, len);
				chars_printed += len;
				break;
			case 'i':
				num = va_arg(args, int);
				len = sprintf(num_str, "%d", num);
				write(1, num_str, len);
				chars_printed += len;
				break;
			case 'b':
				num2 = va_arg(args, unsigned int);
				for (i = 31; i >= 0; i--)
				{
					binary_str[31 - i] = ((num2 >> i) & 1) ? '1' : '0';
				}
				binary_str[32] = '\0';
				write(1, binary_str, 32);
				chars_printed += 32;
				break;
			case 'u':
				num2 = va_arg(args, unsigned int);
				len = sprintf(num_str, "%u", num2);
				write(1, num_str, len);
				chars_printed += len;
				break;
			case 'o':
				num2 = va_arg(args, unsigned int);
				len = sprintf(num_str, "%o", num2);
				write(1, num_str, len);
				chars_printed += len;
				break;
			case 'x':
				num2 = va_arg(args, unsigned int);
				len = sprintf(num_str, "%x", num2);
				write(1, num_str, len);
				chars_printed += len;
				break;
			case 'X':
				num2 = va_arg(args, unsigned int);
				len = sprintf(num_str, "%X", num2);
				write(1, num_str, len);
				chars_printed += len;
				break;
			case 'S':
				str = va_arg(args, char *);
				while (*str)
				{
					if (*str < 32 || *str >= 127)
					{
						char hex[3];
						sprintf(hex, "%02X", (unsigned char)*str);
						write(1, "\\x", 2);
						write(1, hex, 2);
						chars_printed += 4;
					}
					else
					{
						write(1, str, 1);
						chars_printed++;
					}
					str++;
				}
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
