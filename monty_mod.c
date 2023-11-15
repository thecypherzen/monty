#include "monty.h"

/**
 * monty_mod - computes the modulo of the division of the second top element
 * of the stack by the top element of the stack.
 * Usage: mod
 * If the stack contains less than two elements, print the error message
 * L<line_number>: can't mod, stack too short, followed by a new line, and
 * exit with the status EXIT_FAILURE
 *
 * If the top element of the stack is 0, print the error message
 * L<line_number>: division by zero, followed by a new line, and exit with
 * the status EXIT_FAILURE
 * @stack: address of stack ptr
 * @lineno: line number of current operation
 * Return: void
 */
void monty_mod(stack_t **stack, u_int lineno)
{
	size_t len;
	int fnum;

	len = get_stacklen(*stack);
	if (len < 2)
	{
		errno = EXIT_FAILURE;
		fprintf(stderr, "L%u: can't div, stack too short\n", lineno);
		return;
	}
	fnum = (*stack)->n;
	if (!fnum)
	{
		errno = EXIT_FAILURE;
		fprintf(stderr, "L%u: division by zero\n", lineno);
		return;
	}
	monty_pop(stack, lineno);
	(*stack)->n = (*stack)->n % fnum;
}
