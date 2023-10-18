#include "monty.h"
/**
 * split - function to split argumnets of getline
 * @buff: the buffer
 * @delim: delimeters to split
 * Return: void returns nothing
*/
void split(char *buff, char *delim)
{
	configs.opc = strtok(buff, delim);
	configs.numbers = strtok(NULL, delim);
}
