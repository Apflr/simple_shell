#include "naomi.h"
/**
 * _putchar - prints a character 'c' to the standard output (stdout)
 * @c:  Character to be printed
 *
 * Return: 1 0n success if not returns -1 on error
 */
int _putchar(char c)
{
	static int t;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || t >= WRITE_BUF_SIZE)
	{
		write(1, buf, t);
		t = 0;
	}
	if (c != BUF_FLUSH)
		buf[t++] = c;
	return (1);
}
/**
 * _strcpy -  copy a string from source to destination
 * @dest: Ptr to the destination string
 * @src: ptr to the source string
 * Return: Pointer to the destination string
 */
char *_strcpy(char *dest, char *src)
{
	int t = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[t])
	{
		dest[t] = src[t];
		t++;
	}
	dest[t] = 0;
	return (dest);
}
/**
 * _puts - displays input string
 * @str: copies string
 *
 * Return: nothing
 */
void _puts(char *str)
{
	int t = 0;

	if (!str)
		return;
	while (str[t] != '\0')
	{
		_putchar(str[t]);
		t++;
	}
}
/**
 * _strdup - Function to create a duplicate of a string
 * @str:  Pointer to the string to be duplicated
 * Return: Pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *fret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	fret = malloc(sizeof(char) * (length + 1));
	if (!fret)
		return (NULL);
	for (length++; length--;)
		fret[length] = *--str;
	return (fret);
}

