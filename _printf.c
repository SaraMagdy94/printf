#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

int _printf(const char *format, ...)
{
       int chars_printed = 0;
    char buffer[12];
    va_list args;
    va_start(args, format);

    while (*format)
    {
        if (*format == '%' && *(format + 1))
        {
            format++;
            if (*format == 'c')
            {
                char c = va_arg(args, int);
                chars_printed += write(1, &c, 1);
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char *);
                if (str)
                {
                    chars_printed += write(1, str, strlen(str));
                }
                else
                {
                    chars_printed += write(1, "(null)", 6);
                }
            }
            else if (*format == 'd' || *format == 'i')
            {
                int len = sprintf(buffer, "%d", va_arg(args, int));
                chars_printed += write(1, buffer, len);
            }
            else if (*format == 'u')
            {
                int len = sprintf(buffer, "%u", va_arg(args, unsigned int));
                chars_printed += write(1, buffer, len);
            }
            else if (*format == 'o')
            {
                int len = sprintf(buffer, "%o", va_arg(args, unsigned int));
                chars_printed += write(1, buffer, len);
            }
            else if (*format == 'x' || *format == 'X')
            {
                int len = sprintf(buffer, (*format == 'x') ? "%x" : "%X", va_arg(args, unsigned int));
                chars_printed += write(1, buffer, len);
            }
            else if (*format == 'p')
            {
                int len = sprintf(buffer, "%p", va_arg(args, void *));
                chars_printed += write(1, buffer, len);
            }
            else if (*format == '%')
            {
                chars_printed += write(1, "%", 1);
            }
        }
        else
        {
            chars_printed += write(1, format, 1);
        }
        format++;
    }

    va_end(args);
    return chars_printed;
}
