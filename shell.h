#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* for convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct liststr - a singly linked list
 * @numb:  number field
 * @str:  string
 * @next: it  points to the next node
 */
typedef struct liststr
{
	int numb;
	char *str;
	struct liststr *next;
} list_t;

/**
 *struct passinfo - contains pseudo-arguements to pass into a function,
 *allowing uniform prototype for function to pointer struct
 *@arg: a string that is generated from getline containing arguements
 *@argv: an array of strings thatis  generated from arg
 *@path: a string path for current command
 *@argc: argument count
 *@line_count: error count
 *@err_num: error code for exit()s
 *@linecount_flag: on count this line of input
 *@fname: program filename
 *@env: it linked list local copy of environ
 *@environ:the  custom modified copy of environ from LL env
 *@history: history node
 *@alias: alias node
 *@env_changed:  if environ was changed
 *@status: return status of the last exec command
 *@cmd_buf: the address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: fd from which to read line input
 *@histcount: history line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

/* toem_builtin.c */
int _exiting(info_t *);
int _forcd(info_t *);
int _ourhelp(info_t *);

/* toem_errors.c */
void _eput(char *);
int _eputcha(char);
int _ptfd(char , int fd);
int _putfd(char *str, int fd);

/* toem_environ.c */
char *_putenv(info_t *, const char *);
int _thenv(info_t *);
int _setenv(info_t *);
int _unsetenv(info_t *);
int popul_env_list(info_t *);

/* toem_errors1.c */
int _eratoi(char *);
void print_ero(info_t *, char *);
int print_b(int, int);
char *convet_numba(long int, int, int);
void rmov_comment(char *)

/* toem_exits.c */
char *_strngcopy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_stringchr(char *, char);

/* toem_getenv.c */
char *get_envaron(info_t *);
int _resetenv(info_t *, char *);
int _settenv(info_t *, char *, char *);

/* toem_getinfo.c */
void cleared_infor(info_t *);
void set_inform(info_t *, char **);
void free_inform(info_t *, int);

/*toem_getline.c */
ssize_t get_imput _buf(info_t *);
int _gotline(info_t *, char **, size_t *);
void Handler(int);

/* toem_history.c */
char *_history_file(info_t *info);
int written_history(info_t *info);
int reading_history(info_t *info);
int building_history_list(info_t *info, char *buf, int linecount);
int renumbering_history(info_t *info);
