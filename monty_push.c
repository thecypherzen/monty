#include "monty.h"

void monty_push(stack_t **stack, u_int lineno)
{
	extern monty_t mdata;
	int *num = mdata.stack_n;
	stack_t *temp, *new_node;

	printf("monty_push called on line %u\n", lineno);
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
			printf("in stack mode\n");
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
