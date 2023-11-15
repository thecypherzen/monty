#include "monty.h"

/**
 * monty_rotr - rotates the stack to the bottom.
 * Usage: rotr
 * The last element of the stack becomes the top element of the stack
 * rotr never fails
 * @stack: address of stack ptr
 * @lineno: line number of current operation
 * Return: void
 */
void monty_rotr(stack_t **stack, u_int lineno)
{
	stack_t *temp = *stack, *head;

	if (!temp)
		return;
	if (temp->next)
	{
		head = *stack;
		while (head->next)
			head = head->next;

		head->prev->next = NULL;
		temp->prev = head;
		head->next = temp;
		head->prev = NULL;
		*stack = head;
	}
	(void)lineno;
}
