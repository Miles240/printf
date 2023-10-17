#include "main.h"

/**
 * print_unsigned - prints a formated unsigned integer
 * @num: param
 * Return: the length of the integer
 */

int print_unsigned(unsigned int num)
{
	char num_str[12];
	int len;

	len = sprintf(num_str, "%u", num);
	write(1, num_str, len);
	return (len);
}
