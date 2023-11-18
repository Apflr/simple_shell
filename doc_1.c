#include "file.h"
/**
 * interactive - takes back true if shell is i interactive mode
 * @info: address
 *
 * Return: on success 1, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - c ifchar is delimeter
 * @c: char be check
 * @delim: the delim  string
 * Return: on success, and 0 if false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - alphabetic char
 * @c: chr to  be input
 * Return: 1 on success, and 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - trasform str to int
 * @x: str to transform
 * Return: 0 if no  in string, otherwise convert num
 */

int _atoi(char *x)
{
	int z, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (z = 0; x[z] != '\0' && flag != 2; z++)
	{
		if (x[z] == '-')
			sign *= -1;

		if (x[z] >= '0' && x[z] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (x[z] - '0');
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


