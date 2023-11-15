#include "monty.h"

/**
 * free_vectr - frees a vector of strings from memory
 * @vectr: the vector
 * Return: void
 */
void free_vectr(char **vectr)
{
	int i;

	if (vectr)
	{
		for (i = 0; vectr[i]; i++)
		{
			free(vectr[i]);
		}
		free(vectr);
		vectr = NULL;
	}
}
