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
	size_t i, stat = 0;

	if (str)
	{
		for (i = 0; str[i]; i++)
		{
			if (i == 0 && (str[i] == '-' || str[i] == '+'))
				continue;
			if (str[i] < '0' || str[i] > '9')
				return (stat);
		}
		if ((*str == '-' || *str == '+') && strlen(str) == 1)
			return (stat);
		*num = atoi(str);
		stat = 1;
	}
	return (stat);
}
