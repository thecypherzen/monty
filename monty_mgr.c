#include "monty.h"

/**
 * monty_mgr - manages monty_interpreter sequence of operations
 * Return: on success, EXIT_SUCCESS, EXIT_FAILURE otherwise.
 */
int monty_mgr(void)
{
	ssize_t ret, fret = EXIT_SUCCESS;
	char *iline = NULL, **ivectr = NULL;
	size_t sz = 0;

	while (1)
	{
		errno = EXIT_SUCCESS, ret = fd_getline(&iline, &sz, mdata.fd);
		if (ret > 0)
		{
			*mdata.lineno = *mdata.lineno + 1;
			rm_newline_char(&iline);
			ivectr = make_vectr(iline, " \t");
			if (ivectr)
			{
				if (ivectr[0][0] != '#')
					fret = monty_exec_mgr(ivectr);
				free_vectr(ivectr);
				if (fret != EXIT_SUCCESS)
					break;
			}
			else if (errno)
			{
				errno = SIGSEGV, fret = EXIT_FAILURE;
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
