#include "file.h"

/**
 * input_buf - Buff chain command.
 * @info: Param strt.
 * @buf: Buff address.
 * @len: Buff length.
 *
 * Return: Bytes read.
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
    ssize_t z = 0;
    size_t len_p = 0;

    if (!*len) /* If nothing left in the buffer, fill it */
    {
        /*bfree((void **)info->cmd_buf);*/
        free(*buf);
        *buf = NULL;
        signal(SIGINT, sigintHandler);

        z = getline(buf, &len_p, stdin);

        z = _getline(info, buf, &len_p);

        if (z > 0)
        {
            if ((*buf)[z - 1] == '\n')
            {
                (*buf)[z - 1] = '\0'; /* Remove trailing newline */
                z--;
            }
            info->linecount_flag = 1;
            remove_comments(*buf);
            build_history_list(info, *buf, info->histcount++);
            /* if (_strchr(*buf, ';')) is this a command chain? */
            {
                *len = z;
                info->cmd_buf = buf;
            }
        }
    }
    return (z);
}

/**
 * get_input - obtain line minus newline.
 * @info: Param structure.
 *
 * Return: Bytes read.
 */
ssize_t get_input(info_t *info)
{
    static char *buf; /* The ';' command chain buffer */
    static size_t i, j, len;
    ssize_t z = 0;
    char **buf_p = &(info->arg), *p;

    _putchar(BUF_FLUSH);
    z = input_buf(info, &buf, &len);
    if (z == -1) /* EOF */
        return (-1);
    if (len) /* We have commands left in the chain buffer */
    {
        j = i; /* Init a new iterator to the current buffer position */
        p = buf + i; /* Get a pointer for return */

        check_chain(info, buf, &j, i, len);
        while (j < len) /* Iterate to semicolon or end */
        {
            if (is_chain(info, buf, &j))
                break;
            j++;
        }

        i = j + 1; /* Increment past the nulled ';'' */
        if (i >= len) /* Reached the end of the buffer? */
        {
            i = len = 0; /* Reset position and length */
            info->cmd_buf_type = CMD_NORM;
        }

        *buf_p = p; /* Pass back a pointer to the current command position */
        return (_strlen(p)); /* Return the length of the current command */
    }

    *buf_p = buf; /* Else not a chain, pass back the buffer from _getline() */
    return (z); /* Return the length of the buffer from _getline() */
}

/**
 * read_buf - Read a buffer.
 * @info: Parameter structure.
 * @buf: Buffer.
 * @i: Size.
 *
 * Return: r
 */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
    ssize_t z = 0;

    if (*i)
        return (0);
    z = read(info->readfd, buf, READ_BUF_SIZE);
    if (z >= 0)
        *i = z;
    return (z);
}

/**
 * _getline - obtain  next line of input from STDIN.
 * @info: Param structure.
 * @ptr: Pointer address to a buffer, preallocated or NULL.
 * @length: Size of preallocated ptr buffer if not NULL.
 *
 * Return: s
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
    static char buf[READ_BUF_SIZE];
    static size_t i, len;
    size_t k;
    ssize_t z = 0, s = 0;
    char *p = NULL, *new_p = NULL, *c;

    p = *ptr;
    if (p && length)
        s = *length;
    if (i == len)
        i = len = 0;

    z = read_buf(info, buf, &len);
    if (z == -1 || (z == 0 && len == 0))
        return (-1);

    c = _strchr(buf + i, '\n');
    k = c ? 1 + (unsigned int)(c - buf) : len;
    new_p = _realloc(p, s, s ? s + k : k + 1);
    if (!new_p) /* MALLOC FAILURE! */
        return (p ? free(p), -1 : -1);

    if (s)
        _strncat(new_p, buf + i, k - i);
    else
        _strncpy(new_p, buf + i, k - i + 1);

    s += k - i;
    i = k;
    p = new_p;

    if (length)
        *length = s;
    *ptr = p;
    return (s);
}

/**
 * sigintHandler - blck ctrl-C.
 * @sig_num: alarm num.
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
    _puts("\n");
    _puts("$ ");
    _putchar(BUF_FLUSH);
}
