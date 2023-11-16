#include "naomi.h"
#include <stdlib.h>
/**
 * _realloc -  Modifies the size of a memory block
 * @ptr: Pointer to the previous memory block
 * @old_size: Size of the current block in bytes
 * @new_size: Size of the new block in bytes
 * Return: ptr to block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *v;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	v = malloc(new_size);
	if (!v)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		v[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (v);
}
/**
 * _memset - Sets a constant byte value in a block of memory.
 * @s: Pointer to the memory area
 * @b: Byte to fill the memory area with.
 * @n: Number of bytes to fill.
 * Return: A pointer to the memory area.
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int h;

	for (h = 0; h < n; h++)
		s[h] = b;
	return (s);
}
/**
 * ffree - Deallocates memory for a string of strings
 * @pp:  Pointer to the string of strings.
 */
void ffree(char **pp)
{
	char **x = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(x);
}

