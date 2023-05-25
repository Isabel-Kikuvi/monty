#include "monty.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/**
 * _pchar - prints the char at top of a stack
 * @stack: pointer to the top of stack
 * @line: line numb calling instructions
 */
void _pchar(stack_t **stack, unsigned int line)
{
	int ch;
	if (var.len_stack < 1)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	ch = (*stack)->n;
	if (!isascii(ch))
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", ch);
}
