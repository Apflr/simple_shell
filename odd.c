#include "naomi.h"
/**
 * interactive - takes back true if the shell is in the interactive mode
 * @info: struct address
 *
 * Return: 1 if in the interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
        return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - inspects if the char is delim
 * @c: char to be inspected
 * @delim: delim string
 * Return: 1 if it is true, and 0 if false
 */
int is_delim(char c, char *delim)
{
        while (*delim)
                if (*delim++ == c)
                        return (1);
        return (0);
}

/**
 * _isalpha - inspects for alphabetic characters
 * @c: char to  be input
 * Return: 1 if c is alphabetic, and 0 otherwise
 */

int _isalpha(int c)
{
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
                return (1);
        else
                return (0);
}

/**
 * _atoi - changes  string to int
 * @x: string to be changed
 * Return: 0 if no numbers in the string, otherwise convert no.
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


