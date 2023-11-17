#include "naomi.h"
/**
 **_strncpy - Duplicate a portion of the 
 *source string into the destination
 *@dest: dest string to cpy to
 *@src: strng source
 *@n: Number of characters to copy
 *Return: Resultant concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int b, j;
	char *s = dest;

	b = 0;
	while (src[b] != '\0' && b < n - 1)
	{
		dest[b] = src[b];
		b++;
	}
	if (b < n)
	{
		j = b;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat - Merge two strings together
 *@dest: Merge two strings together
 *@src: The string to append
 *@n: Maximum number of bytes to utilize
 *Return: The resulting concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int m, k;
	char *s = dest;

	m = 0;
	k = 0;
	while (dest[m] != '\0')
		m++;
	while (src[k] != '\0' && k < n)
	{
		dest[m] = src[k];
		m++;
		k++;
	}
	if (k < n)
		dest[m] = '\0';
	return (s);
}

/**
 **_strchr - Find a character in the given string
 *@s: String to be searched
 *@c: Character to locate
 *Return: A pointer to the first occurrence 
 *of the character in the string 's'
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
