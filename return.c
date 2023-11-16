#include "naomi.h"
/**
 * _strchr -  Locates a character in the given string
 *@s: The string to be searched
 *@c: The character to find.
 *Return:  A pointer to the first occurrence of the character in the string
 *or NULL if the character is not found
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
/*
 *  _strncpy - Copies a specified number of characters
 *  from the source string to the destination string.
 *  @dest: The destination string to copy to.
 *  @src: The source string.
 *  @n: The number of characters to copy
 *   Return: A pointer to the destination
 *   string after the copy operation
 */
char *_strncpy(char *dest, char *src, int n)
{
	int o, p;
	char *s = dest;

	o = 0;
	while (src[o] != '\0' && o < n - 1)
	{
		dest[o] = src[o];
		o++;
	}
	if (o < n)
	{
		p = o;
		while (p < n)
		{
			dest[p] = '\0';
			p++;
		}
	}
	return (s);
}
/**
 * _strncat - Concatenates two strings with a specified limit on the number of bytes.
 * @dest: The first string.
 * @src: The second string.
 * @n: The maximum number of bytes to use from the source string
 * Return: A pointer to the concatenated string.
 */
char *_strncat(char *dest, char *src, int n)
{
	int e, a;
	char *s = dest;

	a = 0;
	e = 0;
	while (dest[a] != '\0')
		a++;
	while (src[a] != '\0' && e < n)
	{
		dest[a] = src[e];
		a++;
		e++;
	}
	if (e < n)
		dest[a] = '\0';
	return (s);
}
