#include "main.h"

/**
 * print_char - prints formated characters
 * @c: param
 * Return: 1
 */

int print_char(char c)
{
	char buffer[2];

	buffer[0] = c;
	buffer[1] = '\0';
	write(1, buffer, 1);
	return (1);
}
