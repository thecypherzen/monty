#include "monty.h"

/**
 * monty_pop - removes the top element of the stack.
 * Usage: pint
 * If the stack is empty, print the error message L<line_number>: can't pop
 * an empty stack, followed by a new line, and exit with the status
 * EXIT_FAILURE
 * @stack: address of stack head ptr
 * @lineno: current line number of function call
 * Return: void
 */
void monty_pop(stack_t **stack, u_int lineno)
{
	extern mdata;
	stack_t *temp;

	if (!(*stack))
	{
		errno = EXIT_FAILURE;
		fprintf(stderr, "L%d: can't pop an empty stack", )
	}
	printf("monty_pop called on line %u\n", lineno);
	(void)stack;
}