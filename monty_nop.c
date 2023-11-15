#include "monty.h"

/**
 * monty_nop - doesn’t do anything.
 * Usage: nop
 * Return: void
 */
void monty_nop(stack_t **stack, u_int lineno)
{
	printf("monty_nop called on line %u\n", lineno);
	(void)stack;
}