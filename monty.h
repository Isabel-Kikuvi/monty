#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

#define  _POSIX_C_SOURCE 200809L

#define STACK 0
#define QUEUE 1

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct var_s - main variables of Monty interpreter
 * @len_queue: flag 0 stack, 1 queue
 * @len_stack: len of stack
 */
typedef struct var_s
{
	int len_queue;
	size_t len_stack;
} var_t;

extern var_t var;

int _isdigit(char *str);
stack_t *add_node(stack_t **stack, const int n);
void free_stack(int stat, void *arg);
void free_lineptr(int stat, void *arg);
void close_myfile(int stat, void *arg);
void call_oper(stack_t **stack, char *oper, unsigned int line);
void _pall(stack_t **stack, unsigned int line);
void _push(stack_t **stack, unsigned int line);
void _pop(stack_t **stack, unsigned int line);
void _pint(stack_t **stack, unsigned int line);
void _swap(stack_t **stack, unsigned int line __attribute__ ((unused)));
void _add(stack_t **stack, unsigned int line);
void _nop(stack_t **stack __attribute__ ((unused)), unsigned int line);
void _sub(stack_t **stack, unsigned int line)
#endif
