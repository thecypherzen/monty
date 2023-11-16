#include "monty.h"

/**
 * monty_exec_mgr - manages execution of an opcode
 * @ivectr: vector of command line
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE otherwise
 */
int monty_exec_mgr(char **ivectr)
{
	mf_type ifunc = NULL;
	int ret, n;
	stack_t **stack_h = mdata.stack;

	if (strcmp(ivectr[0], "nop") == 0)
		return (EXIT_SUCCESS);
	if (strcmp(ivectr[0], "queue") == 0)
	{
		*mdata.opmode = QUEUE;
		return (EXIT_SUCCESS);
	}
	if (strcmp(ivectr[0], "stack") == 0)
	{
		*mdata.opmode = STACK;
		return (EXIT_SUCCESS);
	}
	ifunc = get_mfunc(ivectr[0]);
	if (!ifunc)
	{
		fprintf(stderr, "L%d unknown instruction %s\n",
				*mdata.lineno, ivectr[0]);
		return (EXIT_FAILURE);
	}
	ret = is_int(ivectr[1], &n);
	if (ret)
		mdata.stack_n = &n;
	else
		mdata.stack_n = NULL;
	if (ivectr[1] && !ret)
		errno = ENOTINT;
	ifunc(stack_h, *mdata.lineno);
	return (errno  == EXIT_FAILURE ? EXIT_FAILURE : EXIT_SUCCESS);
}
