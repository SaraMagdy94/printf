#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include "main.h"

/**
 * _printf - printf function
 * @format: Format string
 * @...: Variable arguments
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
int x = 0;
va_list g;
va_start(g, format);

while (*format)
{
if (*format == '%' && (*(format + 1) == 'c' || *(format + 1) == 's'))
{
char *sr = va_arg(g, char *);
if (*(format + 1) == 'c')
write(1, sr, 1);
else if (sr)
while (*sr)
write(1, sr++, 1);
else
write(1, "(null)", 6);
x = x + (*(format + 1) == 's' && sr) ? strlen(sr) : 1;
format = format + 2;
}
else if (*format == '%' && (*(format + 1) == '%' || *(format + 1) == '\0'))
{
write(1, "%", 1);
x++;
format = format + 2;
}
else
{
write(1, format++, 1);
x++;
}
}

va_end(g);
return (x);
}
