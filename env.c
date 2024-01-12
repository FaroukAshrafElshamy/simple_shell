#include "shell.h"

/**
 * dec_Printing - displays decimal
 * @input: input
 * @fd: description of file
 * Return: chars No.
 */

int dec_Printing(int input, int fd)
{
	int (*__putchar)(char) = charput_roka;
	unsigned int Abs, Cr;
	int ind, C = 0;

	if (fd == STDERR_FILENO)
		__putchar = EpuT;
	if (input < 0)
	{
		Abs = -input;
		__putchar('-');
		C++;
	}
	else
		Abs = input;
	Cr = Abs;
	for (ind = 1000000000; ind > 1; ind /= 10)
	{
		if (Abs / ind)
		{
			__putchar('0' + Cr / ind);
			C++;
		}
		Cr %= ind;
	}
	__putchar('0' + Cr);
	C++;
	return (C);
}

/**
 * environ_obtain - obtains the environ
 * @f: struct
 * Return: zero
 */

char **environ_obtain(type_info *f)
{
	if (!f->environ || f->env_changed)
	{
		f->environ = SFL(f->env);
		f->env_changed = 0;
	}
	return (f->environ);
}

/**
 * roka_envunsetting - unset the value of environment
 * @f: struct
 * @v: variable
 *  Return: one or zero
 */

int roka_envunsetting(type_info *f, char *v)
{
	size_t index = 0;
	char *ptr;
	type_List *n = f->env;

	if (!n || !v)
		return (0);
	while (n)
	{
		ptr = pOfstr(n->str, v);
		if (ptr && *ptr == '=')
		{
			f->env_changed = RemRo(&(f->env), index);
			index = 0;
			n = f->env;
			continue;
		}
		n = n->next;
		index++;
	}
	return (f->env_changed);
}

/**
 * roka_envsetting - set the value of environ
 * @f: struct
 * @v: variable
 * @vu: value
 *  Return: zero
 */

int roka_envsetting(type_info *f, char *v, char *vu)
{
	type_List *N;
	char *str;
	char *BF = NULL;

	if (!v || !vu)
		return (0);
	BF = malloc(roka_lenstr(v) + roka_lenstr(vu) + 2);
	if (!BF)
		return (1);
	copystr_roka(BF, v);
	catstr_roka(BF, "=");
	catstr_roka(BF, vu);
	N = f->env;
	while (N)
	{
		str = pOfstr(N->str, v);
		if (str && *str == '=')
		{
			free(N->str);
			N->str = BF;
			f->env_changed = 1;
			return (0);
		}
		N = N->next;
	}
	RokaNode(&(f->env), BF, 0);
	free(BF);
	f->env_changed = 1;
	return (0);
}

/**
 * f_setting - info setting
 * @f: struct
 * @arags: array of args
 */

void f_setting(type_info *f, char **arags)
{
	int index = 0;

	f->fname = arags[0];
	if (f->arg)
	{
		f->argv = wfromstr(f->arg, " \t");
		if (!f->argv)
		{
			f->argv = malloc(sizeof(char *) * 2);
			if (f->argv)
			{
				f->argv[0] = duplicatstr(f->arg);
				f->argv[1] = NULL;
			}
		}
		for (index = 0; f->argv && f->argv[index]; index++)
			;
		f->argc = index;
		Ro_Replace(f);
		ReplVar(f);
	}
}
