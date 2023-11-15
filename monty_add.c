#include "monty.h"

/**
 * monty_add - adds the top two elements of the stack.
 * Usage: add
 * If the stack contains less than two elements, print the error message
 * L<line_number>: can't add, stack too short, followed by a new line, and
 * exit with the status EXIT_FAILURE
 * @stack: address of stack head ptr
 * @lineno: current line number of function call
 * Description: The result is stored in the second top element of the
 * stack, and the top element is removed, so that at the end:
 *		The top element of the stack contains the result
 *		The stack is one element shorter
 * Return: void
 */
void monty_add(stack_t **stack, u_int lineno)
{
	printf("monty_add called on line %u\n", lineno);
	(void)stack;
}