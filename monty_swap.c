#include "monty.h"

/**
 * monty_swap - swaps the top two elements of the stack..
 * Usage: pint
 * If the stack contains less than two elements, print the error message
 * L<line_number>: can't swap, stack too short, followed by a new line, and
 * exit with the status EXIT_FAILURE
 * @stack: address of stack head ptr
 * @lineno: current line number of function call
 * Return: void
 */
void monty_swap(stack_t **stack, u_int lineno)
{

	printf("monty_pint called on line %u\n", lineno);
	(void)stack;
}