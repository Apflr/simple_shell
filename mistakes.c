#include "naomi.h"
/**
 * _eputs - Generate a linked list of environment variables
 * @str: Structure holding possible arguments for 
 * maintaining a consistent function prototype
 * Return: 0 on Successful population
 */
void _eputs(char *str)
{
	int w = 0;

	if (!str)
		return;
	while (str[w] != '\0')
	{
		_eputchar(str[w]);
		w++;
	}
}

/**
 * _eputchar - write character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char c)
{
	static int x;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(2, buf, x);
		x = 0;
	}
	if (c != BUF_FLUSH)
		buf[x++] = c;
	return (1);
}

/**
 * _putfd -  Generate a linked list of environment variables
 * @c: char to be printed
 * @fd: The filedescriptor to write on
 *
 * Return: return 1 On success
 * On error, -1 , errno is set appropriately.
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putsfd - print input string
 * @str: the character to write
 * @fd: File descriptor for writing
 * Return: Returns 1 upon successful write.
 */
int _putsfd(char *str, int fd)
{
	int g = 0;

	if (!str)
		return (0);
	while (*str)
	{
		g += _putfd(*str++, fd);
	}
	return (g);
}
