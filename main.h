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



void handle_percent(va_list args, const char *format, int *chars_printed, int *buffer_index, char buffer[]);
void print_unsigned_impl(va_list args, char buffer[], int *index, int *chars_printed);
void print_integer_impl(va_list args, char buffer[], int *index, int *chars_printed);
void print_string_impl(va_list args, char buffer[], int *index, int *chars_printed);
void print_char_impl(va_list args, char buffer[], int *index, int *chars_printed);
int print_to_buffer(char buffer[], int *index, int *chars_printed, char c);


#endif