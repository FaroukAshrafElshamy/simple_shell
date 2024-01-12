#include "shell.h"

/**
 * forkcmdddd - cmd forking
 * @f: struct
 */

void forkcmdddd(type_info *f)
{
	pid_t chppd;

	chppd = fork();
	if (chppd == -1)
	{
		perror("Error:");
		return;
	}
	if (chppd == 0)
	{
		if (execve(f->path, f->argv, environ_obtain(f)) == -1)
		{
			f_freeing(f, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(f->status));
		if (WIFEXITED(f->status))
		{
			f->status = WEXITSTATUS(f->status);
			if (f->status == 126)
				Er_Printing(f, "Permission denied\n");
		}
	}
}

/**
 * fputs - displays str
 * @ptr: str
 */

void Rokaputs(char *ptr)
{
	int ind = 0;

	if (!ptr)
		return;
	while (ptr[ind] != '\0')
	{
		charput_roka(ptr[ind]);
		ind++;
	}
}

/**
 * **wfromstr - words will obtained from string
 * @ptr: string
 * @Delim: delim
 * Return: address
 */

char **wfromstr(char *ptr, char *Delim)
{
	char **string;
	int l, m, n, o, wn = 0;

	if (ptr == NULL || ptr[0] == 0)
		return (NULL);
	if (!Delim)
		Delim = " ";
	for (l = 0; ptr[l] != '\0'; l++)
		if (!checkDel(ptr[l], Delim) && (checkDel(ptr[l + 1], Delim) || !ptr[l + 1]))
			wn++;
	if (wn == 0)
		return (NULL);
	string = malloc((1 + wn) * sizeof(char *));
	if (!string)
		return (NULL);
	for (l = 0, m = 0; m < wn; m++)
	{
		while (checkDel(ptr[l], Delim))
			l++;
		n = 0;
		while (!checkDel(ptr[l + n], Delim) && ptr[l + n])
			n++;
		string[m] = malloc((n + 1) * sizeof(char));
		if (!string[m])
		{
			for (n = 0; n < m; n++)
				free(string[n]);
			free(string);
			return (NULL);
		}
		for (o = 0; o < n; o++)
			string[m][o] = ptr[l++];
		string[m][o] = 0;
	}
	string[m] = NULL;
	return (string);
}

/**
 * Ro_Replace - to change the alias
 * @f: struct
 * Return: one or zero
 */

int Ro_Replace(type_info *f)
{
	type_List *N;
	char *ptr;
	int counter;

	for (counter = 0; counter < 10; counter++)
	{
		N = RokaNode(f->alias, f->argv[0], '=');
		if (!N)
			return (0);
		free(f->argv[0]);
		ptr = strchar_roka(N->str, '=');
		if (!ptr)
			return (0);
		ptr = duplicatstr(ptr + 1);
		if (!ptr)
			return (0);
		f->argv[0] = ptr;
	}
	return (1);
}

/**
 * ReplVar - to change variables
 * @f: struct
 * Return: one or zero
 */

int ReplVar(type_info *f)
{
	type_List *n;
	int index = 0;

	for (index = 0; f->argv[index]; index++)
	{
		if (f->argv[index][0] != '$' || !f->argv[index][1])
			continue;
		if (!compStr(f->argv[index], "$?"))
		{
			StringRep(&(f->argv[index]),
						 duplicatstr(num_converting(f->status, 10, 0)));
			continue;
		}
		if (!compStr(f->argv[index], "$$"))
		{
			StringRep(&(f->argv[index]),
						 duplicatstr(num_converting(getpid(), 10, 0)));
			continue;
		}
		n = RokaNode(f->env, &f->argv[index][1], '=');
		if (n)
		{
			StringRep(&(f->argv[index]),
						 duplicatstr(strchar_roka(n->str, '=') + 1));
			continue;
		}
		StringRep(&f->argv[index], duplicatstr(""));
	}
	return (0);
}
