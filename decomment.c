#include "monty.h"
/**
 * decomment - replaces the trailing newline from fd_getline
 * and truncates comments from cmd if there is.
 * @cmd: the command
 * Return: void
 */
void decomment(char **cmd)
{
	size_t len, i;

	if (*cmd)
	{
		len = strlen(*cmd);
		(*cmd)[len - 1] = '\0';

		for (i = 0; *cmd[i] == ' ' || (*cmd)[i] == '\t'; i++)
			;
		if ((*cmd)[i] == '#')
			(*cmd)[i] = '\0';
	}
}
