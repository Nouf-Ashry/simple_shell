#ifndef SHELL_H
#define SHELL_H

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
#define CMD_NORM        0
#define CMD_OR          1
#define CMD_AND         2
#define CMD_CHAIN       3

/* for convert_number() */
#define CONVERT_LOWERCASE       1
#define CONVERT_UNSIGNED        2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0
#define HIST_FILE        ".simple_shell_history"
#define HIST_MAX        4096
extern char **environ;

/**
 * struct lists - singly linked list
 * @num: number
 * @str: string
 * @next: pointer
 */

typedef struct lists
{
	int num;
	char *str;
	struct lists *next;
} list_t;

/**
 * struct passinf - contains pseudo-arguements.
 * @arg: string
 * @argv:an array of strings
 * @path: a string path
 * @argc: the argument count
 * @line_count: error count
 * @err_num: error code
 * @linecount_flag: input
 * @finame: filename
 * @env: linked list
 * @environ: custom modified
 * @history: his node
 * @alias: alias node
 * @env_changed: changed
 * @status: the status
 * @cmd_buf: address of pointer
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @readfd: input
 * @histcount: his line number count
 */

typedef struct passinf
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *finame;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;
	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} inf_t;

#define INFO_INIT \
	{ \
		NULL,  /* field1 */ \
		NULL,  /* field2 */ \
		NULL,  /* field3 */ \
		0,     /* field4 */ \
		0,     /* field5 */ \
		0,     /* field6 */ \
		0,     /* field7 */ \
		NULL,  /* field8 */ \
		NULL,  /* field9 */ \
		NULL,  /* field10 */ \
		NULL,  /* field11 */ \
		NULL,  /* field12 */ \
		0,     /* field13 */ \
		0,     /* field14 */ \
		NULL,  /* field15 */ \
		0,     /* field16 */ \
		0,     /* field17 */ \
		0      /* field18 */ \
}

/**
 * struct builtin - contains a builtin str.
 * @type: the builtin command flag
 * @func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(inf_t *);
} builtin_tab;

/*  shloop.c*/
int hash(inf_t *, char **);
int f_builtin(inf_t *);
void fnd_cmd(inf_t *);
void frk_cmd(inf_t *);

/* parser.c */
int is_cmd(inf_t *, char *);
char *dup_ch(char *, int, int);
char *fnd_path(inf_t *, char *, char *);


/* loophsh.c */

/* int loophsh(char **);*/

/* errors.c */
void _erputs(char *);
int _erputchar(char);
int _eputfd(char c, int fd);
int _eputsfd(char *str, int fd);


/* string.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *sta_with(const char *, const char *);
char *_strcat(char *, char *);

/* string2.c */
char *_strcpy(char *, char *);
char *_strsdup(const char *);
void _puts(char *);
int _putchar(char);


/* exits.c */
char *_strscpy(char *, char *, int);
char *_strscat(char *, char *, int);
char *_strnchr(char *, char);

/* tokenizer.c */
char **strstow(char *, char *);
char **strstowar(char *, char);

/* realloc.c */
char *_memset(char *, char, unsigned int);
void ffre(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* memory.c */
int bfre(void **);

/* atoi.c */
int interactives(inf_t *);
int is_delimet(char, char *);
int _isalpha(int);
int _atoi(char *);

/* errors2.c */
int _erratoi(char *);
void pr_error(inf_t *info, char *message);
int pr_d(int, int);
char *conv_number(long int, int, int);
void rmov_comments(char *);

/* builtin.c */
int _mineexit(inf_t *);
int _minecd(inf_t *);
int _minehelp(inf_t *);

/* builtin2.c */
int _minehistory(inf_t *);
int _minealias(inf_t *);

/*getline.c */
ssize_t gets_input(inf_t *);
int _getsline(inf_t *, char **, size_t *);
void sigintHandler(int);

/* getinfo.c */
void cls_inf(inf_t *);
void sets_inf(inf_t *, char **);
void fre_inf(inf_t *, int);

/* environ.c */
char *_getsenv(inf_t *, const char *);
int _myineenv(inf_t *);
int _mineenv(inf_t *);
int _minesetenv(inf_t *);
int _mineunsetenv(inf_t *);
int pop_env_list(inf_t *);

/* getenv.c */
char **gets_environ(inf_t *);
int _unsetsenv(inf_t *, char *);
int _setsenv(inf_t *, char *, char *);

/* history.c */
char *get_his_fl(inf_t *info);
int write_his(inf_t *info);
int red_his(inf_t *info);
int buld_his_lst(inf_t *info, char *buf, int linecount);
int renum_history(inf_t *info);

/* lists.c */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t pr_lst_str(const list_t *);
int del_node_at_ndex(list_t **, unsigned int);
void fre_lst(list_t **);

/* lists2.c */
size_t lst_len(const list_t *);
char **lst_tostrs(list_t *);
size_t pr_lst(const list_t *);
list_t *node_sta_with(list_t *, char *, char);
ssize_t get_node_ndex(list_t *, list_t *);

/* vars.c */
int is_chain(inf_t *, char *, size_t *);
void ch_chain(inf_t *, char *, size_t *, size_t, size_t);
int repl_alias(inf_t *);
int repl_var(inf_t *);
int repl_str(char **, char *);

#endif
