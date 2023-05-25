#include "monty.h"

/**
 * _pall - prints all of the data in a stack
 * @stack: pointer to the top node of a stack
 * @line: current file line number calling instructions
 */
void _pall(stack_t **stack, unsigned int line)
{
	stack_t *temp;
	(void) line;
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
		if (temp == *stack)
			return;
	}
}
