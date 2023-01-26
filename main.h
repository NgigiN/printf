#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

struct global
{
	char *format;
	int i;
	int j;
	int count;
	va_list args;
	char *str;
} id;

int _printf(const char *format, ...);
int _putchar(char c);

#endif /* MAIN_H */

