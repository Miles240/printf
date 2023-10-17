#include "main.h"

/**
 * print_octal - prints formated integers
 * @num: param
 * Return: the length of the integer
 */

int print_octal(unsigned int num)
{
	char num_str[12];
	int len;

	len = sprintf(num_str, "%o", num);
	write(1, num_str, len);
	return (len);
}
