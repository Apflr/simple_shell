#include "naomi.h"
/**
 * **strtow - divides string to words
 * @str: String entered
 * @d: String Delimiter
 * Return: Always succes
 */

char **strtow(char *str, char *d)
{
	int e, f, g, h, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (e = 0; str[e] != '\0'; e++)
		if (!is_delim(str[e], d) && (is_delim(str[e + 1], d) || !str[e + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (e = 0, f = 0; f < numwords; f++)
	{
		while (is_delim(str[e], d))
			e++;
		g = 0;
		while (!is_delim(str[e + g], d) && str[e + g])
			g++;
		s[f] = malloc((g + 1) * sizeof(char));
		if (!s[f])
		{
			for (g = 0; g < f; g++)
				free(s[g]);
			free(s);
			return (NULL);
		}
		for (h = 0; h < g; h++)
			s[f][h] = str[e++];
		s[f][g] = 0;
	}
	s[f] = NULL;
	return (s);
}

/**
 * **strtow2 - dividing cord into words
 * @str: String Inputting
 * @d: Delimeter
 *
 * Return: Always success
 */
char **strtow2(char *str, char d)
{
	int o, r, g, h, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (o = 0; str[o] != '\0'; o++)
		if ((str[o] != d && str[o + 1] == d) ||
				    (str[o] != d && !str[o + 1]) || str[o + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (o = 0, r = 0; r < numwords; r++)
	{
		while (str[o] == d && str[o] != d)
			o++;
		g = 0;
		while (str[o + g] != d && str[o + g] && str[o + g] != d)
			g++;
		s[r] = malloc((g + 1) * sizeof(char));
		if (!s[r])
		{
			for (g = 0; g < r; g++)
				free(s[g]);
			free(s);
			return (NULL);
		}
		for (h = 0; h < g; h++)
			s[r][h] = str[o++];
		s[r][h] = 0;
	}
	s[r] = NULL;
	return (s);
}

