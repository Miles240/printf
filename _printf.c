#include "main.h"

/**
 * 
*/

int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	int chars_printed = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++; // Move past the '%'
			switch (*format)
			{
			case 'c':
				char c = va_arg(args, int);
				write(1, &c, 1); // Write the character to stdout
				chars_printed++;
				break;
			case 's':
				char *str = va_arg(args, char *);
				write(1, str, strlen(str)); // Write the string to stdout
				chars_printed += strlen(str);
				break;
			case '%':
				write(1, "%", 1); // Write a '%' character
				chars_printed++;
				break;
			}
		}
		else
		{
			write(1, format, 1); // Write other characters as is
			chars_printed++;
		}
		format++;
	}

	va_end(args);
	return chars_printed;
}

int main()
{
	int printed_chars = _printf("Hello, %c! This is a %s example. This is a %% character.\n", 'W', "printf");
	printf("Total characters printed: %d\n", printed_chars);
	return 0;
}
