#include "monty.h"
/**
 * _isdigit - a function to check if a number is a digit or not
 * @s: string to be checked
 * Return: 1 if true, 0 if false
*/
int _isdigit(char *s)
{
	int i;

	if (!(s))
	{
		return (0);
	}

	i = s[0] == '-' ? 1 : 0;

	for (; s[i] != '\0'; i++)
	{
		if (s[i] < '0' || s[i] > '9')
		{
			return (0);
		}
	}
	return (1);
}
