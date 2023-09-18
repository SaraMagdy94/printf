#include <unistd.h>
#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

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
if (*format == '%' && (*(format + 1) == 'c' || *(format + 1) == 's'))
{
if (*(format + 1) == 'c')
{
char x = va_arg(g, int);
printChar(x, &as);
}
else
{
char *sr = va_arg(g, char *);
if (sr)
{
printString(sr, &as);
}
else
{
printString("(null)", &as);
}
}
format = format + 2;
}
else if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
{
int r = va_arg(g, int);
printInteger(r, &as);
format = format + 2;
}
else if (*format == '%' && (*(format + 1) == 'u' ||
*(format + 1) == 'o' || *(format + 1) == 'x' || *(format + 1) == 'X'))
{
unsigned int r = va_arg(g, unsigned int);
printUnsigned(r, &as);
format = format + 2;
}
else if (*format == '%' && *(format + 1) == 'p')
{
void *p = va_arg(g, void *);
printPointer(p, &as);
format = format + 2;
}
else if (*format == '%' && (*(format + 1) == '%' || *(format + 1) == '\0'))
{
printChar('%', &as);
format = format + 2;
}
else
{
printChar(*format++, &as);
}
}
va_end(g);
return (as);
}

