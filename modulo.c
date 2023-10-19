#include "monty.h"
/**
 * modulo - a function that calculates division of top elements
 * @head: pointer to the stack
 * @lines: the line number
 * Return: void returns nothing
*/
void modulo(stack_t **head, unsigned int lines)
{
	stack_t *curr;

	curr = NULL;
	if ((*head) == NULL || (*head)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't mod, stack too short\n", lines);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	curr = (*head)->next;
	if ((*head)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", lines);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}

	curr->n = curr->n % curr->prev->n;
	stack_free(*head);
	*head = curr;
	curr->prev = NULL;
}
