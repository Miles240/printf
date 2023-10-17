#include "main.h"
#include "function.h"

int print_char_wrapper(va_list args)
{
	return print_char(va_arg(args, int));
}

int print_string_wrapper(va_list args)
{
	return print_string(va_arg(args, char *));
}

int print_int_wrapper(va_list args)
{
	return print_int(va_arg(args, int));
}
