#include "monty.h"

/**
 * monty_pint - prints the value at the top of the stack,
 * followed by a new line.
 * Usage: pint
 * If the stack is empty, print the error message L<line_number>: can't
 * pint, stack empty, followed by a new line, and exit with the status
 * EXIT_FAILURE
 * @stack: address of stack head ptr
 * @lineno: current line number of function call
 * Return: void
 */
void monty_pint(stack_t **stack, u_int lineno)
{
	printf("monty_pint called on line %u\n", lineno);
	if (*stack)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n",
					lineno);
		errno = EXIT_FAILURE;
	}
}