#include "monty.h"

/**
 * monty_exec_mgr - manages execution of an opcode
 * @ivectr: vector of command line
 * @mdata: ptr to monty_data structure
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE otherwise
 */
int monty_exec_mgr(char **ivectr, monty_t *mdata)
{
	mf_type ifunc = NULL;
	int ret, n;
	stack_t **stack_h = (mdata->stack);

	if (strcmp(ivectr[0], "nop") == 0)
		;
	else if (strcmp(ivectr[0], "queue") == 0)
		*mdata->opmode = QUEUE;
	else if (strcmp(ivectr[0], "stack") == 0)
		*mdata->opmode = STACK;
	else
	{
		ifunc = get_mfunc(ivectr[0]);
		if (!ifunc)
		{
			fprintf(stderr, "L%d unknown instruction %s\n",
					*mdata->lineno, ivectr[0]);
			return (EXIT_FAILURE);
		}
		ret = is_int(ivectr[1], &n);
		if (ret)
			mdata->stack_n = &n;
		else
			mdata->stack_n = NULL;
		/*printf("ret = %d\n", ret);*/
		if (ivectr[1] && !ret)
			errno = ENOTINT;
		/*printf("mdata.stack_n = %d\n", mdata->stack_n ?
			*mdata->stack_n : -99); */
		ifunc(stack_h, *mdata->lineno);
	}
	/*printf("op %s exec done\n\n", ivectr[0]);*/
	return (errno  == EXIT_FAILURE ? errno : EXIT_SUCCESS);
}
