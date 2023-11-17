#include "file.h"
/**
 * bfree - Releases memory held by a pointer
 * and sets the address to NULL
 * @ptr: Address of the pointer to be freed
 *
 * Return:  Returns 1 on successful memory 
 * release; otherwise, returns 0.
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
