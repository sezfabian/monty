#include "monty.h"
#define MAX_LENGTH 1000

stack_t *mystack = NULL;

/**
 * main-  main entry point of the monty program
 * @argc: number of input arguments
 * @argv: pointer to arry of char arguments
 * Return: zero if sucessfull
 */

int main(int argc, char **argv)
{
	FILE *fptr;
	char line[MAX_LENGTH];
	struct stat filestat;
	char *token;
	char **tokens = malloc(5 * sizeof(char *));
	int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit_function();
	}
	if (stat(argv[1], &filestat) != 0)
	{
		fprintf(stderr, "ERROR: Can't open file %s\n", argv[1]);
		exit_function();
	}
	fptr = fopen(argv[1], "r");
	while (fgets(line, MAX_LENGTH, fptr))
	{
		int length = 0;

		token = strtok(line, " \n\t$");
		while (token != NULL)
		{
			tokens[length] = token;
			length++;
			token = strtok(NULL, " \n\t$");
		}
		line_number++;
		operations(tokens, &mystack, line_number);
		tokens[0] = NULL, tokens[1] = NULL;
	}
	return (0);
}
