#include "main.h"

/*
* print_char - prints a formatted character
*prin
*/

int print_char(char c) {
    char buffer[2];
    buffer[0] = c;
    buffer[1] = '\0';
    write(1, buffer, 1);
    return 1;
}

int print_string(const char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    write(1, str, len);
    return len;
}

int print_integer(int num) {
    char num_str[12];
    int len = sprintf(num_str, "%d", num);
    write(1, num_str, len);
    return len;
}

int print_unsigned(unsigned int num) {
    char num_str[12];
    int len = sprintf(num_str, "%u", num);
    write(1, num_str, len);
    return len;
}

int print_octal(unsigned int num) {
    char num_str[12];
    int len = sprintf(num_str, "%o", num);
    write(1, num_str, len);
    return len;
}

int print_hex(unsigned int num, int uppercase) {
    char num_str[12];
    int len;
    if (uppercase) {
        len = sprintf(num_str, "%X", num);
    } else {
        len = sprintf(num_str, "%x", num);
    }
    write(1, num_str, len);
    return len;
}

int my_printf(const char *format, ...) {
    int chars_printed = 0;
    va_list args;
    char buffer[1024];
    int buffer_index = 0;
    
    va_start(args, format);

    while (*format != '\0') {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c':
                    chars_printed += print_char(va_arg(args, int));
                    break;
                case 's':
                    chars_printed += print_string(va_arg(args, char *));
                    break;
                case 'd':
                case 'i':
                    chars_printed += print_integer(va_arg(args, int));
                    break;
                case 'u':
                    chars_printed += print_unsigned(va_arg(args, unsigned int));
                    break;
                case 'o':
                    chars_printed += print_octal(va_arg(args, unsigned int));
                    break;
                case 'x':
                    chars_printed += print_hex(va_arg(args, unsigned int), 0);
                    break;
                case 'X':
                    chars_printed += print_hex(va_arg(args, unsigned int), 1);
                    break;
                case '%':
                    chars_printed += print_char('%');
                    break;
            }
        } else {
            buffer[buffer_index++] = *format;
            chars_printed++;
        }

        if (buffer_index >= 1024) {
            write(1, buffer, buffer_index);
            buffer_index = 0;
        }

        format++;
    }

    if (buffer_index > 0) {
        write(1, buffer, buffer_index);
    }
    
    va_end(args);
    return chars_printed;
}
