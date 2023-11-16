#include "naomi.h"
/**
 * replace_string - substitutes the content of a string.
 * @old: The address of the old string to be replaced
 * @new: The new string that replaces the old one.
 * Return: Returns 1 if the replacement is
 * successful; otherwise, returns 0.
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
/**
 * replace_vars - substitutes variables based on the
 * information provided in the parameter structure.
 * @info:  A structure containing parameters for variable replacement.
 * Return: 1 if the substitution is successful; otherwise, returns 0.
 */
int replace_vars(info_t *info)
{
	int l = 0;
	list_t *node;

	for (l = 0; info->argv[l]; l++)
	{
		if (info->argv[l][0] != '$' || !info->argv[l][1])
			continue;

		if (!_strcmp(info->argv[l], "$?"))
		{
			replace_string(&(info->argv[l]),
					_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[l], "$$"))
		{
			replace_string(&(info->argv[l]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[l][1], '=');
		if (node)
		{
			replace_string(&(info->argv[l]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[l], _strdup(""));

	}
	return (0);
}
/**
 * check_chain - examines the entry point based on the parameters provided in the structure.
 * @info: A structure containing relevant parameters.
 * @buf:  A character buffer.
 * @p: The address of the current position.
 * @i: The starting position in the buffer.
 * @len:  The length of the buffer
 * Return: This function does not return a value (void)
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t f = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			f = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			f = len;
		}
	}

	*p = f;
}
/**
 * replace_alias -  substitutes aliases based on the information
 * provided in the parameter structure.
 * @info:   A structure containing parameters for alias replacement.
 * Return: Returns 1 if the replacement
 * is successful; otherwise, returns 0.
 */
int replace_alias(info_t *info)
{
	int z;
	list_t *node;
	char *p;

	for (z = 0; z < 10; z++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}
/**
 * is_chain - checks if the current character in the buffer serves as a delimiter for a chain
 * @info:  A structure containing relevant parameters.
 * @buf: A character buffer
 * @p: The address of the buffer.
 * Return: 1 if the test is successful; otherwise, returns 0.
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t r = *p;

	if (buf[r] == '|' && buf[r + 1] == '|')
	{
		buf[r] = 0;
		r++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[r] == '&' && buf[r + 1] == '&')
	{
		buf[r] = 0;
		r++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[r] == ';') /* Located the end of the command */
	{
		buf[r] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = r;
	return (1);
}
