#include "monty.h"

/**
 * _pop - removes top element of a stack
 * @stack: pointer to top of stack
 * @line: current file line num calling instruction
 */

void _pop(stack_t **stack, unsigned int line)
{
	stack_t *pop = *stack;
	if (var.len_stack == 0)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->prev = (*stack)->prev;
	(*stack)->prev->next = (*stack)->next;
	if (var.len_stack != 1)
		*stack = (*stack)->next;
	else
		*stack = NULL;
	free(pop);
	var.len_stack--;
}
