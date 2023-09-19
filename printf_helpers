#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

/*
 * - printChar: Print a character
 * - printString: Print a string
 * - printInteger: Print an integer
 * - printUnsigned: Print an unsigned integer
 * - printPointer: Print a pointer
 */

/**
 *  printChar - Print a character
 *  @c: input char
 *  @as: pointer
 */
void printChar(char c, int *as)
{
	write(1, &c, 1);
	(*as)++;
}
/**
 *  printString - Print a string
 *  @str: pointerr
 *  @as: pointer
 */

void printString(const char *str, int *as)
{
	while (*str)
	{
		write(1, str++, 1);
		(*as)++;
	}
}
/**
 * printInteger - print integer
 * @num: integer input
 * @as: pointer
 */
void printInteger(int num, int *as)
{
	char buffer[12];
	int i;

	i = sprintf(buffer, "%d", num);
	write(1, buffer, i);
	(*as) += i;
}
/**
 * printUnsigned - print unsigned integer
 * @num: input
 * @as: pointer
 */
void printUnsigned(unsigned int num, int *as)
{
	char buffer[32];
	int i;

	i = sprintf(buffer, "%u", num);
	write(1, buffer, i);
	(*as) += i;
}
/**
 *  printPointer - print pointer
 *  @ptr: pointer
 *  @as: pointer
 */
void printPointer(void *ptr, int *as)
{
	char buffer[32];
	int l;

	sprintf(buffer, "%p", ptr);
	l = strlen(buffer);
	write(1, buffer, l);
	(*as) += l;
}
