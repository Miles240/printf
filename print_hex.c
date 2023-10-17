#include "main.h"

/**
 * print_hexa - prints formated hexa-decimals
 * @num:param one
 * @uppercase: param two
 * Return: the length of the integer
 */

int print_hexa(unsigned int num, int uppercase)
{
	char num_str[12];
	int len;

	if (uppercase)
	{
		len = sprintf(num_str, "%X", num);
	}
	else
	{
		len = sprintf(num_str, "%x", num);
	}
	write(1, num_str, len);
	return (len);
}
