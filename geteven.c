#include "naomi.h"
/**
 * get_environ - provides a duplicate of our
 * environment in the form of a string array.
 * @info:  A structure with potential arguments,
 * ensuring a consistent function prototype.
 * Return: Always returns 0 in case of success.
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}
/**
 * _setenv - initializes a new environment
 * variable or modifies an existing one.
 * @info: A structure with potential arguments,
 * ensuring a consistent function prototype.
 * @var: The string denoting the property of the environment variable
 * @value: The string denoting the value of the environment variable.
 *  Return: Always returns 0 in case of success.
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *bufe = NULL;
	list_t *node;
	char *y;

	if (!var || !value)
		return (0);

	bufe = malloc(_strlen(var) + _strlen(value) + 2);
	if (!bufe)
		return (1);
	_strcpy(bufe, var);
	_strcat(bufe, "=");
	_strcat(bufe, value);
	node = info->env;
	while (node)
	{
		y = starts_with(node->str, var);
		if (y && *y == '=')
		{
			free(node->str);
			node->str = bufe;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), bufe, 0);
	free(bufe);
	info->env_changed = 1;
	return (0);
}
/**
 * _unsetenv - function removes an environment variable.
 * @info: A structure with potential arguments,
 * ensuring a consistent function prototype.
 *  @var: The string denoting the property of the environment variable.
 * Return: Returns 1 upon successful deletion, and 0 otherwise.
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t e = 0;
	char *z;

	if (!node || !var)
		return (0);

	while (node)
	{
		z = starts_with(node->str, var);
		if (z && *z == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), e);
			e = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		e++;
	}
	return (info->env_changed);
}
