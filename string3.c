#include "shell.h"

/**
 * roka_lenstr - to get the length of string
 * @str: string
 * Return: length
 */

int roka_lenstr(char *str)
{
	int c = 0;

	if (!str)
		return (0);
	while (*str++)
		c++;
	return (c);
}

/**
 * compStr - like strcmp function
 * @ptr1: string No.1
 * @ptr2: string No.
 * Return: -1 or 1 or 0
 */

int compStr(char *ptr1, char *ptr2)
{
	while (*ptr1 && *ptr2)
	{
		if (*ptr1 != *ptr2)
			return (*ptr1 - *ptr2);
		ptr1++;
		ptr2++;
	}
	if (*ptr1 == *ptr2)
		return (0);
	else
		return (*ptr1 < *ptr2 ? -1 : 1);
}

/**
 * pOfstr - haystack checking
 * @H: checking string
 * @N: the required string
 * Return: pointer
 */

char *pOfstr(const char *H, const char *N)
{
	while (*N)
		if (*N++ != *H++)
			return (NULL);
	return ((char *)H);
}

/**
 * catstr_roka - like strcat function
 * @BD: Buffer destin.
 * @BS: Buffer source
 * Return: address
 */

char *catstr_roka(char *BD, char *BS)
{
	char *a = BD;

	while (*BD)
		BD++;
	while (*BS)
		*BD++ = *BS++;
	*BD = *BS;
	return (a);
}

/**
 * copystr_roka - like strcpy function
 * @BD: Buffer destin.
 * @BS: Buffer source
 * Return: address
 */

char *copystr_roka(char *BD, char *BS)
{
	int c = 0;

	if ((BD == BS) || (BS == 0))
		return (BD);
	while (BS[c])
	{
		BD[c] = BS[c];
		c++;
	}
	BD[c] = 0;
	return (BD);
}
