#include "naomi.h"
/**
 * is_cmd - finds if file is  executable command
 * @info: idea Struct
 * @path:  Path of a file
 *
 * Return: On success 1,otherwise 0
 */
int is_cmd(info_t *info, char *path)
{
        struct stat st;

        (void)info;
        if (!path || stat(path, &st))
                return (0);

        if (st.st_mode & S_IFREG)
        {
                return (1);
        }
        return (0);
}

/**
 * dup_chars - multiplies Char
 * @pathstr: path
 * @start: begin Index
 * @stop: end Index
 *
 * Return: Buff new ptr
 */
char *dup_chars(char *pathstr, int start, int stop)
{
        static char buf[1024];
        int z = 0, u = 0;

        for (u = 0, z = start; z < stop; z++)
                if (pathstr[z] != ':')
                        buf[u++] = pathstr[z];
        buf[u] = 0;
        return (buf);
}

/**
 * find_path -  cmd in  str path
 * @info: Struct
 * @pathstr: str Path
 * @cmd: cmd find
 *
 * Return: on success cmd path if found or NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
        int z = 0, curr_pos = 0;
        char *path;

        if (!pathstr)
                return (NULL);
        if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
        {
                if (is_cmd(info, cmd))
                        return (cmd);
        }
        while (1)
        {
                if (!pathstr[z] || pathstr[z] == ':')
                {
                        path = dup_chars(pathstr, curr_pos, z);
                        if (!*path)
                                _strcat(path, cmd);
                        else
                        {
                                _strcat(path, "/");
                                _strcat(path, cmd);
                        }
                        if (is_cmd(info, path))
                                return (path);
                        if (!pathstr[z])
                                break;
                        curr_pos = z;
                }
                z++;
        }
        return (NULL);
}


