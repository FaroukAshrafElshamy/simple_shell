#include "shell.h"

/**
 * roka_ex - outs from shell
 * @f: struct
 * Return: satatus of exit
 */

int roka_ex(type_info *f)
{
	int chEx;

	if (f->argv[1])
	{
		chEx = eratoi(f->argv[1]);
		if (chEx == -1)
		{
			f->status = 2;
			Er_Printing(f, "Illegal number: ");
			ETS(f->argv[1]);
			EpuT('\n');
			return (1);
		}
		f->err_num = eratoi(f->argv[1]);
		return (-2);
	}
	f->err_num = -1;
	return (-2);
}

/**
 * roka_cd - to get the directory
 * @f: structu
 * Return: zero
 */

int roka_cd(type_info *f)
{
	int rChDr;
	char *ptr, *d, BF[1024];

	ptr = getcwd(BF, 1024);
	if (!ptr)
		RRppts("TODO: >>getcwd failure emsg here<<\n");
	if (!f->argv[1])
	{
		d = obtain_Env(f, "HOME=");
		if (!d)
			rChDr =
				chdir((d = obtain_Env(f, "PWD=")) ? d : "/");
		else
			rChDr = chdir(d);
	}
	else if (compStr(f->argv[1], "-") == 0)
	{
		if (!obtain_Env(f, "OLDPWD="))
		{
			RRppts(ptr);
			charput_roka('\n');
			return (1);
		}
		RRppts(obtain_Env(f, "OLDPWD=")), charput_roka('\n');
		rChDr =
			chdir((d = obtain_Env(f, "OLDPWD=")) ? d : "/");
	}
	else
		rChDr = chdir(f->argv[1]);
	if (rChDr == -1)
	{
		Er_Printing(f, "can't cd to ");
		ETS(f->argv[1]), EpuT('\n');
	}
	else
	{
		roka_envsetting(f, "OLDPWD", obtain_Env(f, "PWD="));
		roka_envsetting(f, "PWD", getcwd(BF, 1024));
	}
	return (0);
}

/**
 * roka_help - help function
 * @f: struct
 * Return: zero
 */

int roka_help(type_info *f)
{
	char **arArgs;

	arArgs = f->argv;
	RRppts("help call works. Function not yet implemented \n");
	if (0)
		RRppts(*arArgs);
	return (0);
}

/**
 * roka_hist - like history function
 * @f: struct
 *  Return: Always 0
 */

int roka_hist(type_info *f)
{
	DispList(f->history);
	return (0);
}

/**
 * AliasUnset - obtains string from alias
 * @f: struct
 * @ptr: string
 * Return: zero or one
 */

int AliasUnset(type_info *f, char *ptr)
{
	int R;
	char *ptrs, charac;

	ptrs = strchar_roka(ptr, '=');
	if (!ptrs)
		return (1);
	charac = *ptrs;
	*ptrs = 0;
	R = RemRo(&(f->alias),
					RokaObt(f->alias, RokaNode(f->alias, ptr, -1)));
	*ptrs = charac;
	return (R);
}
