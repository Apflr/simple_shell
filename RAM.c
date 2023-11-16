#include "naomi.h"
/**
 * bfree - Frees POinter and \'0'\ the address
 * @ptr: Address of  ptr to be 
 * Return: SUCCESS.
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
