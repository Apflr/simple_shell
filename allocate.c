#include "file.h"
/**
 * _memset - fills a memory block with a constant byte
 * @s:   Pointer to the memory block
 * @b:  Byte used to fill the memory block pointed to by *s
 * @n: Amount of bytes to be used
 * Return: pointer to return
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int y;

	for (y = 0; y < n; y++)
		s[y] = b;
	return (s);
}

/**
 * ffree - Releases memory occupied by a string array
 * @pp: Pointer to a string array
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - Adjusts the size of a memory block
 * @ptr: Pointer to the memory block to be adjusted
 * @old_size: Size of the block in bytes before adjustment
 * @new_size: Size of the new block in bytes
 *
 * Return: Pointer to the adjusted memory block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
