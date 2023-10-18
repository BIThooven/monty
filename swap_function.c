#include "monty.h"
/**
 * swap - function that swaps elements in the stack
 * @head: the head pointer on the stack
 * @lines: number of the line
 * Return: void returns nothing
*/
void swap(stack_t **head, unsigned int lines)
{
	stack_t *thelist;
	int temp, length;

	length = lengthofstack(*head);
	thelist = *head;
	if (length < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", lines);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	temp = thelist->n;
	thelist->n = thelist->next->n;
	thelist->next->n = temp;
}
