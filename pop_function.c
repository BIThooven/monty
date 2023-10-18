#include "monty.h"
/**
 * pop - function that removes elements of a stack
 * @head: pointer to head node of the stack
 * @lines: number of lines
 * Return: void returns nothing
*/
void pop(stack_t **head, unsigned int lines)
{
	stack_t *thelist;

	thelist = *head;
	if (*head == NULL || head == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", lines);
		exit(EXIT_FAILURE);
	}
	(*head) = thelist->next;
	if (thelist->next)
	{
		thelist->next->prev = NULL;
	}
	free(thelist);
}
