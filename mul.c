#include "monty.h"

/**
 * _mul - multiplies the top 2 elements
 * @stack: pointer to the top of stack
 * @line: line numb calling instructions
 */
void _mul(stack_t **stack, unsigned int line)
{
	int n;
	if (var.len_stack < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	_pop(stack, line);
	(*stack)->n *= n;
}
