#include "monty.h"
/**
 * rm_newline_char - removes trailing newline in a strind
 * if there is.
 * @cmd: the command
 * Return: void
 */
void rm_newline_char(char **cmd)
{
	size_t len;

	if (*cmd)
	{
		len = strlen(*cmd);
		if ((*cmd)[len - 1] == '\n')
			(*cmd)[len - 1] = '\0';
	}
}
