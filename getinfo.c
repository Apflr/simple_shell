#include "naomi.h"
/**
 * clear_info - Set up the info_t structure.
 * @info: struct of  address.
 */
void clear_info(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}

/**
 * set_info - Configure an info_t structure.
 * @info: Address of the structure.
 * @av: Array containing command-line arguments.
 */
void set_info(info_t *info, char **av)
{
	int r = 0;

	info->fname = av[0];
	if (info->arg)
	{
		info->argv = strtow(info->arg, " \t");
		if (!info->argv)
		{
			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (r = 0; info->argv && info->argv[r]; r++)
			;
		info->argc = r;

		replace_alias(info);
		replace_vars(info);
	}
}

/**
 * free_info -  Release memory in an info_t structure field.
 * @info: Address of the structure.
 * @all: True if freeing all fields is needed.
 */
void free_info(info_t *info, int all)
{
	ffree(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (all)
	{
		if (!info->cmd_buf)
			free(info->arg);
		if (info->env)
			free_list(&(info->env));
		if (info->history)
			free_list(&(info->history));
		if (info->alias)
			free_list(&(info->alias));
		ffree(info->environ);
			info->environ = NULL;
		bfree((void **)info->cmd_buf);
		if (info->readfd > 2)
			close(info->readfd);
		_putchar(BUF_FLUSH);
	}
}
