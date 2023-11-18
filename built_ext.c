#include "file.h"

/**
 * _strncpy - record str.
 * @dest: dest string to copy to.
 * @src: Str src.
 * @n: Amount of char to copy.
 * Return: Conc str.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int m, k;
	char *s = dest;

	m = 0;
	while (src[m] != '\0' && m < n - 1)
	{
		dest[m] = src[m];
		m++;
	}
	if (m < n)
	{
		k = m;
		while (k < n)
		{
			dest[k] = '\0';
			k++;
		}
	}
	return (s);
}

/**
 * _strncat - Concat two str.
 * @dest: First str.
 * @src: Second str.
 * @n: amount of bytes to maximally use.
 * Return: Concat str.
 */
char *_strncat(char *dest, char *src, int n)
{
	int v, k;
	char *s = dest;

	v = 0;
	k = 0;
	while (dest[v] != '\0')
		v++;
	while (src[k] != '\0' && k < n)
	{
		dest[v] = src[k];
		v++;
		k++;
	}
	if (k < n)
		dest[v] = '\0';
	return (s);
}

/**
 * _strchr - finds char in the string.
 * @s: str to be parsed.
 * @c: Char to look for.
 * Return: (s) a ptr to the memory area s.
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
