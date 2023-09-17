#include <unistd.h>
#include <stdarg.h>
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
if (*format == '%' && (*(format + 1) == 'c' || *(format + 1) == 's'))
{
if (*(format + 1) == 'c')
{
char x = va_arg(g, int);
write(1, &x, 1);
as++;
}
else
{
char *sr = va_arg(g, char *);
if (sr)
{
while (*sr)
{
write(1, sr++, 1);
as++;
}
}
else
{
write(1, "(null)", 6);
as = as + 6;
}
}
format = format + 2;
}
else if (*format == '%' && (*(format + 1) == '%' || *(format + 1) == '\0'))
{
write(1, "%", 1);
as++;
format = format + 2;
}
else
{
write(1, format++, 1);
as++;
}
}

va_end(g);
return (as);
}

