#include "monty.h"

/**
 * isint - checks if string is a number
 * @s: string of numbers
 * Return: 1 if true, 0 if false
 */

int isint(char s[])
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (isdigit(s[i]) == 0)
			return (0);
	}
	return (1);
}

