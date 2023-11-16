#include "naomi.h"
/**
 * renumber_history - Updates numbering in the linked list of history
 * @info: Structure that holds the necessary or pertinent arguments.
 * Return: The updated count of history entries
 */

int renumber_history(info_t *info)
{
	list_t *node = info->history;
	int egg = 0;

	while (node)
	{
		node->num = egg++;
		node = node->next;
	}
	return (info->histcount = egg);
}
/**
 * build_history_list -  Appends an entry to the history linked list
 * @info: Structure containing possible arguments.
 * Utilized for maintenance.
 * @buf: Buffer used in the process
 * @linecount: The present number of lines in the history.
 * Return:  is always success
 */

int build_history_list(info_t *info, char *buf, int linecount)
{
	list_t *node = NULL;

	if (info->history)
		node = info->history;
	add_node_end(&node, buf, linecount);

	if (!info->history)
		info->history = node;
	return (0);
}
/**
 * get_history_file - function gets file history
 * @info: contains parameter structure
 * Return: a given string
 */

char *get_history_file(info_t *info)
{
	char *buf, *dir;

	dir = _getenv(info, "HOME=");
	if (!dir)
		return (NULL);
	buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	_strcpy(buf, dir);
	_strcat(buf, "/");
	_strcat(buf, HIST_FILE);
	return (buf);
}
/**
 * write_history -  Attaches to an existing file
 * @info: contains parameter structure
 * Return:success 1, if not  -1
 */

int write_history(info_t *info)
{
	ssize_t ty;
	char *filename = get_history_file(info);
	list_t *node = NULL;

	if (!filename)
		return (-1);

	ty = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (ty == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		_putsfd(node->str, ty);
		_putfd('\n', ty);
	}
	_putfd(BUF_FLUSH, ty);
	close(ty);
	return (1);
}
/**
 * read_history - scans the history files
 * @info: hold parameter structure
 * Return: success on history count, or  else 0
 */

int read_history(info_t *info)
{
	int x, last = 0, linecount = 0;
	ssize_t dj, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = get_history_file(info);

	if (!filename)
		return (0);

	dj = open(filename, O_RDONLY);
	free(filename);
	if (dj == -1)
		return (0);
	if (!fstat(dj, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(dj, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(dj);
	for (x = 0; x < fsize; x++)
		if (buf[x] == '\n')
		{
			buf[x] = 0;
			build_history_list(info, buf + last, linecount++);
			last = x + 1;
		}
	if (last != x)
		build_history_list(info, buf + last, linecount++);
	free(buf);
	info->histcount = linecount;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	renumber_history(info);
	return (info->histcount);
}
