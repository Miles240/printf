#include "main.h"

/**
 * print_to_buffer - ....
 * @buffer: param one
 * @index: ...
 * @c: ...
 * @char_printed: ...
 * Return: 0
*/

int print_to_buffer(char buffer[], int *index, int *chars_printed, char c)
{
	buffer[(*index)++] = c;
	(*chars_printed)++;
	if (*index >= 1024)
	{
		write(1, buffer, *index);
		*index = 0;
	}
	return (0);
}

void print_char_impl(va_list args, char buffer[], int *index, int *chars_printed)
{
	char c = va_arg(args, int);
	print_to_buffer(buffer, index, chars_printed, c);
}

void print_string_impl(va_list args, char buffer[], int *index, int *chars_printed)
{
	const char *str = va_arg(args, char *);
	while (*str)
	{
		print_to_buffer(buffer, index, chars_printed, *str);
		str++;
	}
}

void print_integer_impl(va_list args, char buffer[], int *index, int *chars_printed)
{
	char num_str[12];
	int i;
	int len = sprintf(num_str, "%d", va_arg(args, int));
	for (i = 0; i < len; i++)
	{
		print_to_buffer(buffer, index, chars_printed, num_str[i]);
	}
}

void print_unsigned_impl(va_list args, char buffer[], int *index, int *chars_printed)
{
	char num_str[12];
	int i;
	int len = sprintf(num_str, "%u", va_arg(args, unsigned int));
	for (i = 0; i < len; i++)
	{
		print_to_buffer(buffer, index, chars_printed, num_str[i]);
	}
}
