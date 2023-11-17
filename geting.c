#include "naomi.h"
/**
 * get_environ - Provide a duplicate string array of our environment
 * @info: Structure potentially holding 
 * arguments for consistent function prototype
 * Return: Always 0 Success
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
 * _unsetenv -  environ var
 * @info: Structure containing potential arguments.
 *  Return: return 1 on delete, 0 otherwise
 * @var: string env var property
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t y = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), y);
			y = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		y++;
	}
	return (info->env_changed);
}

/**
 * _setenv - Create or update an environment variable
 * @info: Structure holding possible arguments
 * for consistent function prototype
 * @var:  String representing the value of the environment variable
 * @value:  String representing the environment variable property
 *  Return: Always 0 Success
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
