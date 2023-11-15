#include "monty.h"

/**
 * monty_pall - prints all elements on stack
 * @stack: address of stack ptr
 * @lineno: line number of current operation
 * Return: void
 */
void monty_pall(stack_t **stack, u_int lineno)
{
	stack_t *temp;

	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
