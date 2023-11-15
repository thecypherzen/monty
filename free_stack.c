#include "monty.h"

/**
 * free_stack - frees the stack
 * @s_head: ptr to stack head
 * Description: It never fails
 * Return: void
 */
void free_stack(stack_t *s_head)
{
	stack_t *temp;
	size_t fwd;

	if (s_head)
	{
		fwd = !s_head->prev ? 1 : 0;
		if (fwd)
		{
			while (s_head)
			{
				temp = s_head, s_head = s_head->next;
				free(temp);
			}
		}
		else
		{
			while (s_head)
			{
				temp = s_head, s_head = s_head->prev;
				free(temp);
			}
		}
	}
}