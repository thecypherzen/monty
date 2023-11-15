#include "monty.h"

/**
 * monty_mul - multiplies the second top element of the stack with the top
 * element of the stack.
 * Usage: mul
 * If the stack contains less than two elements, print the error message
 * L<line_number>: can't mul, stack too short, followed by a new line, and
 * exit with the status EXIT_FAILURE
 * Return: void
 */
void monty_mul(stack_t **stack, u_int lineno)
{
	printf("monty_mul called on line %u\n", lineno);
	(void)stack;
}