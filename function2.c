#include "function.h"
#include "main.h"

int print_unsigned_wrapper(va_list args)
{
	return print_unsigned(va_arg(args, unsigned int));
}

int print_octal_wrapper(va_list args)
{
	return print_octal(va_arg(args, unsigned int));
}

int print_hexa_wrapper(va_list args)
{
	unsigned int val = va_arg(args, unsigned int);
	int is_upper = va_arg(args, int);
	return print_hexa(val, is_upper);
}

int print_percent_wrapper(va_list args)
{
	(void)args;
	return print_char('%');
}
