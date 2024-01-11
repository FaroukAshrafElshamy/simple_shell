#include "shell.h"

/**
 * CCMD - check cmd
 * @f: struct
 * @p: file path
 * Return: zero or one
 */

int CCMD(type_info *f, char *p)
{
	struct stat s;

	(void)f;
	if (!p || stat(p, &s))
		return (0);
	if (s.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * RODuplicates - used in duplicating
 * @stringPath: path
 * @st: index of start
 * @sp: index of stop
 * Return: address
 */

char *RODuplicates(char *stringPath, int st, int sp)
{
	int m = 0, n = 0;
	static char BF[1024];

	for (n = 0, m = st; m < sp; m++)
		if (stringPath[m] != ':')
			BF[n++] = stringPath[m];
	BF[n] = 0;
	return (BF);
}

/**
 * roka_Memset - like memset function
 * @am: area of memory
 * @fb: filled byte
 * @nb: bytes number
 * Return: address
 */

char *roka_Memset(char *am, char fb, unsigned int nb)
{
	unsigned int index;

	for (index = 0; index < nb; index++)
		am[index] = fb;
	return (am);
}

/**
 * freerokaf - delete strings
 * @str: string
 */

void freerokaf(char **str)
{
	char **p = str;

	if (!str)
		return;
	while (*str)
		free(*str++);
	free(p);
}

/**
 * roka_realloc - like realloc function
 * @ppp: the pointer
 * @os: old size
 * @ns: new size
 * Return: address
 */

void *roka_realloc(void *ppp, unsigned int os, unsigned int ns)
{
	char *pointer;

	if (!ppp)
		return (malloc(ns));
	if (!ns)
		return (free(ppp), NULL);
	if (ns == os)
		return (ppp);
	pointer = malloc(ns);
	if (!pointer)
		return (NULL);
	os = os < ns ? os : ns;
	while (os--)
		pointer[os] = ((char *)ppp)[os];
	free(ppp);
	return (pointer);
}
