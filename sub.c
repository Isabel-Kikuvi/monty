#include "monty.h"

/**
 * _sub - subtracts the top from the second top-most element
 * @stack: pointer to the top of the  stack
 * @line: line number calling instructions
 */
void _sub(stack_t **stack, unsigned int line)
{
	int n;
	if (var.len_stack < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	_pop(stack, line);
	(*stack)->n -= n;
}
