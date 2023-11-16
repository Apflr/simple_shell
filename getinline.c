#include "naomi.h"
/**
 * input_buf - Processes a chained command buffer
 * @info: Parent structure
 * @buf:   Address of the buffer
 * @len:  Length of the buffer
 *
 * Return: the number of bytes read
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t v = 0;
	size_t fun_b = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		v = getline(buf, &fun_b, stdin);
#else
		v = _getline(info, buf, &fun_b);
#endif
		if (v > 0)
		{
			if ((*buf)[v - 1] == '\n')
			{
				(*buf)[v - 1] = '\0';
				v--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			{
				*len = v;
				info->cmd_buf = buf;
			}
		}
	}
	return (v);
}
/**
 * sigintHandler -  Handles the blocking of the Ctrl-C signal
 * @sig_num: The signal number received
 * Return: nothing
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
/**
 * _getline - Retrieves the next line of input from the standard input (STDIN)
 * @info:  Parental  structure
 * @ptr: Address of a buffer pointer, which can be preallocated or NULL
 * @length: Specifies the size of the allocated buffer
 * pointed to by 'ptr', if 'ptr' is not NULL.
 * Return: s (the retrieved line)
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t h, len;
	size_t g;
	ssize_t o = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		s = *length;
	if (h == len)
		h = len = 0;

	o = read_buf(info, buf, &len);
	if (o == -1 || (o == 0 && len == 0))
		return (-1);

	c = _strchr(buf + h, '\n');
	g = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, s, s ? s + g : g + 1);
	if (!new_p) /* MALLOC FAILURE! */
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(new_p, buf + h, g - h);
	else
		_strncpy(new_p, buf + h, g - h + 1);

	s += g - h;
	h = g;
	p = new_p;

	if (length)
		*length = s;
	*ptr = p;
	return (s);
}

