#include "main.h"

/**
 * print_string - prints formated strings
 * @str: param
 * Return: the length of the string
 */

int print_string(const char *str)
{
	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	write(1, str, len);
	return (len);
}
