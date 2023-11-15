#include "monty.h"

/**
 * monty_rotl - rotates the stack to the top.
 * Usage: rotl
 * The top element of the stack becomes the last one, and the second top
 * element of the stack becomes the first one
 * rotl never fails
 * Return: void
 */
void monty_rotl(stack_t **stack, u_int lineno)
{
	printf("monty_rotl called on line %u\n", lineno);
	(void)stack;
}