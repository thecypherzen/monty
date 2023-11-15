#include "monty.h"

int monty_mgr(monty_t *mdata)
{
	ssize_t ret, fret = 0;
	char *iline = NULL, **ivectr = NULL;
	size_t sz = 0;

	while (1)
	{
		ret = fd_getline(&iline, &sz, mdata->fd);
		if (ret > 0)
		{
			*mdata->lineno = *mdata->lineno + 1, decomment(&iline);
			if (strlen(iline) > 0)
			{
				/*printf("iline: %s\n", iline);*/
				ivectr = make_vectr(iline, " ");
				if (!ivectr)
				{
					/*printf("vector is null\n");*/
					errno = SIGSEGV, fret = EXIT_FAILURE;
					break;
				}
				fret = monty_exec_mgr(ivectr, mdata);
				free_vectr(ivectr);
				if (fret != 0)
					break;
			}
		}
		else
		{
			if (ret == SIGSEGV)
				fret = EXIT_FAILURE;
			break;
		}
	}
	printf("\n[* monty mgr * ] done executing file\n");
	free(iline);
	return (fret);
}