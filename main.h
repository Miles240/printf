#ifndef main_h
#define main_h
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int _printf(const char *format, ...);
int print_char(char c);
int print_string(const char *str);
int print_int(int num);
int print_unsigned(unsigned int num);
int print_octal(unsigned int num);
int print_hexa(unsigned int num, int uppercase);

#endif