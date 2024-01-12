#ifndef __SHELL__H__
#define __SHELL__H__

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/wait.h>

#define ReadBufSize 1024
#define WriteBufSize 1024
#define BufFlush -1
#define CmdNorm 0
#define CmdOr 1
#define CmdAnd 2
#define CmdChain 3
#define ConvertLowercase 1
#define UnsignedConvert 2
#define USE_GETLINE 0
#define USE_STRTOK 0
#define FileHist ".simple_shell_history"
#define MaxHist 4096
extern char **environ;

/**
 * struct strList - list
 * @num: number
 * @str: string
 * @next: next
 */

typedef struct strList
{
	int num;
	char *str;
	struct strList *next;
} type_List;

/**
 * struct infoPass - Huge List
 * @arg: argument
 * @argv: vector
 * @path: path
 * @argc: Number of args
 * @line_count: Number of errors
 * @err_num: error
 * @linecount_flag: flage
 * @fname: name of file
 * @env: list
 * @environ: environment
 * @history: history
 * @alias: alias
 * @env_changed: new environ
 * @status: status
 * @cmd_buf: BF cmd
 * @cmd_buf_type: type BF cmd
 * @readfd: file description
 * @histcount: count of history
 */

typedef struct infoPass
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	type_List *env;
	type_List *history;
	type_List *alias;
	char **environ;
	int env_changed;
	int status;
	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} type_info;
#define InitInfo                                                                \
	{                                                                           \
		NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
			0, 0, 0                                                             \
	}
/**
 * struct Built - all builtin functions
 * @type: flage
 * @func: fun
 */

typedef struct Built
{
	char *type;
	int (*func)(type_info *);
} TableBuilt;

int roka_lenstr(char *);
int compStr(char *, char *);
char *pOfstr(const char *, const char *);
char *catstr_roka(char *, char *);
char *copystr_roka(char *, char *);
char *duplicatstr(const char *);
void RRppts(char *);
int charput_roka(char);
char *strncopy_roka(char *, char *, int);
char *_strncat(char *, char *, int);
char *strchar_roka(char *, char);
char **wfromstr(char *, char *);
char **fromstr2(char *, char);
char *roka_Memset(char *, char, unsigned int);
void freerokaf(char **);
void RokaFree(type_List **pointerH);
void *roka_realloc(void *, unsigned int, unsigned int);
int freepointer(void **);
int checkAct(type_info *);
int checkDel(char, char *);
int Alpha_check(int);
int atoiii(char *);
int RemRo(type_List **H, unsigned int ind);
int eratoi(char *);
void Er_Printing(type_info *, char *);
int dec_Printing(int, int);
char *num_converting(long int, int, int);
void Com_Removing(char *);
int roka_ex(type_info *);
int roka_cd(type_info *);
int roka_help(type_info *);
int roka_hist(type_info *);
int roka_alias(type_info *);
ssize_t obtain_inputtting(type_info *);
int roka_getline(type_info *, char **, size_t *);
void handlersig(int);
void roka_clear(type_info *);
void f_setting(type_info *, char **);
void f_freeing(type_info *, int);
char *obtain_Env(type_info *, const char *);
int roka_env(type_info *);
int roka_env_setting(type_info *);
int roka_env_unsetting(type_info *);
int pop_env_li(type_info *);
char **environ_obtain(type_info *);
int roka_envunsetting(type_info *, char *);
int roka_envsetting(type_info *, char *, char *);
char *obt_FHist(type_info *info);
int Hist_Writing(type_info *info);
int Hist_reading(type_info *info);
int creat_listhist(type_info *info, char *buf, int linecount);
int reconunting_history(type_info *info);
type_List *creat_Lnode(type_List **, const char *, int);
type_List *RokaNeNode(type_List **, const char *, int);
size_t Listprint(const type_List *);
int indnode_Rem(type_List **, unsigned int);
void alllist_Freeing(type_List **);
size_t len_list(const type_List *);
char **string_from_list(type_List *);
size_t displays_List(const type_List *);
int alias_setting(type_info *, char *);
ssize_t BF_reading(type_info *, char *, size_t *);
ssize_t BF_inputting(type_info *, char **, size_t *);
int strREPLACING(char **, char *);
int mHSH(type_info *, char **);
int built_Finder(type_info *);
void CMDFika(type_info *f);
void forkcmdddd(type_info *);
int CCMD(type_info *, char *);
char *RODuplicates(char *, int, int);
char *PFin(type_info *, char *, char *);
int loophsh(char **);
void ETS(char *);
int EpuT(char);
int Rokaputs(char c, int fd);
int Rokaput(char *str, int fd);
type_List *RokaNode(type_List *, char *, char);
ssize_t RokaObt(type_List *, type_List *);
int CheckChain(type_info *, char *, size_t *);
void CheckCh(type_info *, char *, size_t *, size_t, size_t);
int Ro_Replace(type_info *);
int ReplVar(type_info *);
int AliasUnset(type_info *, char *);
int AliasPrinting(type_List *);
#endif