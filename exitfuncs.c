#include "monty.h"

/**
 * exit_function - handles errors and frees memory before exiting
 * Return: void
 */

void exit_function(void)
{
	free_list(mystack);
	exit(EXIT_FAILURE);
}

/**
 * free_list - free a stack_t list
 * @head: head of list to free
 * Return: void
 */

void free_list(stack_t *head)
{
	if (head != NULL)
	{
		if (head->next != NULL)
			free_list(head->next);
		free(head);
	}
}

