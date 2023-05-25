#include "monty.h"

/**
 * add_node - add a new node to a linked list
 * @top: double pointer to the beginning of a linked list
 * @n: data value to add to new node
 *
 * Return: pointer to new node, or NULL on failure
 */

stack_t *add_node(stack_t **top, const int n)
{
	stack_t *new_node;

	if (top == NULL)
		return (NULL);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	if (*top == NULL)
	{
		new_node->prev = new_node;
		new_node->next = new_node;
	}
	else
	{
		(*top)->prev->next = new_node;
		new_node->prev = (*top)->prev;
		(*top)->prev = new_node;
		new_node->next = *top;
	}
	if (var.len_queue == STACK || var.len_stack == 0)
		*top = new_node;
	return (new_node);
}

/**
 * free_stack - frees malloced memory
 * @arg: pointer to stack
 * @stat: exit status
 */
void free_stack(int stat, void *arg)
{
	stack_t **top;
	stack_t *tmp;
	(void) stat;
	top = (stack_t **)arg;
	if (*top)
	{
		(*top)->prev->next = NULL;
		(*top)->prev = NULL;
	}
	while (*top != NULL)
	{
		tmp = (*top)->next;
		free(*top);
		*top = tmp;
	}
	var.len_stack = 0;
}

/**
 * free_lineptr - free line pointer
 * @stat: exit status
 * @arg: pointer to line
 */
void free_lineptr(int stat, void *arg)
{
	char **lineptr = arg;
	(void) stat;
	if (*lineptr != NULL)
	free(*lineptr);
}

/**
 * close_myfile - close file stream
 * @stat: status passed to exit
 * @arg: pointer to file stream
 */
void close_myfile(int stat, void *arg)
{
	FILE *myfile;
	(void) stat;
	myfile = (FILE *) arg;
	fclose(myfile);
}
