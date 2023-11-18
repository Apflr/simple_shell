#include "file.h"

/**
 * _erratoi - transform string to int.
 * @s: Str to transform
 * Return: 0 if no num, the converted number otherwise, -1 on error.
 */
int _erratoi(char *s)
{
	int t = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;  /* TODO: why does this make main return 255? */
	for (t = 0;  s[t] != '\0'; t++)
	{
		if (s[t] >= '0' && s[t] <= '9')
		{
			result *= 10;
			result += (s[t] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - writes error messages.
 * @info: Param & return info struct.
 * @estr: str having specified type of errors.
 * Return: No num return 0, the converted number otherwise, -1 on error.
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - func to print decimal  number (base 10).
 * @input: Input.
 * @fd: File descriptor to write .
 * Return: Num of char printed.
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int t, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (t = 1000000000; t > 1; t /= 10)
	{
		if (_abs_ / t)
		{
			__putchar('0' + current / t);
			count++;
		}
		current %= t;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - transforms function, clone of itoa.
 * @num: Num
 * @base: Base.
 * @flags: arg flags.
 * Return: Str.
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - fucn to replace  first instance of '#' with '\0'.
 * @buf: String address to modify.
 * Return: Always 0 Success.
 */
void remove_comments(char *buf)
{
	int v;

	for (v = 0; buf[v] != '\0'; v++)
		if (buf[v] == '#' && (!v || buf[v - 1] == ' '))
		{
			buf[v] = '\0';
			break;
		}
}
