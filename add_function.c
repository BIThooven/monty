#include "monty.h"
/**
 * add - function that add 2 elements to the stack
 * @head: the head pointer
 * @lines: number of the line
 * Return: void returns nothing
*/
void add(stack_t **head, unsigned int lines)
{
	stack_t *thelist;
	int length;

	thelist = *head;
	length = lengthofstack(*head);

	if (length < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", lines);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	thelist->next->n += thelist->n;
	pop(head, lines);
}
