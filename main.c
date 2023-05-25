#define  _POSIX_C_SOURCE 200809L
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "monty.h"

/**
 * main - monty bytecode interpreter
 * @argc: command line arguments
 * @argv: array of command line arguments
 * Return: exit codes for failure or 0 Success
 */

int main(int argc, char *argv[])
{
	stack_t *top = NULL;
	stack_t *tmp;
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

	while (getline(&lineptr, &length, myfile) != -1)
	{
		line++;
		oper = strtok(lineptr, "\n\t\r ");
		if (oper != NULL && oper[0] != '#')
		{
			call_oper(&top, oper, line);
		}
	}
	if (lineptr != NULL)
		free(lineptr);

	while (top != NULL)
	{
		tmp = top->next;
		free(top);
		top = tmp;
	}

	fclose(myfile);

	exit(EXIT_SUCCESS);
}
