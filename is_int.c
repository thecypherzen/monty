#include "monty.h"
/**
 * is_int - checks if a string is an int or not
 * if it is an int, it converts it and sets value pointed by num to it
 * else it returns
 * @str: the string
 * @num: the number
 * Return: 1 if a valid int, or 0 otherwise;
 */
int is_int(char *str, int *num)
{
	size_t i;

	if (str)
	{
		for (i = 0; str[i]; i++)
		{
			if (i == 0 && str[i] == '-')
				continue;
			if (str[i] < '0' || str[i] > '9')
				return (0);
		}
		*num = atoi(str);
		return (1);
	}
	return (0);
}
