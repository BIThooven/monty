#include "monty.h"
/**
 * add_nodeint_end - function that adds a node at the end
 * @head: pointer to the head node
 * @n: integer to be added
 * Return: void returns nothing
*/
void add_nodeint_end(stack_t **head, const int n)
{
	stack_t *thelist;
	stack_t *new;

	thelist = *head;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		stack_free(new);
		dprintf(STDERR_FILENO, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
	}
	while (thelist->next != NULL)
	{
		thelist = thelist->next;
	}
	thelist->next = new;
	new->prev = thelist;
}
/**
 * stack_free - function that clean the stack
 * @h: pointer to the head of the stack
 * Return: Nothing it is a void function
 */
void stack_free(stack_t *h)
{
	stack_t *next;

	while (h != NULL)
	{
		next = h->next;
		free(h);
		h = next;
	}
	fclose(configs.fname);
	free(configs.buff);
}
/**
 * add_nodeint - function that adds new node
 * @h: pointer to the head node
 * @n: int to be added
 * Return: void returns nothing
*/
void add_nodeint(stack_t **h, const int n)
{
	stack_t *_new;

	_new = malloc(sizeof(stack_t));
	if (_new == NULL)
	{
		stack_free(_new);
		dprintf(STDERR_FILENO, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	_new->n = n;
	_new->prev = NULL;
	_new->next = *h;

	if (*h != NULL)
	{
		(*h)->prev = _new;
	}
	*h = _new;
}
/**
 * del_nodeint_end - a function that deletes the node at the end
 * @h: pointer to the head node
 * @n: the index
 * Return: void returns nothing
*/
void del_nodeint_end(stack_t **h, unsigned int n)
{
	stack_t *thelist;
	size_t i;

	thelist = *h;
	if (*h == NULL || h == NULL)
	{
		return;
	}
	for (i = 0; thelist != NULL; i++)
	{
		if (i == n)
		{
			if (thelist->prev)
			{
				thelist->prev->next = thelist->next;
			}
			if (thelist->next)
			{
				thelist->next->prev = thelist->prev;
			}
			if (*h == thelist)
				*h = thelist->next;
			free(thelist);
			return;
		}
		thelist = thelist->next;
	}
}
