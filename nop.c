#include "monty.h"

/**
 * _nop - doee nothing
 * @stack: pointer to top of a stack
 * @line: line num calling instructions
 */
void _nop(stack_t **stack __attribute__ ((unused)), unsigned int line)
{
	(void) line;
}
