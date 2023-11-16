#include "naomi.h"
/**
 * interactive - checks if the shell is operating in interactive mode.
 * @info: A structure holding relevant information.
 * Return: Returns 1 if the shell is in interactive mode, and 0 otherwise.
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks whether a given character is a delimiter.
 * @c: The character to be checked.
 * @delim: the delimeter string
 * Return: Returns 1 if the character is a delimiter, and 0 if it is not.
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - checks whether a given character is an alphabetic character.
 * @c: The character to be examined.
 * Return: Returns 1 if the character is alphabetic, and 0 otherwise.
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
/**
 * _atoi - converts a string to an integer.
 * @x: The string to be converted
 * Return: 0 if there are no numbers in the string;
 * otherwise, it returns the converted integer.
 */

int _atoi(char *x)
{
	int b, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (b = 0; x[b] != '\0' && flag != 2; b++)
	{
		if (x[b] == '-')
			sign *= -1;

		if (x[b] >= '0' && x[b] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (x[b] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

