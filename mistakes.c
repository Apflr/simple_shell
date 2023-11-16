#include "naomi.h"
/**
 * _putsfd - Prints a string to a specified fd
 * @str: String to be displayed
 * @fd: filedescriptor to write to strng
 * Return: numb of chars to print
 */

int _putsfd(char *str, int fd)
{
	int t = 0;

	if (!str)
		return (0);
	while (*str)
	{
		t += _putfd(*str++, fd);
	}
	return (t);
}
/**
 * _eputchar - Prints a character to the standard error output (stderr).
 * @c: The character to displayed
 * Return: 1 on successful write.
 * If there's an error, returns -1, and sets the appropriate error code.
 */

int _eputchar(char c)
{
	static int v;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || v >= WRITE_BUF_SIZE)
	{
		write(2, buf, v);
		v = 0;
	}
	if (c != BUF_FLUSH)
		buf[v++] = c;
	return (1);
}
/**
 * _eputs - displays output string
 * @str: string printed
 * Return: Null
 */

void _eputs(char *str)
{
	int v = 0;

	if (!str)
		return;
	while (str[v] != '\0')
	{
		_eputchar(str[v]);
		v++;
	}
}
/**
 * _putfd - char c printed to file descriptor
 * @c: prints characters
 * @fd: file descriptor written on
 *
 * Return: return 1 if not
 * returns -1 , where error is set
 */

int _putfd(char c, int fd)
{
	static int t;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || t >= WRITE_BUF_SIZE)
	{
		write(fd, buf, t);
		t = 0;
	}
	if (c != BUF_FLUSH)
		buf[t++] = c;
	return (1);
}

