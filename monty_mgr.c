#include "monty.h"

/**
 * monty_mgr - manages monty_interpreter sequence of operations
 * Return: on success, EXIT_SUCCESS, EXIT_FAILURE otherwise.
 */
int monty_mgr(void)
{
	ssize_t ret, fret = 0;
	char *iline = NULL, **ivectr = NULL;
	size_t sz = 0;

	while (1)
	{
		errno = EXIT_SUCCESS;
		ret = fd_getline(&iline, &sz, mdata.fd);
		if (ret > 0)
		{
			iline[ret - 1] = '\0';
			*mdata.lineno = *mdata.lineno + 1;
			if (strlen(iline) > 0)
			{
				ivectr = make_vectr(iline, " ");
				if (!ivectr)
				{
					errno = SIGSEGV, fret = EXIT_FAILURE;
					break;
				}
				if (ivectr[0][0] != '#')
					fret = monty_exec_mgr(ivectr);
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
	free(iline);
	return (fret);
}
