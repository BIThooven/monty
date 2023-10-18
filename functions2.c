#include "monty.h"
/**
 * get_at_index - function to return the nth node
 * @h: pointer to the head node
 * @n: indexing through nodes
 * Return: returns null if node at nth index does not exist
*/
int get_at_index(stack_t *h, unsigned int n)
{
	size_t i;

	i = 0;
	if (h == NULL)
	{
		return ('\0');
	}
	while (i < n)
	{
		if (h->next == NULL)
		{
			return ('\0');
		}
		h = h->next;
		i++;
	}
	return (h->n);
}
/**
 * lengthofstack - function the returns the length of the stack
 * @head: pointer to the head node
 * Return: the number of nodes
*/
int lengthofstack(stack_t *head)
{
	int elements_nums;
	stack_t *thelist;

	thelist = (stack_t *)head;
	for (elements_nums = 0; thelist != NULL; elements_nums++)
	{
		thelist = thelist->next;
	}
	return (elements_nums);
}
