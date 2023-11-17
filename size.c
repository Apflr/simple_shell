#include "naomi.h"
/**
 * bfree - reales pointer and NULLs the memory address
 * @ptr: freed file
 *
 * Return: Success 1,otherwise 0.
 */
int bfree(void **ptr)
{
        if (ptr && *ptr)
        {
                free(*ptr);
                *ptr = NULL;
                return (1);
        }
        return (0);
}
