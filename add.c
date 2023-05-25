#include "monty.h"

/**
 * _add - adds top two elements of a stack
 * @stack: pointer to the top of a stack
 * @line: current file line num calling instructions
 */
void _add(stack_t **stack, unsigned int line)
{
	int n = 0;
	if (var.len_stack < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	n += (*stack)->n;
	_pop(stack, line);
	(*stack)->n += n;
}
