#ifndef NAOMI_H
#define NAOMI_H

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <limits.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

/* command chains */
#define CMD_OR          1
#define CMD_NORM        0
#define CMD_CHAIN       3
#define CMD_AND         2


/*for write/read buffer*/
#define BUF_FLUSH -1
#define WRITE_BUF_SIZE 1024
#define READ_BUF_SIZE 1024

/* converting_number() */
#define CONVERT_LOWERCASE       1
#define CONVERT_UNSIGNED        2

/* its for using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE       ".simple_shell_history"
#define HIST_MAX        4096

extern char **environ;


/**
 * struct liststr - function to singly linked list
 * @num: is field number
 * @str: a string tested
 * @next: points onto the adjacent node
 */
typedef struct liststr
{
        int num;
        char *str;
        struct liststr *next;
} list_t;

/**
 * struct passinfo - holds arguments pass to a function
 * @argv:array of strings gotten from @arg
 * @path:  string path for the active command
 * @arg: its generated from getline holding arguments
 * @argc: contains argument count
 * @err_num: contains the error code for exit()s
 * @line_count: contains error count
 * @fname: program name
 * @env: linked list local copy of environment
 * @linecount_flag: flags on count line of input
 * @environ: custom modified copy of environment
 * @alias: alias node
 * @env_changed: only if environ was changed      
 * @status: returns status of the last expected command
 * @cmd_buf_type: CMD_type ||, &&,
 * @readfd: the fd from which line input is to be read
 * @histcount: contains history line number count
 * @cmd_buf: address of pointer to cmd_buf,
 */
typedef struct passinfo
{
        char *arg;
	char **argv;
	list_t *history;
        unsigned int line_count;
        char *path;
        int linecount_flag;
	int err_num;
	int argc;
	char *fname;
        char **environ;
	list_t *env;
	int env_changed;
        list_t *alias;
	int status;

        char **cmd_buf; /* pointer for cmd ; chain buffer,  memory of  management */
        int cmd_buf_type; /* CMD_type ||, &&, ; */
	int histcount;
        int readfd;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
                0, 0, 0}


/**
 * struct builtin - contains a builtin string for related functions
 * @type: flag command
 * @func: is the function tested
 */
typedef struct builtin
{
        char *type;
        int (*func)(info_t *);
} builtin_table;

/* for_whils.c */
char *dup_chars(char *, int, int);
int is_cmd(info_t *, char *);
char *find_path(info_t *, char *, char *);

/* fmcg.c */
int loophsh(char **);

/* stringrays.c */
int _strlen(char *);
char *_strcat(char *, char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);

/* rays.c */
int _putchar(char);
char *_strdup(const char *);
void _puts(char *);
char *_strcpy(char *, char *);

/* mistakes.c */
int _eputchar(char);
void _eputs(char *);
int _putsfd(char *str, int fd);
int _putfd(char c, int fd);

/* gotten.c */
void set_info(info_t *, char **);
void clear_info(info_t *);
void free_info(info_t *, int);

/* return.c */
char *_strncat(char *, char *, int);
char *_strncpy(char *, char *, int);
char *_strchr(char *, char);

/* whilelop.c */
void find_cmd(info_t *);
void fork_cmd(info_t *);
int hsh(info_t *, char **);
int find_builtin(info_t *);

/* proof.c */
char **strtow(char *, char *);
char **strtow2(char *, char);

/* distribute.c */
char *_memset(char *, char, unsigned int);
void *_realloc(void *, unsigned int, unsigned int);
void ffree(char **);

/* RAM.c */
int bfree(void **);

/* interact.c */
int is_delim(char, char *);
int interactive(info_t *);
int _atoi(char *);
int _isalpha(int);

/* mistakes1.c */
void print_error(info_t *, char *);
int _erratoi(char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

/* inbuilt.c */
int _myexit(info_t *);
int _myhelp(info_t *);
int _mycd(info_t *);

/* inbuilt1.c */
int _myalias(info_t *);
int _myhistory(info_t *);
int print_alias(list_t *node);
int set_alias(info_t *info, char *str);

/* getinline.c */
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);
ssize_t get_input(info_t *);

/* geteven.c */
char **get_environ(info_t *);
int _setenv(info_t *, char *, char *);
int _unsetenv(info_t *, char *);

/* past.c */
char *get_history_file(info_t *info);
int write_history(info_t *info);
int renumber_history(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);

/* surronding.c */
int _mysetenv(info_t *);
char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int populate_env_list(info_t *);
int _myunsetenv(info_t *);

/* listed.c */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);
size_t print_list_str(const list_t *);

/* verses.c */
int is_chain(info_t *, char *, size_t *);
int replace_vars(info_t *);
int replace_alias(info_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_string(char **, char *);

/* listed1.c */
char **list_to_strings(list_t *);
list_t *node_starts_with(list_t *, char *, char);
size_t print_list(const list_t *);
size_t list_len(const list_t *);
ssize_t get_node_index(list_t *, list_t *);
#endif
