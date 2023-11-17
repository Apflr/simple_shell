#include "naomi.h"
/**
 * _myhistory - prints out  files list,in  one command by line, preceded
 * @info: Structure holding  arguments. Used for withholding
 *        constant funct prototype.
 *  Return: Always 0 Success
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - set$ friend to the string
 * @info: parameter structure
 * @str: alias string
 * Return: 0 Success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *p, d;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	d = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = d;
	return (ret);
}

/**
 * set_alias - sets alias to the strings
 * @info: parameter to structure
 * @str: strn freind
 * Return: 0 success, 1 on error
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
 * print_alias - prints an alias of the string 
 * @node: the node representing the alias
 * Return: 0 on success, 1 on error
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
 * _myalias - Emulates the functionality of the
 * built-in 'alias' command (see 'man alias')
 * @info: Structure holding possible arguments, 
 * ensuring a consistent function prototype
 *  Return: 0 on Success
 */
int _myalias(info_t *info)
{
	int r = 0;
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
	for (r = 1; info->argv[r]; r++)
	{
		p = _strchr(info->argv[r], '=');
		if (p)
			set_alias(info, info->argv[r]);
		else
			print_alias(node_starts_with(info->alias, info->argv[r], '='));
	}

	return (0);
}
