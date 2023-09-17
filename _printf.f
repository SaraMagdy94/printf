#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 * _printf - printf function
 * @format: Format string
 * @...: Variable arguments
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
int as = 0;
va_list g;
va_start(g, format);

while (*format)
{
if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
{
int x = va_arg(g, int);
int len = 0;
while (x > 0)
{
char y = x % 10 + '0';
write(1, &y, 1);
x /= 10;
len++;
}
as += len;
format += 2;
}
else
{
write(1, format, 1);
as++;
format++;
}
}

va_end(g);
return (as);
}
