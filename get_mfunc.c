#include "monty.h"

/**
 * get_mfunc - fetches the function corresponding to an operation
 * @opcode: the operation code
 * Return: ptr to opcode function if found, NULL otherwise.
 */
mf_type get_mfunc(char *opcode)
{
	instruction_t builtins[] = {
		{"push", monty_push}, {"pall", monty_pall}, {"pint", monty_pint},
		{"pop", monty_pop}, {"swap", monty_swap}, {"add", monty_add},
		{"sub", monty_sub}, {"div", monty_div}, {"mul", monty_mul},
		{"mod", monty_mod}, {"pchar", monty_pchar}, {"pstr", monty_pstr},
		{"rotr", monty_rotr}, {"rotl", monty_rotl}, {NULL, NULL}
	};
	size_t i, match = 0;

	for (i = 0; builtins[i].opcode; i++)
	{
		if (strcmp(opcode, builtins[i].opcode) == 0)
		{
			match = 1;
			break;
		}
	}
	return (match ? builtins[i].f : NULL);
}
