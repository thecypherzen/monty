#include "monty.h"

/**
 * make_vectr - makes a vector from a string based usiing a delimiter
 * @inputstr: the string
 * @delim: the delimiting string
 * Return: ptr to the vecor on success.
 *         NULL otherwise or if error
 */
char **make_vectr(char *inputstr, char *delim)
{
	char **vectr, *str, *token;
	int n = 0, i, j;

	if (!inputstr || strlen(inputstr) == 0)
		return (NULL);
	str = str_dup(inputstr);

	for (i = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
				n++;
		}
	}
	n += 2;
	vectr = malloc(sizeof(char *) * (n));
	if (!vectr)
		return (NULL);
	vectr[--n] = NULL;
	token = strtok(str, delim);
	if (!token)
	{
		free(vectr), free(str);
		return (NULL);
	}
	for (i = 0; i < n; i++)
	{
		if (!token)
			vectr[i] = NULL;
		else
			vectr[i] = str_dup(token);
		token = strtok(NULL, delim);
	}
	free(str);
	return (vectr);
}
