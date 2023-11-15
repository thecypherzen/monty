#include "monty.h"

/**
 * get_stacklen - gets the length of the monty stack
 * @stack: ptr to stack head
 * Return: the length of stack.
 */
size_t get_stacklen(stack_t *stack)
{
	size_t len = 0;
	stack_t *temp;

	if (!stack)
		return (len);
	temp = stack;
	while (temp)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}
