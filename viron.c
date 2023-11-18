#include "file.h"

/**
 * _myenv -writes recent environment.
 * @info: Structure having potential arguments. Used for maintaining
 *          constant func prototype.
 * Return: Always 0 Success.
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - obtain  value of an environment variable.
 * @info: Structure having potential arguments.
 * @name: Environment variable name.
 *
 * Return:  value of environment variable.
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initialize a new environ  var or modify an existing one.
 * @info: Structure containing potential arg. Used to maintain
 *        a constant function prototype.
 *  Return: Always 0 Success.
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguments.\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove an envir var.
 * @info: Structure having potential arguments. Used for maintaining
 *        a constant function prototype.
 * Return: Always 0 Success.
 */
int _myunsetenv(info_t *info)
{
	int m;

	if (info->argc == 1)
	{
		_eputs("Too few arguments.\n");
		return (1);
	}
	for (m = 1; m <= info->argc; m++)
		_unsetenv(info, info->argv[m]);

	return (0);
}

/**
 * populate_env_list - Populate  env linked list.
 * @info: Structure having potential arguments. Used for maintaining
 *          a constant function prototype.
 * Return: Always 0 Success.
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t m;

	for (m = 0; environ[m]; m++)
		add_node_end(&node, environ[m], 0);
	info->env = node;
	return (0);
}
