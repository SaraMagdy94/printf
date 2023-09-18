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
char buffer[1024];
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
buffer[0] = x;
write(1, buffer, 1);
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
<<<<<<< HEAD
else if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
{
int r = va_arg(g, int);
char buffer[12];
int i = sprintf(buffer, "%d", r);
write(1, buffer, i);
as = as + i;
format = format + 2;
}
=======
>>>>>>> eee0e2f5625479c46bc053aa4b981817e0f82c66
else if (*format == '%' && (*(format + 1) == 'u' ||
*(format + 1) == 'o' || *(format + 1) == 'x' || *(format + 1) == 'X'))
{
unsigned int r = va_arg(g, unsigned int);
char buffer[32];
int i = 0;

if (*(format + 1) == 'u')
i = sprintf(buffer, "%u", r);
else if (*(format + 1) == 'o')
i = sprintf(buffer, "%o", r);
else if (*(format + 1) == 'x')
i = sprintf(buffer, "%x", r);
else if (*(format + 1) == 'X')
i = sprintf(buffer, "%X", r);

write(1, buffer, i);
as =  as + i;
format = format + 2;
}
else if (*format == '%' && (*(format + 1) == '%' || *(format + 1) == '\0'))
{
buffer[0] = '%';
write(1, buffer, 1);
as++;
format = format + 2;
}
else
{
buffer[0] = *format++;
write(1, buffer, 1);as++;
}
}
va_end(g);
return (as);
}
