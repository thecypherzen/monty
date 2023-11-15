#include "monty.h"

/**
 * _fd_getline_helper - a helper function of fd_getline.
 * - copies from buffer to line ptr.
 * @buff: address of ptr to buffer  - source
 * @line: copy destination
 * @line_sz: size of destination buffer
 * Return: void
 */
ssize_t _fd_getline_helper(char **buff, char **line, size_t *line_sz)
{
	size_t i;

	for (i = 0; (*buff)[i]; i++)
	{
		(*line)[i] = (*buff)[i];
		if (i == *line_sz - 1)
		{
			*line_sz += 120;
			*line = realloc(*line, *line_sz);
			if (!(*line))
			{
				fprintf(stderr, "malloc failed\n");
				return (-1);
			}
		}
	}
	(*line)[i] = '\0';
	return (0);
}
