#include "main.h"

/**
 * print_int - prints formated integers
 * @num: param
 * Return: the length of thr integer
 */

int print_int(int num)
{
	char num_str[12];
	int len;

	len = sprintf(num_str, "%d", num);
	write(1, num_str, len);
	return (len);
}
