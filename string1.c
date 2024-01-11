#include "shell.h"

/**
 * Rokaputs - displays descreption of file
 * @charac: charactars
 * @descrF: descreption file
 * Return: one or negative one
 */

int Rokaputs(char charac, int descrF)
{
	static char BF[WriteBufSize];
	static int index;

	if (charac == BufFlush || index >= WriteBufSize)
	{
		write(descrF, BF, index);
		index = 0;
	}
	if (charac != BufFlush)
		BF[index++] = charac;
	return (1);
}

/**
 * Rokaput - displays string
 * @s: string
 * @descF: descreption of file
 * Return: chars No.
 */

int Rokaput(char *s, int descF)
{
	int index = 0;

	if (!s)
		return (0);
	while (*s)
	{
		index += Rokaputs(*s++, descF);
	}
	return (index);
}

/**
 * eratoi - obtains integer from string
 * @s: string
 * Return: zero or negativeone
 */

int eratoi(char *s)
{
	unsigned long int R = 0;
	int index = 0;

	if (*s == '+')
		s++;
	for (index = 0; s[index] != '\0'; index++)
	{
		if (s[index] >= '0' && s[index] <= '9')
		{
			R *= 10;
			R += (s[index] - '0');
			if (R > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (R);
}

/**
 * num_converting - number converting function
 * @nm: the number
 * @b: the base
 * @f: flag of Arguments
 * Return: the required string
 */

char *num_converting(long int nm, int b, int f)
{
	static char BF[50];
	char s = 0;
	unsigned long i = nm;
	static char *strar;
	char *str;

	if (!(f & UnsignedConvert) && nm < 0)
	{
		i = -nm;
		s = '-';
	}
	strar = f & ConvertLowercase ? "0123456789abcdef" : "0123456789ABCDEF";
	str = &BF[49];
	*str = '\0';
	do
	{
		*--str = strar[i % b];
		i /= b;
	} while (i != 0);
	if (s)
		*--str = s;
	return (str);
}

/**
 * Com_Removing - used to remove comments
 * @buf: BUFFER
 */

void Com_Removing(char *buf)
{
	int index;

	for (index = 0; buf[index] != '\0'; index++)
		if (buf[index] == '#' && (!index || buf[index - 1] == ' '))
		{
			buf[index] = '\0';
			break;
		}
}
