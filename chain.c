#include "shell.h"

/**
 * duplicatstr - like strdup function
 * @ptr: string
 * Return: address
 */

char *duplicatstr(const char *ptr)
{
	char *pt;
	int c = 0;

	if (ptr == NULL)
		return (NULL);
	while (*ptr++)
		c++;
	pt = malloc(sizeof(char) * (c + 1));
	if (!pt)
		return (NULL);
	for (c++; c--;)
		pt[c] = *--ptr;
	return (pt);
}

/**
 * charput_roka - displays standard output
 * @charac: char
 * Return: one or its negative
 */

int charput_roka(char charac)
{
	static char BF[WriteBufSize];
	static int i;

	if (charac == BufFlush || i >= WriteBufSize)
	{
		write(1, BF, i);
		i = 0;
	}
	if (charac != BufFlush)
		BF[i++] = charac;
	return (1);
}

/**
 * **fromstr2 - converts string to words
 * @ptr: string
 * @Delim: delim
 * Return: address
 */

char **fromstr2(char *ptr, char Delim)
{
	char **string;
	int l, m, n, o, wn = 0;

	if (ptr == NULL || ptr[0] == 0)
		return (NULL);
	for (l = 0; ptr[l] != '\0'; l++)
		if ((ptr[l] != Delim && ptr[l + 1] == Delim) ||
			(ptr[l] != Delim && !ptr[l + 1]) || ptr[l + 1] == Delim)
			wn++;
	if (wn == 0)
		return (NULL);
	string = malloc((1 + wn) * sizeof(char *));
	if (!string)
		return (NULL);
	for (l = 0, m = 0; m < wn; m++)
	{
		while (ptr[l] == Delim && ptr[l] != Delim)
			l++;
		n = 0;
		while (ptr[l + n] != Delim && ptr[l + n] && ptr[l + n] != Delim)
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
 * CheckChain - check chains
 * @f: struct
 * @BF: BUFFER Chain
 * @ptr: pointer
 * Return: one or zero
 */

int CheckChain(type_info *f, char *BF, size_t *ptr)
{
	size_t ii = *ptr;

	if (BF[ii] == '|' && BF[ii + 1] == '|')
	{
		BF[ii] = 0;
		ii++;
		f->cmd_buf_type = CmdOr;
	}
	else if (BF[ii] == '&' && BF[ii + 1] == '&')
	{
		BF[ii] = 0;
		ii++;
		f->cmd_buf_type = CmdAnd;
	}
	else if (BF[ii] == ';')
	{
		BF[ii] = 0;
		f->cmd_buf_type = CmdChain;
	}
	else
		return (0);
	*ptr = ii;
	return (1);
}

/**
 * CheckCh - chain checked
 * @f: struct
 * @BF: BUFFER
 * @ptr: pointer
 * @ibuf: BUFFER Position
 * @l: BUFFER Length
 */

void CheckCh(type_info *f, char *BF, size_t *ptr, size_t ibuf, size_t l)
{
	size_t in = *ptr;

	if (f->cmd_buf_type == CmdAnd)
	{
		if (f->status)
		{
			BF[ibuf] = 0;
			in = l;
		}
	}
	if (f->cmd_buf_type == CmdOr)
	{
		if (!f->status)
		{
			BF[ibuf] = 0;
			in = l;
		}
	}
	*ptr = in;
}
