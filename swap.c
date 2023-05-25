#include "monty.h"

/**
 * _swap - swaps the top two elements of a stack
 * @stack: pointer to top of stack
 * @line: current file line num calling instructions
 */

void _swap(stack_t **stack, unsigned int line __attribute__ ((unused)))
{
	stack_t *temp;
	if (var.len_stack < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	if (var.len_stack == 2)
	{
		*stack = (*stack)->next;
		return;
	}
	temp = (*stack)->next;
	temp->prev = (*stack)->prev;
	(*stack)->prev->next = temp;
	(*stack)->prev = temp;
	(*stack)->next = temp->next;
	temp->next->prev = *stack;
	temp->next = *stack;
	*stack = temp;
}
