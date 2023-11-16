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

	printf("decommenting %s\n", *cmd);
	if (*cmd)
	{
		len = strlen(*cmd);
		printf("len: %lu\n", len);
		(*cmd)[len - 1] = '\0';

		for (i = 0; ((*cmd)[i] == ' ' || (*cmd)[i] == '\t')
									&& (*cmd)[i]; i++)
			;
		printf("i == %lu, val: %c\n", i, (*cmd)[i]);
		if ((*cmd)[i] == '#')
			(*cmd)[i] = '\0';
	}
}
