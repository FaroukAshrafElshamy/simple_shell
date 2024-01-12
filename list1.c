#include "shell.h"

/**
 * RokaLeNode - creat new node
 * @h: head
 * @s: string
 * @n: index
 * Return: list size
 */

type_List *RokaLeNode(type_List **h, const char *s, int n)
{
	type_List *nHead;

	if (!h)
		return (NULL);
	nHead = malloc(sizeof(type_List));
	if (!nHead)
		return (NULL);
	roka_Memset((void *)nHead, 0, sizeof(type_List));
	nHead->num = n;
	if (s)
	{
		nHead->str = duplicatstr(s);
		if (!nHead->str)
		{
			free(nHead);
			return (NULL);
		}
	}
	nHead->next = *h;
	*h = nHead;
	return (nHead);
}

/**
 * RokaNeNode - creats node at the end
 * @h: head
 * @s: string
 * @n: index
 * Return: list size
 */

type_List *RokaNeNode(type_List **h, const char *s, int n)
{
	type_List *node1, *node2;

	if (!h)
		return (NULL);
	node2 = *h;
	node1 = malloc(sizeof(type_List));
	if (!node1)
		return (NULL);
	roka_Memset((void *)node1, 0, sizeof(type_List));
	node1->num = n;
	if (s)
	{
		node1->str = duplicatstr(s);
		if (!node1->str)
		{
			free(node1);
			return (NULL);
		}
	}
	if (node2)
	{
		while (node2->next)
			node2 = node2->next;
		node2->next = node1;
	}
	else
		*h = node1;
	return (node1);
}

/**
 * Listprint - displays the string of the list
 * @head: head
 * Return: list size
 */

size_t Listprint(const type_List *head)
{
	size_t index = 0;

	while (head)
	{
		RRppts(head->str ? head->str : "(nil)");
		RRppts("\n");
		head = head->next;
		index++;
	}
	return (index);
}

/**
 * SFL - gets the string array
 * @h: head
 * Return: string array
 */

char **SFL(type_List *h)
{
	type_List *n = h;

	size_t m = len_list(h), k;
	char **ptr1;
	char *ptr2;

	if (!h || !m)
		return (NULL);
	ptr1 = malloc(sizeof(char *) * (m + 1));
	if (!ptr1)
		return (NULL);
	for (m = 0; n; n = n->next, m++)
	{
		ptr2 = malloc(roka_lenstr(n->str) + 1);
		if (!ptr2)
		{
			for (k = 0; k < m; k++)
				free(ptr1[k]);
			free(ptr1);
			return (NULL);
		}

		ptr2 = copystr_roka(ptr2, n->str);
		ptr1[m] = ptr2;
	}
	ptr1[m] = NULL;
	return (ptr1);
}

/**
 * DispList - displays component of list
 * @head: head
 * Return: list size
 */

size_t DispList(const type_List *head)
{
	size_t index = 0;

	while (head)
	{
		RRppts(num_converting(head->num, 10, 0));
		charput_roka(':');
		charput_roka(' ');
		RRppts(head->str ? head->str : "(nil)");
		RRppts("\n");
		head = head->next;
		index++;
	}
	return (index);
}
