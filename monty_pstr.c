#include "monty.h"

/**
 * monty_pstr - prints the string starting at the top of the stack,
 * followed by a new line.
 * Usage: pstr
 * The integer stored in each element of the stack is treated as the ascii
 * value of the character to be printed
 *
 * The string stops when either:
 *	- the stack is over
 *	- the value of the element is 0
 * 	- the value of the element is not in the ascii table
 *
 * if the stack is empty, print only a new line
 * Return: void
 */
void monty_pstr(stack_t **stack, u_int lineno)
{
	printf("monty_pstr called on line %u\n", lineno);
	(void)stack;
}