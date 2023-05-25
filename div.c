#include "monty.h"

/**
 * _div - divides the 2nd top by top element of stack
 * @stack: pointer to the top of the stack
 * @line: line num calling instructions
 */
void _div(stack_t **stack, unsigned int line)
{
	int n;
	if (var.len_stack < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	_pop(stack, line);
	if (n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line);
		exit(EXIT_FAILURE);
	}
	(*stack)->n /= n;
}
