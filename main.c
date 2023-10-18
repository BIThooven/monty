#include "monty.h"
config configs = {NULL, NULL, NULL, NULL, 1};
/**
 * main - program that interprets bytcodes , execute opcodes
 * @argc: arguments to be passed
 * @argv: arguments passed to the script
 * Return: 0 if success and 1 if failure
*/
int main(int argc, char *argv[])
{
	stack_t *h;
	size_t buffer_size;
	ssize_t chars;
	unsigned int line;

	line = 1;
	h = NULL;
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	configs.fname = fopen(argv[1], "r");

	if (configs.fname == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((chars = getline(&configs.buff, &buffer_size, configs.fname)) != EOF)
	{
		split(configs.buff, DELIM);
		if (configs.opc != NULL && configs.opc[0] != '#')
		{
			opcode_func(line, configs.opc, &h);
		}
		line++;
	}
	stack_free(h);
	return (0);
}
