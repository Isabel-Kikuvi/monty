#include "monty.h"

/**
 * _push - pushes a data to a stack
 * @stack: pointer to top node of a stack
 * @line: current file line num calling instruction
 */
void _push(stack_t **stack, unsigned int line)
{
	char *str;
	int n;

	str = strtok(NULL, "\n\t\r ");
	if (str == NULL || _isdigit(str))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}
	n = atoi(str);

	if (!add_node(stack, n))
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	var.len_stack++;
	}
