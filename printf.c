#include "main.h"



/**
 * _printchar - prints character
 *
 * Return: Nothing
 *
 */

void _printchar(void)
{
	_putchar(va_arg(id.args, int));
	id.count++;
}

/**
 * _printstr - prints str
 *
 * Return: Nothing
 *
 */

void _printstr(void)
{
	id.str = va_arg(id.args, char *);
	if (id.str == NULL)
		id.str = "(null)";
	else
	{
		id.j = 0;
		while (id.str[id.j] != '\0')
		{
		_putchar(id.str[id.j]);
		id.j++;
		id.count++;
		}
	}
}

/**
 * _printint - prints integer
 *
 * Return: void
*/

void _printint(void)
{
	int num, div, len;

	num = va_arg(id.args, int);
	div = 1;
	len = 0;
	if (num < 0)
	{
		_putchar('-');
		num = num * -1;
		id.count++;
	}
	if (num == 0)
	{
		_putchar('0');
		id.count++;
	}
	while (num / div > 0)
	{
		div = div * 10;
		len++;
	}
	div = div / 10;
	while (len > 0)
	{
		_putchar(((num / div) % 10) + '0');
		div = div / 10;
		len--;
		id.count++;
	}
}

/**
 * _printf - produces output according to a format
 * @format: character string
 * Return: number of characters printed
 */


int _printf(const char *format, ...)
{
	id.i = 0, id.j = 0, id.count = 0;
	if (format == NULL)
		return (-1);
	va_start(id.args, format);
	while (format[id.i] != '\0')
	{
		if (format[id.i] == '%')
		{
			id.i++;
			if (format[id.i] == 'c')
				_printchar();
			else if (format[id.i] == 's')
				_printstr();
			else if (format[id.i] == 'd' || format[id.i] == 'i')
				_printint();
			else if (format[id.i] == '%')
				_putchar('%');
			else
			{
				_putchar('%');
				_putchar(format[id.i]);
				id.count += 2;
			}
		}
		else
		{
			_putchar(format[id.i]);
			id.count++;
		}
		id.i++;
	}
	va_end(id.args);
	return (id.count);
}
