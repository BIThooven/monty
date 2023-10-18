#include "monty.h"
/**
 * push - function to push elements to the stack
 * @head: pointer to the head node
 * @linenum: number of lines
 * Return: void returns nothing
*/
void push(stack_t **head, unsigned int linenum)
{
	if (_isdigit(configs.numbers) == 1)
	{
		if (configs.mode == 1)
		{
			add_nodeint(head, atoi(configs.numbers));
		}
		else if (configs.mode == 0)
		{
			if (*head == NULL || head == NULL)
			{
				add_nodeint(head, atoi(configs.numbers));
			}
			else
			{
				add_nodeint_end(head, atoi(configs.numbers));
			}
		}
	}
	else
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", linenum);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
}
