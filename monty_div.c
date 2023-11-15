#include "monty.h"

/**
 * monty_div - divides the second top element of the stack by the top element of the stack.
 * Usage: sub
 * If the stack contains less than two elements, print the error message
 * L<line_number>: can't div, stack too short, followed by a new line, and
 * exit with the status EXIT_FAILURE
 *
 * If the top element of the stack is 0, print the error message
 * L<line_number>: division by zero, followed by a new line, and exit with
 * the status EXIT_FAILURE
 * Return: void
 */
void monty_div(stack_t **stack, u_int lineno)
{
	printf("monty_div called on line %u\n", lineno);
	(void)stack;
}