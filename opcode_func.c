#include "monty.h"
/**
 * opcode_func - function to check and execute and opcode
 * @head: pointer to the head
 * @lines: number of the line
 * @opt: opcode to read
 * Return: void returns nothing
*/
void opcode_func(int lines, char *opt, stack_t **head)
{
	instruction_t cmd[] = {
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		{"pint", pint},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
	};
	int i;

	i = 0;
	for (; cmd[i].opcode; i++)
	{
		if (strcmp(cmd[i].opcode, opt) == 0)
		{
			cmd[i].f(head, lines);
			break;
		}
	}
	if (cmd[i].opcode == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: unknown instruction %s", lines, opt);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
}
