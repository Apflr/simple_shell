#include "naomi.h"
/**
 * _myenv - Display the current environment variables
 * @info: tructure holding possible arguments,
 * ensuring a consistent function prototype
 * Return: 0 on Success
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}
/**
 * _getenv - Retrieve the value of an environment variable
 * @info: Structure holding possible arguments
 * @name: Name of the environment variable
 * Return: The value of the specified environment variable
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
 * _mysetenv - Create a new environment 
 * variable or update an existing one
 * @info:  Structure holding possible arguments,
 * ensuring a consistent function prototype
 * Return: 0 on Success
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
 * _myunsetenv - Eliminate an environment variable
 * @info: Structure encompassing possible arguments, 
 * ensuring consistent function prototype
 * Return: Always 0 Success
 */
int _myunsetenv(info_t *info)
{
	int e;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (e = 1; e <= info->argc; e++)
		_unsetenv(info, info->argv[e]);

	return (0);
}

/**
 * populate_env_list - Generate a linked list of environment variables
 * @info: Structure holding possible arguments for 
 * maintaining a consistent function prototype
 * Return: 0 on Successful population
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t e;

	for (e = 0; environ[e]; e++)
		add_node_end(&node, environ[e], 0);
	info->env = node;
	return (0);
}
