#include "monty.h"

/**
 * _pall - prints all of the data in a stack
 * @top: pointer to the top node of a stack
 * @line: current file line number calling instructions
 */
void _pall(stack_t **top, unsigned int line)
{
	stack_t *temp;
	(void) line;
	temp = *top;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
		if (temp == *top)
			return;
	}
}
