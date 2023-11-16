#include "naomi.h"
/**
 * _erratoi -  a function that converts
 * string to interger
 * @s: string to be converted
 * Return: always success
 */
int _erratoi(char *s)
{
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;  /* TODO: why does this make main return 255? */
	for (i = 0;  s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - prints error messageS
 * @info: parameter AND return info OF struct
 * @estr: string contains THE  specified type of ERRORS
 * Return: ALWAYS SUCCESS
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
 * print_d - function print decimals (integer) numBERS  TO base 10
 * @input: EXPECTS input
 * @fd: filedescriptor to writTEN on
 *
 * Return: number of charACTERS printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int y, count = 0;
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
	for (y = 1000000000; y > 1; y /= 10)
	{
		if (_abs_ / y)
		{
			__putchar('0' + current / y);
			count++;
		}
		current %= y;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - changes func, clone of itoa
 * @num: numbeR
 * @base: base
 * @flags: argument to  flags
 * Return: always success
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
 * remove_comments - function that changes first instance of '#' with '\0'
 * @buf: string address to changed
 * Return: success
 */
void remove_comments(char *buf)
{
	int g;

	for (g = 0; buf[g] != '\0'; g++)
		if (buf[g] == '#' && (!g || buf[g - 1] == ' '))
		{
			buf[g] = '\0';
			break;
		}
}
