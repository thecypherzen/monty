#include "monty.h"

/**
 * monty_pstr - prints the string starting at the top of the stack,
 * followed by a new line.
 * Usage: pstr
 * The integer stored in each element of the stack is treated as the ascii
 * value of the character to be printed
 *
 * The string stops when either:
 *	- the stack is over
 *	- the value of the element is 0
 *	- the value of the element is not in the ascii table
 *
 * if the stack is empty, print only a new line
 * @stack: stack ptr address
 * @lineno: line number of current operation
 * Return: void
 */
void monty_pstr(stack_t **stack, u_int lineno)
{
	int fnum;
	stack_t *temp;

	if (*stack)
	{
		temp = *stack;
		while (temp)
		{
			fnum = temp->n;
			if (fnum <= 0 || fnum > 127)
			{
				break;
			}
			printf("%c", temp->n);
			temp = temp->next;
		}
	}
	printf("\n");
	(void)lineno;
}
