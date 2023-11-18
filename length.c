#include "file.h"
/**
 * _strcpy -  Copy string
 * @dest: Dest
 * @src: Src
 *
 * Return: Des Ptr
 */
char *_strcpy(char *dest, char *src)
{
	int z = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[z])
	{
		dest[z] = src[z];
		z++;
	}
	dest[z] = 0;
	return (dest);
}

/**
 * _strdup - changes and deplicates the String
 * @str: Str duplicate transform
 *
 * Return: duplicated str pointer
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 * _puts - Print input str
 * @str: Printed string
 *
 * Return: Null
 */
void _puts(char *str)
{
	int z = 0;

	if (!str)
		return;
	while (str[z] != '\0')
	{
		_putchar(str[z]);
		z++;
	}
}

/**
 * _putchar - outputss  char c to stdout
 * @c:  char to be  print
 *
 * Return: 1 0n success
 * -1 on error is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int z;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || z >= WRITE_BUF_SIZE)
	{
		write(1, buf, z);
		z = 0;
	}
	if (c != BUF_FLUSH)
		buf[z++] = c;
	return (1);
}
