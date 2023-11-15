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
	size_t len;
	stack_t *temp;

	len = get_stacklen(*stack);
	if (len < 2)
	{
		errno = EXIT_FAILURE;
		fprintf(stderr, "L%u: can't swap, stack too short\n", lineno);
		return;
	}
	temp = (*stack)->next;
	temp->prev = NULL;
	if (temp->next)
		temp->next->prev = *stack;
	(*stack)->next = temp->next;
	(*stack)->prev = temp;
	temp->next = *stack;
	*stack = temp;
}
