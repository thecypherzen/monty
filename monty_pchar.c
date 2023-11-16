#include "monty.h"

/**
 * monty_pchar - prints the char at the top of the stack, followed
 * by a new line.
 * Usage: pchar
 * The integer stored at the top of the stack is treated as the ascii value
 * of the character to be printed
 *
 * If the value is not in the ascii table (man ascii) print the error
 * message L<line_number>: can't pchar, value out of range, followed by a
 * new line, and exit with the status EXIT_FAILURE
 *
 * If the stack is empty, print the error message L<line_number>: can't
 * pchar, stack empty, followed by a new line, and exit with the status
 * EXIT_FAILURE
 * @stack: stack head ptr address
 * @lineno: line number of current operation
 * Return: void
 */
void monty_pchar(stack_t **stack, u_int lineno)
{
	size_t len;
	int fnum;

	len = get_stacklen(*stack);
	if (!len)
	{
		errno = EXIT_FAILURE;
		fprintf(stderr, "L%u: can't pchar, stack empty\n", lineno);
		return;
	}
	fnum = (*stack)->n;
	if (fnum < 32 || fnum > 127)
	{
		errno = EXIT_FAILURE;
		fprintf(stderr, "L%u: can't pchar, value out of range\n", lineno);
		return;
	}
	printf("%c\n", fnum);
}
