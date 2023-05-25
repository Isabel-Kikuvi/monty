#include "monty.h"

/**
 * call_oper - executes stack instructions called
 * @top: pointer to top node of stack
 * @oper: string cpy of stack
 * @line: current file line num calling the instruction
 */

void call_oper(stack_t **top, char *oper, unsigned int line)
{
int c;
instruction_t all_opers[] = {
{"push", _push},
{"pall", _pall},
{"pint", _pint},
{"pop", _pop},
{"swap", _swap},
{"add", _add},
{"nop", _nop},
{NULL, NULL}
};
for (c = 0; all_opers[c].opcode != NULL; c++)
{
if (strcmp(oper, all_opers[c].opcode) == 0)
{
all_opers[c].f(top, line);
return;
}
}
fprintf(stderr, "L%u: unknown instruction %s\n", line, oper);
exit(EXIT_FAILURE);
}
