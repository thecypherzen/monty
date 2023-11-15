#include "monty.h"

/**
 * monty_sub - subtracts the top element of the stack from the second top
 * element of the stack..
 * Usage: sub
 * If the stack contains less than two elements, print the error message
 * L<line_number>: can't sub, stack too short, followed by a new line, and
 * exit with the status EXIT_FAILURE
 * Return: void
 */
void monty_sub(stack_t **stack, u_int lineno)
{
	printf("monty_sub called on line %u\n", lineno);
	(void)stack;
}