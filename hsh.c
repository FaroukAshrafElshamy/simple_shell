#include "shell.h"

/**
 * RokaNode - get prefex starting node
 * @n: head
 * @p: the matched str
 * @charac: char
 * Return: Null or Node
 */
type_List *RokaNode(type_List *n, char *p, char charac)
{
	char *ptr = NULL;

	while (n)
	{
		ptr = pOfstr(n->str, p);
		if (ptr && ((charac == -1) || (*ptr == charac)))
			return (n);
		n = n->next;
	}
	return (NULL);
}

/**
 * PFin - cmd finder
 * @f: struct
 * @stPath: string path
 * @Fcmd: finding cmd
 * Return: complete cmd path
 */
char *PFin(type_info *f, char *stPath, char *Fcmd)
{
	int in = 0, posc = 0;
	char *cmdPath;

	if (!stPath)
		return (NULL);
	if ((roka_lenstr(Fcmd) > 2) && pOfstr(Fcmd, "./"))
	{
		if (CCMD(f, Fcmd))
			return (Fcmd);
	}
	while (1)
	{
		if (!stPath[in] || stPath[in] == ':')
		{
			cmdPath = RODuplicates(stPath, posc, in);
			if (!*cmdPath)
				catstr_roka(cmdPath, Fcmd);
			else
			{
				catstr_roka(cmdPath, "/");
				catstr_roka(cmdPath, Fcmd);
			}
			if (CCMD(f, cmdPath))
				return (cmdPath);
			if (!stPath[in])
				break;
			posc = in;
		}
		in++;
	}
	return (NULL);
}

/**
 * FHS - loop of the main shell
 * @f: struct
 * @arargs: arrays of args
 * Return: zero or one
 */
int FHS(type_info *f, char **arargs)
{
	ssize_t c = 0;
	int rBuilt = 0;

	while (c != -1 && rBuilt != -2)
	{
		roka_clear(f);
		if (checkAct(f))
			RRppts("$ ");
		EpuT(BufFlush);
		c = obtain_inputtting(f);
		if (c != -1)
		{
			f_setting(f, arargs);
			rBuilt = BuilFin(f);
			if (rBuilt == -1)
				CMDFika(f);
		}
		else if (checkAct(f))
			charput_roka('\n');
		f_freeing(f, 0);
	}
	Hist_Writing(f);
	f_freeing(f, 1);
	if (!checkAct(f) && f->status)
		exit(f->status);
	if (rBuilt == -2)
	{
		if (f->err_num == -1)
			exit(f->status);
		exit(f->err_num);
	}
	return (rBuilt);
}

/**
 * BuilFin - builtin finder
 * @info: struct
 * Return: -one,zero,one,2
 */
int BuilFin(type_info *info)
{
	int index, rBuilt = -1;
	TableBuilt allbuilt[] = {
		{"exit", roka_ex},
		{"env", roka_env},
		{"help", roka_help},
		{"history", roka_hist},
		{"setenv", roka_env_setting},
		{"unsetenv", roka_env_unsetting},
		{"cd", roka_cd},
		{"alias", roka_alias},
		{NULL, NULL}};
	for (index = 0; allbuilt[index].type; index++)
		if (compStr(info->argv[0], allbuilt[index].type) == 0)
		{
			info->line_count++;
			rBuilt = allbuilt[index].func(info);
			break;
		}
	return (rBuilt);
}

/**
 * CMDFika - cmd finder
 * @f: struct
 */
void CMDFika(type_info *f)
{
	int n, m;
	char *p = NULL;

	f->path = f->argv[0];
	if (f->linecount_flag == 1)
	{
		f->line_count++;
		f->linecount_flag = 0;
	}
	for (n = 0, m = 0; f->arg[n]; n++)
		if (!checkDel(f->arg[n], " \t\n"))
			m++;
	if (!m)
		return;
	p = PFin(f, obtain_Env(f, "PATH="), f->argv[0]);
	if (p)
	{
		f->path = p;
		forkcmdddd(f);
	}
	else
	{
		if ((checkAct(f) || obtain_Env(f, "PATH=")
			|| f->argv[0][0] == '/') && CCMD(f, f->argv[0]))
			forkcmdddd(f);
		else if (*(f->arg) != '\n')
		{
			f->status = 127;
			Er_Printing(f, "not found\n");
		}
	}
}
