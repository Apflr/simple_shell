#include "naomi.h"
/**
 * **strtow - Duplicate str into words
 * @str:  input
 * @d: str Del
 * Return: Pointer on success to  array of strings, else NULL on failure
 */

char **strtow(char *str, char *d)
{
        int z, x, u, n, numwords = 0;
        char **s;

        if (str == NULL || str[0] == 0)
                return (NULL);
        if (!d)
                d = " ";
        for (z = 0; str[z] != '\0'; z++)
                if (!is_delim(str[z], d) && (is_delim(str[z + 1], d) || !str[z + 1]))
                        numwords++;

        if (numwords == 0)
                return (NULL);
        s = malloc((1 + numwords) * sizeof(char *));
        if (!s)
                return (NULL);
        for (z = 0, x = 0; x < numwords; x++)
        {
                while (is_delim(str[z], d))
                        z++;
                u = 0;
                while (!is_delim(str[z + u], d) && str[z + u])
                        u++;
                s[x] = malloc((u + 1) * sizeof(char));
                if (!s[x])
                {
                        for (u = 0; u < x; u++)
                                free(s[u]);
                        free(s);
                        return (NULL);
                }
                for (n = 0; n < u; n++)
                        s[x][n] = str[z++];
                s[x][n] = 0;
        }
        s[x] = NULL;
        return (s);
}

/**
 * **strtow2 - Duplicate str into words
 * @str:  Input
 * @d: Delim
 * Return: Pointer on success to  array of strings, else NULL on failure
 */
char **strtow2(char *str, char d)
{
        int b, j, u, n, numwords = 0;
        char **s;

        if (str == NULL || str[0] == 0)
                return (NULL);
        for (b = 0; str[b] != '\0'; b++)
                if ((str[b] != d && str[b + 1] == d) ||
                                    (str[b] != d && !str[b + 1]) || str[b + 1] == d)
                        numwords++;
        if (numwords == 0)
                return (NULL);
        s = malloc((1 + numwords) * sizeof(char *));
        if (!s)
                return (NULL);
        for (b = 0, j = 0; j < numwords; j++)
        {
                while (str[b] == d && str[b] != d)
                        b++;
                u = 0;
                while (str[b + u] != d && str[b + u] && str[b + u] != d)
                        u++;
                s[j] = malloc((u + 1) * sizeof(char));
                if (!s[j])
                {
                        for (u = 0; u < j; u++)
                                free(s[u]);
                        free(s);
                        return (NULL);
                }
                for (n = 0; n < u; n++)
                        s[j][n] = str[b++];
                s[j][n] = 0;
        }
        s[j] = NULL;
        return (s);
}
