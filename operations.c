#include "monty.h"
#include <string.h>

/**
  * operations - searches for opcode in struct and executes it
  * @tokens: pointer to elements of line fro file
  * @heads: pointer to global stack
  * @line_number: curren line number from file being interpreted
  * Return: void
  */

void operations(char **tokens, stack_t **heads, int line_number)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}
	};
	int i, x = 0;

	if (tokens[0] == NULL)
		return;
	if (tokens[0][0] == '#')
	{
		ops[10].f(NULL, 0);
		return;
	}
	for (i = 0; ops[i].opcode != NULL; i++)
	{
		if (strcmp(ops[i].opcode, tokens[0]) == 0)
		{
			if (strcmp(tokens[0], "push") == 0)
			{
				x = atoi(tokens[1]);
				if (isint(tokens[1]) == 0)
				{
					fprintf(stderr, "L%d: usage: push integer", line_number);
					exit_function();
				}
			}
			else
				x = line_number;
			ops[i].f(heads, x);
			break;
		}
	}
	if (ops[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s", line_number, tokens[0]);
		exit_function();
	}
}

