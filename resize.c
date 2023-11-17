#include "naomi.h"
/**
 * _memset - adds mem with  constant byte
 * @s:  memory area
 * @b: Byte  fill *s with
 * @n:  bytes
 * Return: on success Ptr to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
        unsigned int z;

        for (z = 0; z < n; z++)
                s[z] = b;
        return (s);
}

/**
 * ffree -releases  string of strings
 * @pp: String of Str
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
 * _realloc - resizes  block of mem
 * @ptr: ptr to adjacent block
 * @old_size: Byte
 * @new_size: Byte for new block
 *
 * Return: on success ptr to block
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


