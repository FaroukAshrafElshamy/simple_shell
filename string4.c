#include "shell.h"

/**
 * StringRep - used to replace thestring
 * @old: the old
 * @new: the new
 * Return: one or zero
 */

int StringRep(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
