#include "naomi.h"
/**
 * free_info -  Frees the fields of the info_t struct.
 *
 * @info: Struct to be freed
 * @all: If true, free all fields.
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
/**
 * set_info - Initializes the fields of the info_t struct.
 * @info: Pointer to the struct to be initialized
 * @av: Argument vector used for initialization
 */
void set_info(info_t *info, char **av)
{
	int g = 0;

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
		for (g = 0; info->argv && info->argv[g]; g++)
			;
		info->argc = g;

		replace_alias(info);
		replace_vars(info);
	}
}
/**
 * clear_info - Release resources associated with the info_t struct.
 * @info: Pointer to the struct undergoing resource release.
 */
void clear_info(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}
