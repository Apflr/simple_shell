#include "naomi.h"
/**
 * _strcpy - takes String
 * @dest:des point
 * @src: source file
 *
 * Return: on success Destination Ptr
 */
char *_strcpy(char *dest, char *src)
{
        int z = 0;

        if (dest == src || src == 0)
                return (dest);
        while (src[z])
        {
                dest[z] = src[z];
                z++;
        }
        dest[z] = 0;
        return (dest);
}

/**
 * _strdup - fixes String
 * @str:  matches
 *
 * Return: on success Duplicated string ptr
 */
char *_strdup(const char *str)
{
        int length = 0;
        char *ret;

        if (str == NULL)
                return (NULL);
        while (*str++)
                length++;
        ret = malloc(sizeof(char) * (length + 1));
        if (!ret)
                return (NULL);
        for (length++; length--;)
                ret[length] = *--str;
        return (ret);
}

/**
 * _puts - writes input string
 * @str: writes tring
 *
 * Return: Null
 */
void _puts(char *str)
{
        int z = 0;

        if (!str)
                return;
        while (str[z] != '\0')
        {
                _putchar(str[z]);
                z++;
        }
}

/**
 * _putchar - puts  char c to stdout
 * @c:  char 
 *
 * Return: on success 1 , otherwise
 * -1 on error is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
        static int z;
        static char buf[WRITE_BUF_SIZE];

        if (c == BUF_FLUSH || z >= WRITE_BUF_SIZE)
        {
                write(1, buf, z);
                z = 0;
        }
        if (c != BUF_FLUSH)
                buf[z++] = c;
        return (1);
}
