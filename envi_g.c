#include "file.h"

/**
 * get_environ -takes back string vector copy of our environ.
 * @info: Structure having  potential arguments. Used for maintaining
 *          constant function prototype.
 * Return: Always 0 Success.
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
 * _unsetenv - Remove an env var.
 * @info: Structure having potential arg. Used for maintaining
 *        constant function prototype.
 * Return: Return 1 on delete, 0 otherwise.
 * @var: String environment variable property.
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t m = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), m);
			m = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		m++;
	}
	return (info->env_changed);
}

/**
 * _setenv - init a new env var or modify an existing one.
 * @info: Structure having potential arguments. Used for maintaining
 *        constant function prototype.
 * @var: Str env variable property.
 * @value: Str env variable value.
 * Return: Always 0 Success.
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}
