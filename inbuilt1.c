#include "naomi.h"
/**
 * _myalias - copies alias builtin man alias
 * @info: Structure containing arguments.can be used to maintain
 *          const funct prototype.
 *  Return: Always Success
 */
int _myalias(info_t *info)
{
	int v = 0;
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
	for (v = 1; info->argv[v]; v++)
	{
		p = _strchr(info->argv[v], '=');
		if (p)
			set_alias(info, info->argv[v]);
		else
			print_alias(node_starts_with(info->alias, info->argv[v], '='));
	}

	return (0);
}
/**
 * _myhistory - shows  histo list, line by line, proceded
 *              by line numbers, starting at 0.
 * @info: Structure containing arguments used to maintain
 *        const funct prototype.
 *  Return: end of program
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}
/**
 * unset_alias - puts alias to the string
 * @info: parameter to structures
 * @str: strin alias
 *
 * Return: Always success
 */
int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int vet;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	vet = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (vet);
}
/**
 * set_alias - puts alias to the string
 * @info: parameter for structu
 * @str: alias variable that stores a string.
 * Return: Always 0 succes, 1 if fail
 */
int set_alias(info_t *info, char *str)
{
	char *b;

	b = _strchr(str, '=');
	if (!b)
		return (1);
	if (!*++b)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}
/**
 * print_alias - outputs an nickname to string
 * @node: nickname node
 * Return: Always 0  or  1 
 */
int print_alias(list_t *node)
{
	char *t = NULL, *u = NULL;

	if (node)
	{
		t = _strchr(node->str, '=');
		for (u = node->str; u <= t; u++)
		_putchar(*u);
		_putchar('\'');
		_puts(t + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}
