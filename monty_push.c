#include "monty.h"

/**
 * monty_push - pushes an integer to the stack or queue, as the
 * case may be.
 * - in stack mode, the structure is LIFO, in queue mode it's FIFO
 * - the integer is stored in the mdata struct
 * - if number is not an int, an error is thrown and errno is set
 *   appropriately.
 * @stack: ptr to stack head address
 * @lineno: line number of current operation
 * Return: void always.
 */
void monty_push(stack_t **stack, u_int lineno)
{
	int *num = mdata.stack_n;
	stack_t *temp, *new_node;

	if (errno == ENOTINT || !num)
	{
		fprintf(stderr, "L%d: usage: push integer\n", lineno);
		errno = EXIT_FAILURE;
		return;
	}
	/*printf("opmode = %s\n", *mdata.opmode == STACK ? "STACK" "QUEUE");*/
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		errno = SIGSEGV;
		return;
	}
	new_node->n = *num;
	if (*stack == NULL)
		new_node->prev = NULL, new_node->next = NULL, *stack = new_node;
	else
	{
		if (*mdata.opmode == STACK)
		{
			new_node->prev = NULL, new_node->next = *stack;
			(*stack)->prev = new_node, *stack = new_node;
		}
		else
		{
			temp = *stack;
			while (temp->next)
				temp = temp->next;
			new_node->next = NULL, new_node->prev = temp;
			temp->next = new_node;
		}
	}
}
