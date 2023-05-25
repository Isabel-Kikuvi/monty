#include "main.h"

/**
 * _pint - prints the value at top of stack
 * @stack: pointer to the top of the stack
 * @line: current file line number calling instructions
 */

void instruct_pint(stack_t **stack, unsigned int line)
{
	stack_t *head = *stack;
	if (var.len_stack == 0)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", head->n);
}

