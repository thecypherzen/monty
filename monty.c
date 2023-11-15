#include "monty.h"
/**
 * main - Entry point of mmonty
 * @argsc: cmd line arguments count
 * @argsv: cmd line arguments vector
 * Return: EXIT_SUCCESS on success EXIT_FAILURE on failure
 */
int main(int argsc, char **argsv)
{
	int op_mode = STACK, fd, ret;
	stack_t *mstack = NULL;
	extern monty_t mdata;
	u_int lineno = 0;

	if (argsc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = open(argsv[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argsv[1]);
		exit(EXIT_FAILURE);
	}
	mdata.fd = fd, mdata.opmode = &op_mode, mdata.stack_n = NULL;
	mdata.lineno = &lineno, mdata.stack = &mstack;
	ret = monty_mgr(&mdata);

	close(fd), free_stack(mstack);
	if (ret == EOF)
		printf("\n");
	else if (errno == SIGSEGV)
		fprintf(stderr, "Error: malloc failed\n");
	return (ret);
}
