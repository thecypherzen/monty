#include "monty.h"

int monty_exec_mgr(char **ivectr, monty_t *mdata)
{
	mf_type ifunc = NULL;
	int ret, n;
	stack_t **stack_h = (mdata->stack);

	if (strcmp(ivectr[0], "queue") == 0)
		*mdata->opmode = QUEUE, printf("modeset to %s\n", "[QUEUE]");
	else if (strcmp(ivectr[0], "stack") == 0)
		*mdata->opmode = STACK, printf("modeset to %s\n", "[STACK]");
	else
	{
		/*printf("opmode: %s\n", *mdata->opmode == STACK ?
			"stack" : "queue");*/
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
	printf("\n\n");
	return (errno  == EXIT_FAILURE ? errno : 0);
}
