#include "monty.h"

/**
 * monty_sub - subtracts the top element of the stack from the second top
 * element of the stack..
 * Usage: sub
 * If the stack contains less than two elements, print the error message
 * L<line_number>: can't sub, stack too short, followed by a new line, and
 * exit with the status EXIT_FAILURE
 * @stack: stack head ptr address
 * @lineno: line number of current op
 * Return: void
 */
void monty_sub(stack_t **stack, u_int lineno)
{
	size_t len;
	int fnum;

	len = get_stacklen(*stack);
	if (len < 2)
	{
		errno = EXIT_FAILURE;
		fprintf(stderr, "L%u: can't sub, stack too short\n", lineno);
		return;
	}
	fnum = (*stack)->n, monty_pop(stack, lineno);
	(*stack)->n = (*stack)->n - fnum;
}
