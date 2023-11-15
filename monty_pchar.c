#include "monty.h"

/**
 * monty_pchar - prints the char at the top of the stack, followed by a new
 * line.
 * Usage: pchar
 * The integer stored at the top of the stack is treated as the ascii value * of the character to be printed
 *
 * If the value is not in the ascii table (man ascii) print the error
 * message L<line_number>: can't pchar, value out of range, followed by a
 * new line, and exit with the status EXIT_FAILURE
 *
 * If the stack is empty, print the error message L<line_number>: can't
 * pchar, stack empty, followed by a new line, and exit with the status
 * EXIT_FAILURE
 * Return: void
 */
void monty_pchar(stack_t **stack, u_int lineno)
{
	printf("monty_pchar called on line %u\n", lineno);
	(void)stack;
}