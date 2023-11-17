#include "naomi.h"
/**
 * print_alias - writes  alias str
 * @node: alias next
 *
 * Return: on 0 Success,otherwise 1
 */
int print_alias(list_t *node)
{
    char *q = NULL, *x = NULL;


    if (node)
    {
        q = _strchr(node->str, '=');
        for (x = node->str; x <= q; x++)
        _putchar(*x);
        _putchar('\'');
        _puts(q + 1);
        _puts("'\n");
        return (0);
    }
    return (1);
}


/**
 * _myalias - multplies alias builtn
 * @info: Struct having potential arg. To maintain
 *          const function prototype.
 *  Return: on 0 Success
 */
int _myalias(info_t *info)
{
    int g = 0;
    char *q = NULL;
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
    for (g = 1; info->argv[g]; g++)
    {
        q = _strchr(info->argv[g], '=');
        if (q)

        set_alias(info, info->argv[g]);
        else

            print_alias(node_starts_with(info->alias, info->argv[g], '='));
    }


    return (0);
}
