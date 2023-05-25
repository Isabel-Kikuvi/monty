#include "monty.h"

/**
 * _isdigit - checks if string is digits
 * @str: string to check for digits
 * Return: 0 if only digit, 1 if not digit
 */

int _isdigit(char *str)
{
	int a;

	for (a = 0; str[a]; a++)
	{
		if (str[a] == '-' && a == 0)
		continue;
		if (isdigit(str[a]) == 0)
		return (1);
	}
	return (0);
}
