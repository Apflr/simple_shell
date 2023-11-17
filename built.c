#include "naomi.h"
/**
 * _myhistory - Show the history list with each command on a separate line,
 * prefaced by line numbers starting from 0.
 * @info: Structure possibly holding arguments 
 * to ensure a consistent function prototype.
 *  Return: Always 0 for success
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - Removes an alias associated with the provided string
 * @info: Parameter structure
 * @str: String representing the alias to remove
 * Return: Returns 0 upon success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - Sets an alias given string
 * @info: Parameter structure
 * @str: String represt an alias
 *
 * Return: Always 0, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - Prints an alias from node
 * @node: Aliasnodde
 *
 * Return: Always 0 success, 1 on error
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - imitates the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *        a const func prot.
 *  Return: Always 0 for succe
 */
int _myalias(info_t *info)
{
	int h = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (h = 1; info->argv[h]; h++)
	{
		p = _strchr(info->argv[h], '=');
		if (p)
			set_alias(info, info->argv[h]);
		else
			print_alias(node_starts_with(info->alias, info->argv[h], '='));
	}

	return (0);
}
