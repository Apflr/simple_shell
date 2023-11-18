#include "file.h"
/**
 * **strtow - deplicate and duplicates string into words
 * @str: Str
 * @d: Str Del
 * Return: Ptr  vector of str on success, else NULL on failure
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
 * **strtow2 -  duplicates str into words
 * @str: Input
 * @d: delim
 * Return: on success Ptr to  array of strings, else NULL on failure
 */
char **strtow2(char *str, char d)
{
	int m, j, u, n, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (m = 0; str[m] != '\0'; m++)
		if ((str[m] != d && str[m + 1] == d) ||
				    (str[m] != d && !str[m + 1]) || str[m + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (m = 0, j = 0; j < numwords; j++)
	{
		while (str[m] == d && str[m] != d)
			m++;
		u = 0;
		while (str[m + u] != d && str[m + u] && str[m + u] != d)
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
			s[j][n] = str[m++];
		s[j][n] = 0;
	}
	s[j] = NULL;
	return (s);
}

