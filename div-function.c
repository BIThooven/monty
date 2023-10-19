#include "monty.h"
/**
 * _div - divide the second top element of the stack by top element
 * @head: pointer to the stack
 * @lines: number of the line
 * Return: void returns nothing
*/
void _div(stack_t **head, unsigned int lines)
{
	stack_t *curr;

	curr = NULL;
	if (head == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't div, stack too short\n", lines);
		exit(EXIT_FAILURE);
	}

	if ((*head) == NULL || (*head)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't div, stack too short\n", lines);
		exit(EXIT_FAILURE);
	}
	curr = (*head)->next;

	if ((*head)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", lines);
		exit(EXIT_FAILURE);
	}
	curr->n = curr->n / curr->prev->n;
	stack_free(*head);
	(*head) = curr;
	curr->prev = NULL;
}
