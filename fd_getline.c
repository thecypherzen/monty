#include "monty.h"

/**
 * fd_getline - custom getline that works with file descriptors
 * instead of file streams
 * @line: buffer to which read bytes are stored
 * @sz: size of the buffer
 * @fd: the file descriptor to read from
 * Return: the number of bytes red on success, -1 on failure or
 * end of file.
 */
ssize_t fd_getline(char **line, size_t *sz, int fd)
{
	char *buff;
	size_t buffsz = 128, i;
	ssize_t res, n = 0;

	buff = malloc(buffsz);
	if (!buff)
		return (SIGSEGV);
	if (!(*line) || !(*sz))
		*sz = 120, *line = malloc(*sz);
	if (!(*line))
		return (SIGSEGV);
	i = 0, fflush(stdout);
	while ((res = read(fd, buff + i, 1)) > 0)
	{
		n++, i++;
		if (i == buffsz)
		{
			buffsz += 128, buff = realloc(buff, buffsz);
			if (!buff)
				return (n ? n : SIGSEGV);
		}
		if (buff[i - 1] == '\n')
		{
			buff[i] = '\0';
			break;
		}
	}
	if (res == 0)
		buff[i] = '\0';
	res = _fd_getline_helper(&buff, line, sz);
	free(buff), buff = NULL;
	if (res < 0)
		return (res);
	return (n ? n : -1);
}
