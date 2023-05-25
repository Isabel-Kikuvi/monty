#include "monty.h"

/**
 * _mod - rest of the div of the second top by the top
 * @stack: pointer to the top of stack
 * @line: line num calling instructions
 */
void _mod(stack_t **stack, unsigned int line)
{
	int n;
	if (var.len_stack < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	_pop(stack, line);
	if (n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line);
		exit(EXIT_FAILURE);
	}
	(*stack)->n %= n;
}
