#ifndef _function_h_
#define _function_h_
#include "main.h"

int print_char_wrapper(va_list args);
int print_string_wrapper(va_list args);
int print_int_wrapper(va_list args);
int print_unsigned_wrapper(va_list args);
int print_octal_wrapper(va_list args);
int print_hexa_wrapper(va_list args);
int print_percent_wrapper(va_list args);

#endif
