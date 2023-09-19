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

if (format == NULL || (format[0] == '%' && format[1] == '\0'))
return (-1);

while (*format)
{
if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
{

int r = va_arg(g, int);
char buffer[12];
int i;
int j;
int neg;

i = 0;
neg = 0;

if (r < 0)
{
neg = 1;
r = -r;
}

do {
buffer[i++] = (char)(r % 10 + '0');
r /= 10;
} while (r);

if (neg)
{
buffer[i++] = '-';
}

for (j = 0; j < i / 2; j++)
{
char tmp = buffer[j];
buffer[j] = buffer[i - j - 1];
buffer[i - j - 1] = tmp;
}

write(1, buffer, i);
as = as + i;
format = format + 2;
}
else if (*format == '%' && (*(format + 1) == 'c' || *(format + 1) == 's'))
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
else if (*format == '%' && (*(format + 1) == '+' ||
*(format + 1) == ' ' || *(format + 1) == '#'))
{
char flag = *(format + 1);

format += 2;

if (*(format) == 'd' || *(format) == 'i')
{
	int r = va_arg(g, int);
	char buffer[12];
	int i;

	if (flag == '+')
		i = sprintf(buffer, "%+d", r);
	else if (flag == ' ')
		i = sprintf(buffer, "% d", r);
	else if (flag == '#')
		i = sprintf(buffer, "%d", r);
	else
		i = sprintf(buffer, "%d", r);

	write(1, buffer, i);
	as += i;
}
}
else if (*format == '%' && *(format + 1) == 'p')
{
    void *p = va_arg(g, void *);
    unsigned long ad = (unsigned long)p;
    char hex[17] = "0123456789ABCDEF";
    int i;
    int j;
    i = 0;

    do {
        buffer[i++] = hex[ad % 16];
        ad /= 16;
    } while (ad);

    buffer[i++] = 'x';
    buffer[i++] = '0';

    for (j = i - 1; j >= 0; j--) {
        write(1, &buffer[j], 1);
    }

    as = as + i;
    format = format + 2;
}
else if (*format == '%' && (*(format + 1) == '%' || *(format + 1) == '\0'))
{
write(1, "%", 1);
as++;
format = format + 2;
}
else if (*format == '%' && *(format + 1) == 'b')
{
unsigned int r = va_arg(g, unsigned int);
char binary[33];
int i;

binary[32] = '\0';
i = 31;

while (i >= 0)
{
binary[i] = (r & 1) ? '1' : '0';
r >>= 1;
i--;
}

i = 0;
while (binary[i] == '0' && i < 32)
{
i++;
}

write(1, binary + i, 32 - i);
as = as + 32 - i;
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


