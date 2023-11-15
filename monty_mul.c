#include "monty.h"

/**
 * monty_mul - multiplies the second top element of the stack with the top
 * element of the stack.
 * Usage: mul
 * If the stack contains less than two elements, print the error message
 * L<line_number>: can't mul, stack too short, followed by a new line, and
 * exit with the status EXIT_FAILURE
 * @stack: address of stack ptr
 * @lineno: line number of current operation
 * Return: void
 */
void monty_mul(stack_t **stack, u_int lineno)
{
	size_t len;
	int fnum;

	len = get_stacklen(*stack);
	if (len < 2)
	{
		errno = EXIT_FAILURE;
		fprintf(stderr, "L%u: can't mul, stack too short\n", lineno);
		return;
	}
	fnum = (*stack)->n, monty_pop(stack, lineno);
	(*stack)->n = (*stack)->n * fnum;
}
