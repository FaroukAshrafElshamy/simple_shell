#include "shell.h"

/**
 * roka_env_setting - set the value of environment
 * @f: struct
 *  Return: zero
 */

int roka_env_setting(type_info *f)
{
	if (f->argc != 3)
	{
		ETS("Incorrect number of arguements\n");
		return (1);
	}
	if (roka_envsetting(f, f->argv[1], f->argv[2]))
		return (0);
	return (1);
}

/**
 * roka_env_unsetting - delete var of env
 * @f: struct
 * Return: zero
 */

int roka_env_unsetting(type_info *f)
{
	int i;

	if (f->argc == 1)
	{
		ETS("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= f->argc; i++)
		roka_envunsetting(f, f->argv[i]);
	return (0);
}

/**
 * pop_env_li - list pop
 * @f: struct
 * Return: zero
 */

int pop_env_li(type_info *f)
{
	size_t in;
	type_List *nt = NULL;

	for (in = 0; environ[in]; in++)
		creat_EnNode(&nt, environ[in], 0);
	f->env = nt;
	return (0);
}

/**
 * ETS - displays  str
 * @s: string
 */

void ETS(char *s)
{
	int index = 0;

	if (!s)
		return;
	while (s[index] != '\0')
	{
		EpuT(s[index]);
		index++;
	}
}

/**
 * Er_Printing - displays the error
 * @f: struct
 * @erS: the error string
 */

void Er_Printing(type_info *f, char *erS)
{
	ETS(f->fname);
	ETS(": ");
	dec_Printing(f->line_count, STDERR_FILENO);
	ETS(": ");
	ETS(f->argv[0]);
	ETS(": ");
	ETS(erS);
}
