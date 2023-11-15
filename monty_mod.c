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
 * Return: void
 */
void monty_mod(stack_t **stack, u_int lineno)
{
	printf("monty_mod called on line %u\n", lineno);
	(void)stack;
}