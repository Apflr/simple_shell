#include "naomi.h"
/**
 * is_chain - checks if recent char in buf is a chain delimeter
 * @info:  Param Strt
 * @buf: Buff
 * @p: buf address
 
 * Return: on Success 1, else 0 
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
        size_t y = *p;

        if (buf[y] == '|' && buf[y + 1] == '|')
        {
                buf[y] = 0;
                y++;
                info->cmd_buf_type = CMD_OR;
        }
        else if (buf[y] == '&' && buf[y + 1] == '&')
        {
                buf[y] = 0;
                y++;
                info->cmd_buf_type = CMD_AND;
        }
        else if (buf[y] == ';') /* found end  command */
        {
                buf[y] = 0;
                info->cmd_buf_type = CMD_CHAIN;
        }
        else
                return (0);
        *p = y;
        return (1);
}

/**
 * check_chain - bolds entry point
 * @info: Param Struct
 * @buf: Char buff
 * @p: recent position
 * @i: begin position in buf
 * @len: Buffer distance
 *
 * Return: void
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
        size_t y = *p;

        if (info->cmd_buf_type == CMD_AND)
        {
                if (info->status)
                {
                        buf[i] = 0;
                        y = len;
                }
        }
        if (info->cmd_buf_type == CMD_OR)
        {
                if (!info->status)
                {
                        buf[i] = 0;
                        y = len;
                }
        }

        *p = y;
}

/**
 * replace_alias -fix an aliases
 * @info:  Param Strt
 *
 * Return: on success 1, otherwise 0
 */
int replace_alias(info_t *info)
{
        int z;
        list_t *node;
        char *p;

        for (z = 0; z < 10; z++)
        {
                node = node_starts_with(info->alias, info->argv[0], '=');
                if (!node)
                        return (0);
                free(info->argv[0]);
                p = _strchr(node->str, '=');
                if (!p)
                        return (0);
                p = _strdup(p + 1);
                if (!p)
                        return (0);
                info->argv[0] = p;
        }
        return (1);
}

/**
 * replace_vars - fix vars
 * @info: Param Strt
 *
 * Return: on succcess1, otherwise 0
 */
int replace_vars(info_t *info)
{
        int z = 0;
        list_t *node;

        for (z = 0; info->argv[z]; z++)
        {
                if (info->argv[z][0] != '$' || !info->argv[z][1])
                        continue;

                if (!_strcmp(info->argv[z], "$?"))
                {
                        replace_string(&(info->argv[z]),
                                        _strdup(convert_number(info->status, 10, 0)));
                        continue;
                }
                if (!_strcmp(info->argv[z], "$$"))
                {
                        replace_string(&(info->argv[z]),
                                        _strdup(convert_number(getpid(), 10, 0)));
                        continue;
                }
                node = node_starts_with(info->env, &info->argv[z][1], '=');
                if (node)
                {
                        replace_string(&(info->argv[z]),
                                        _strdup(_strchr(node->str, '=') + 1));
                        continue;
                }
                replace_string(&info->argv[z], _strdup(""));

        }
        return (0);
}

/**
 * replace_string - fixes String
 * @old: adress of an old string
 * @new: brand String
 *
 * Return:on success 1, else 0
 */
int replace_string(char **old, char *new)
{
        free(*old);
        *old = new;
        return (1);
}

