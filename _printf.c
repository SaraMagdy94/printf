#include <stdarg.h>
#include <unistd.h>
#include "main.h"
#include <stdio.h>
/**
 * _printf - printf function
 * @format: Format string
 * @...: Variable arguments
 * _strlen - Calculate the length of a string.
 * @str: The input string.
 * Return: Number of characters printed
 */
size_t _strlen(const char *str)
{
size_t l = 0;
while (str[l])
l++;
return (l);
}
int _printf(const char *format, ...)
{
int as = 0;
va_list g;
va_start(g, format);

while (*format)
{
if (*format == '%' && *(format + 1))
{
format++;
switch (*format)
{
case 'c':
{
char c = va_arg(g, int);
as = as + write(1, &c, 1);
break;
}
case 's':
{
const char *str = va_arg(g, const char *);
as = as + write(1, str, _strlen(str));
break;
}
case '%':
as = as + write(1, "%", 1);
break;
default:
as = as + write(1, "%", 1);
as = as + write(1, format, 1);
}
}
else
as = as + write(1, format, 1);
format++;
}
va_end(g);
return (as);
}


