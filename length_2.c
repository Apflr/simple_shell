#include "file.h"
/**
 * _strlen - outputs   a string
 * @s: string to the check
 *
 * Return: Intr string lenght
 */
int _strlen(char *s)
{
	int z = 0;

	if (!s)
		return (0);

	while (*s++)
		z++;
	return (z);
}

/**
 * _strcmp -   checks  two strangs
 * @s1: First Str
 * @s2: Second Str
 *
 * Return:  Positive if s1 > s2, zero if s1 == s2 ,Negative if s1 < s2
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
 * starts_with - checks needle starts with haystack
 * @haystack: Str  Search
 * @needle: Sub_str
 *
 * Return: address of  char  or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat -puts 2 str
 * @dest: Destn buff
 * @src: Buff src
 *
 * Return: Ptr on success
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
