#include "naomi.h"
/**
 * _strcat - combines two strings
 * @dest: The destination buffer
 * @src: The source buffer.
 * Return: Returns a pointer.
 */

char *_strcat(char *dest, char *src)
{
	char *fret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (fret);
}
/**
 * starts_with - determines if the string needle
 * begins with the substring haystack.
 * @haystack: The string to search
 * @needle: The substring to check.
 *
 * Return: Returns the address of the next character or NULL.
 */

char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}
/**
 * _strcmp - function compares two strings
 * @s1: The first string.
 * @s2: the  Second String
 *
 * Return: Returns a positive value if s1 is greater than s2,
 * zero if s1 is equal to s2,
 * and a negative value if s1 is less than s2.
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}
/**
 * _strlen -  calculates the length of a string.
 * @s: The string whose length is to be determined.
 * Return: an integer representing the length of the string
 */

int _strlen(char *s)
{
	int d = 0;

	if (!s)
		return (0);

	while (*s++)
		d++;
	return (d);
}
