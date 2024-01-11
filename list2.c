#include "shell.h"

/**
 * RemRo - remove node
 * @H: head
 * @ind: index
 * Return: one or zero
 */

int RemRo(type_List **H, unsigned int ind)
{
	type_List *n1, *n2;
	unsigned int in = 0;

	if (!H || !*H)
		return (0);

	if (!ind)
	{
		n1 = *H;
		*H = (*H)->next;
		free(n1->str);
		free(n1);
		return (1);
	}
	n1 = *H;
	while (n1)
	{
		if (in == ind)
		{
			n2->next = n1->next;
			free(n1->str);
			free(n1);
			return (1);
		}
		in++;
		n2 = n1;
		n1 = n1->next;
	}
	return (0);
}

/**
 * RokaFree - delete the list
 * @pointerH: head
 */

void RokaFree(type_List **pointerH)
{
	type_List *n, *nn, *h;

	if (!pointerH || !*pointerH)
		return;
	h = *pointerH;
	n = h;
	while (n)
	{
		nn = n->next;
		free(n->str);
		free(n);
		n = nn;
	}
	*pointerH = NULL;
}

/**
<<<<<<< HEAD
 * LenList - get the length of the list
=======
 * len_list - get the length of the list
>>>>>>> f40e936485249b1ef01c03dcdff98a5dcca8ebf9
 * @head: head
 * Return: list size
 */

<<<<<<< HEAD
size_t LenList(const type_List *head)
=======
size_t len_list(const type_List *head)
>>>>>>> f40e936485249b1ef01c03dcdff98a5dcca8ebf9
{
	size_t index = 0;

	while (head)
	{
		head = head->next;
		index++;
	}
	return (index);
}

/**
 * RokaObt - obtains node index
 * @h: head
 * @n: node
 * Return: negative one or index
 */

ssize_t RokaObt(type_List *h, type_List *n)
{
	size_t index = 0;

	while (h)
	{
		if (h == n)
			return (index);
		h = h->next;
		index++;
	}
	return (-1);
}

/**
 * freepointer - delete pointers
 * @pointer: pointer
 * Return: zero or one
 */

int freepointer(void **pointer)
{
	if (pointer && *pointer)
	{
		free(*pointer);
		*pointer = NULL;
		return (1);
	}
	return (0);
}
