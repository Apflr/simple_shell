#include "naomi.h"
/**
 * find_path - Searches for 'cmd' within the 'pathstr' string of paths
 * @info: Informational structure
 * @pathstr: String holding  paths
 * @cmd: Command tobe  locate
 *
 * Return: Path of 'cmd' if found, otherwise NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int u = 0, curr_pos = 0;
	char *byte;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[u] || pathstr[u] == ':')
		{
			byte = dup_chars(pathstr, curr_pos, u);
			if (!*byte)
				_strcat(byte, cmd);
			else
			{
				_strcat(byte, "/");
				_strcat(byte, cmd);
			}
			if (is_cmd(info, byte))
				return (byte);
			if (!pathstr[u])
				break;
			curr_pos = u;
		}
		u++;
	}
	return (NULL);
}
/**
 * is_cmd - Verifies if a file functions as an executable command.
 * @info: Structural data used for providing information.
 * @path: File's location or directory.
 * Return: Returns 1 if successful; otherwise, returns 0.
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
 * dup_chars - photocopies Characters
 * @pathstr: Strings towards path
 * @start: where index starts
 * @stop: where index ends
 * Return: buffer to a new pointer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int c = 0, e = 0;

	for (e = 0, c = start; e < stop; c++)
		if (pathstr[c] != ':')
			buf[e++] = pathstr[c];
	buf[e] = 0;
	return (buf);
}

