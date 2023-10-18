#include "monty.h"
/**
 * pint - function that prints values at stack
 * @head: pointer to the head
 * @lines: number of lines
 * Return: void returns nothing
*/
void pint(stack_t **head, unsigned int lines)
{
	if (head == NULL || *head == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", lines);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
