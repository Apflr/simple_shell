#include "naomi.h"
/**
 * fork_cmd - Forking  executed thread to run cmd
 * @info:  para and  return details to  struct
 * Return: nothing
 */

void fork_cmd(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		/* TODO: ERR FUNCTION */
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		/* TODO:  ERRO  FUNCTION */
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				print_error(info, "Permission denied\n");
		}
	}
}
/**
 * find_builtin - tracks  builtin commands
 * @info: par and return info struct
 * Return: -1 if builtin not found,
 * 0  if successful, when builtin located
 * 1 if unsuccesful ,where builtin fails
 * 2 returns on  exit.
 */
int find_builtin(info_t *info)
{
	int b, built_in_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (b = 0; builtintbl[b].type; b++)
		if (_strcmp(info->argv[0], builtintbl[b].type) == 0)
		{
			info->line_count++;
			built_in_ret = builtintbl[b].func(info);
			break;
		}
	return (built_in_ret);
}
/**
 * hsh - execution of  shell loop
 * @info: Parameters and returns details to struct
 * @av: Arg vect
 *
 * Return: success
 */
int hsh(info_t *info, char **av)
{
	ssize_t m = 0;
	int builtin_ret = 0;

	while (m != -1 && builtin_ret != -2)
	{
		clear_info(info);
		if (interactive(info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		m = get_input(info);
		if (m != -1)
		{
			set_info(info, av);
			builtin_ret = find_builtin(info);
			if (builtin_ret == -1)
				find_cmd(info);
		}
		else if (interactive(info))
			_putchar('\n');
		free_info(info, 0);
	}
	write_history(info);
	free_info(info, 1);
	if (!interactive(info) && info->status)
		exit(info->status);
	if (builtin_ret == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtin_ret);
}
/**
 * find_cmd - monitors commands in PATH
 * @info: parameters and returns info struct
 * Return: null
 */

void find_cmd(info_t *info)
{
	char *path = NULL;
	int b, d;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (b = 0, d = 0; info->arg[b]; b++)
		if (!is_delim(info->arg[b], " \t\n"))
			d++;
	if (!d)
		return;

	path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		fork_cmd(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=")
					|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
			fork_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "not found\n");
		}
	}
}
