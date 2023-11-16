#include "naomi.h"
/**
 * populate_env_list - populates a linked list with environment variables.
 * @info: A structure containing potential arguments,
 * Utilized to preserve a consistent function prototype.
 * Return: Always returns 0 upon success.
 */

int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t u;

	for (u = 0; environ[u]; u++)
		add_node_end(&node, environ[u], 0);
	info->env = node;
	return (0);
}
/**
 * _myunsetenv - removes an environment variable easily
 * @info: A structure holding possible arguments,
 * utilized to keep a consistent function prototype.
 * Return: Always returns 0 upon success.
 */

int _myunsetenv(info_t *info)
{
	int b;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (b = 1; b <= info->argc; b++)
		_unsetenv(info, info->argv[b]);

	return (0);
}
/**
 * _getenv - retrieves the value of an environment variable.
 * @info: A structure holding possible arguments.
 * @name: The name of the environment variable.
 *
 * Return:  Returns the value of the specified environment variable.
 */

char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *q;

	while (node)
	{
		q = starts_with(node->str, name);
		if (q && *q)
			return (q);
		node = node->next;
	}
	return (NULL);
}
/**
 * _mysetenv - starts a new environment variable or modifies an existing one.
 *
 * @info: A structure holding possible arguments,
 * used to ensure a consistent function prototype
 *  Return: Returns 0 in case of success.
 */

int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}
/**
 * _myenv - outputs the current environment.
 * @info: A structure with potential arguments,
 * ensuring a consistent function prototype.
 * Return:  Always returns 0 in the case of success
 */

int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}
