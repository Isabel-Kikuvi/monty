#include "monty.h"

/**
 * pchar - prints the char at the top of the stack
 * @stack: pointer to the top of stack
 * @line: line num calling instructions
 */

void _ pchar(stack_t **stack, unsigned int line)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
		exit(EXIT_FAILURE);
		return;
	}
	if (is_ascii((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
		exit(EXIT_FAILURE);
		return;
	}
	printf("%c\n", (*stack)->n);
}
