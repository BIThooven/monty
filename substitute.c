#include "monty.h"
/**
 * sub - a function that subtracts the 2 top element of the stack
 * @head: the pointer to head node
 * @lines: number of the line
 * Return: void returns nothing
*/
void sub(stack_t **head, unsigned int lines)
{
	stack_t *curr;

	curr = NULL;
	if (head == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't sub, stack too short", lines);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	if ((head) == NULL || (*head)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n", lines);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	curr = (*head)->next;

	curr->n = curr->n - curr->prev->n;
	stack_free(*head);
	*head = curr;
	curr->prev = NULL;
}