#include "monty.h"
/**
 * pall - function to print values in the stack
 * @head: the head pointer
 * @time: number of current lines
 * Return: void returns nothing
*/
void pall(stack_t **head, unsigned int time)
{
	stack_t *stack = *head;

	(void)time;
	while (stack != NULL)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
	}
}
