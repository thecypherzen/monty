#include "monty.h"

void monty_pall(stack_t **stack, u_int lineno)
{
	stack_t *temp;

	printf("\nmonty_pall called on line %u\n", lineno);
	temp = *stack;
	if (temp)
	{
		while (temp)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
	}
	else
		printf("[stack empty]\n");
}