#include "monty.h"

/**
 * monty_rotl - rotates the stack to the top.
 * Usage: rotl
 * The top element of the stack becomes the last one, and the second top
 * element of the stack becomes the first one
 * rotl never fails
 * @stack: address of stack ptr
 * @lineno: line number of current operation
 * Return: void
 */
void monty_rotl(stack_t **stack, u_int lineno)
{
	stack_t *head = *stack, *temp;

	if (!head)
		return;
	if (head->next)
	{
		temp = *stack, head = head->next;
		while (temp->next)
			temp = temp->next;

		temp->next = head->prev;
		head->prev->prev = temp;
		head->prev->next = NULL;
		head->prev = NULL;
		*stack = head;
	}
	(void)lineno;
}
