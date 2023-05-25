#include "monty.h"

var_t var;

/**
 * main - monty bytecode interpreter
 * @argc: command line arguments
 * @argv: array of command line arguments
 * Return: exit codes for failure or 0 Success
 */

int main(int argc, char *argv[])
{
	stack_t **top = NULL;
	unsigned int line = 0;
	FILE *myfile = NULL;
	char *lineptr = NULL, *oper = NULL;
	size_t length = 0;

	var.len_queue = 0;
	var.len_stack = 0;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	myfile = fopen(argv[1], "r");
	if (myfile == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	on_exit(free_lineptr, &lineptr);
	on_exit(free_stack, &top);
	on_exit(close_myfile, myfile);

	while (getline(&lineptr, &length, myfile) != -1)
	{
		line++;
		oper = strtok(lineptr, "\n\t\r ");
	if (oper != NULL && oper[0] != '#')
	{
		call_oper(&top, oper, line);
	}
	}
	exit(EXIT_SUCCESS);
	}
