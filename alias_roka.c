#include "shell.h"

/**
  * RoSetting - obtains string
 * @f: struct
 * @s: string
 * Return: zero or one
 */

int RoSetting(type_info *f, char *s)
{
	char *str;

	str = strchar_roka(s, '=');
	if (!str)
		return (1);
	if (!*++str)
		return (AliasUnset(f, s));
	AliasUnset(f, s);
	return (RokaNode(&(f->alias), s, 0) == NULL);
}

/**
 * AliasPrinting - displays string of alias
 * @n: list node
 * Return: zero or one
 */

int AliasPrinting(type_List *n)
{
	char *ptr1 = NULL, *ptr2 = NULL;

	if (n)
	{
		ptr1 = strchar_roka(n->str, '=');
		for (ptr2 = n->str; ptr2 <= ptr1; ptr2++)
			charput_roka(*ptr2);
		charput_roka('\'');
		RRppts(ptr1 + 1);
		RRppts("'\n");
		return (0);
	}
	return (1);
}

/**
 * roka_alias - like alias
 * @f: truct
 *  Return: zero
 */

int roka_alias(type_info *f)
{
	int index = 0;
	type_List *n = NULL;
	char *ptr = NULL;

	if (f->argc == 1)
	{
		n = f->alias;
		while (n)
		{
			AliasPrinting(n);
			n = n->next;
		}
		return (0);
	}
	for (index = 1; f->argv[index]; index++)
	{
		ptr = strchar_roka(f->argv[index], '=');
		if (ptr)
			RoSetting(f, f->argv[index]);
		else
			AliasPrinting(RokaNode(f->alias, f->argv[index], '='));
	}
	return (0);
}

/**
 * roka_env - displays env
 * @f: struct
 * Return: zero
 */

int roka_env(type_info *f)
{
	Listprint(f->env);
	return (0);
}

/**
 * obtain_Env - obtains env value
 * @f: struct
 * @n: name of variable
 * Return: env value
 */

char *obtain_Env(type_info *f, const char *n)
{
	char *ptr;
	type_List *listN = f->env;

	while (listN)
	{
		ptr = pOfstr(listN->str, n);
		if (ptr && *ptr)
			return (ptr);
		listN = listN->next;
	}
	return (NULL);
}
