#include "shell.h"

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