#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: ptr to the top of the stack
 * @line_number: the line number of the command being execute
 * Return: void
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newl;

	if (!stack)
		return;

	newl = malloc(sizeof(stack_t));

	if (newl == NULL)
	{
		fprintf(stderr, "ERROR: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newl->n = line_number;
	newl->prev = NULL;
	newl->next = *stack;

	if (newl->next != NULL)
		(newl->next)->prev = newl;

	*stack = newl;
}



/**
 * pall - prints all the values on the stack,
 * starting from the top of the stack
 * @stack: ptr to the top of the stack
 * @line_number: the line number of the command being execute
 * Return: void
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	(void) line_number;
	if (head == NULL)
		return;
	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}

}

/**
 * pint - prints the value at the top of the stack, followed by a new line
 * @stack: ptr to the top of the stack
 * @line_number: the line number of the command being execute
 * Return: nothing, void
 */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	(void) line_number;

	if (head == NULL)
		exit_function(5);
	printf("%d\n", head->n);
}

