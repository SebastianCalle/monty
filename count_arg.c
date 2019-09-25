#include "monty.h"
/**
 * check_del - verify if char is a delimiter
 * @c: first character
 * @b: character before
 * Return: 1 if match 0 if not
 */
int check_del(char c, char b)
{
	int i;
	const char *del = ": \t\r\a\0";

	for (i = 0; del[i]; i++)
	{
		if (del[i] == b)
			return (0);
		if (del[i] == c)
			return (1);
	}
	return (0);
}
/**
 * check_flag - check until the character be a letter
 * @str: character to verificate
 * @index: index parameter
 * @i: count parameter
 * @c: count letter
 * Return: 1 if  suscces or 0 if not
 */
int check_flag(char str, int *index, int *i, int *c)
{

	if ((str > 32 && str < 126) || str == 12)
	{
		*index = *i;
		if (*i > 0)
			*c += 1;
		return (1);
	}
	else
		*i += 1;
	return (0);
}
/**
 * count_letters - count the size of each argument
 * @str: string argument * @index: index of string
 * @index: index parameter
 * @l: last parameter
 * Return: the size of each argument
 */
int count_letters(char *str, int *index, int *l)
{
	int c = 0, flag = 0, flag2, j, i;
	const char *del = ": \t\r\a\0";

	i = *l;
cont:
	while (str[i])
	{
		if (flag == 0)
		{
			flag2 = check_flag(str[i], &(*index), &i, &c);
			if (flag2 == 0)
				goto cont;
			flag = 1;
		}
		j = 0;
		while (del[j])
		{
			if (i > 0)
			{
				if (str[i - 1] == del[j])
				{
					i++;
					*l = i;
					goto cont;
				}

			}
			if (str[i] == del[j])
			{
				i++;
				*l = i;
				return (c);
			}
			j++;
		}
		c++;
		i++;
		*l = i;
	}
	return (c);
}
/**
 * count_arg - count number of arguments
 * @str: strint to count
 * Return: number of arguments
 */
int count_arg(char *str)
{
	int i = 0, c = 0;

	for (i = 0; str[i]; i++)
	{
		if (i == 0)
		{
			c += check_del(str[i], str[i]);
			continue;

		}
		c += check_del(str[i], str[i - 1]);
	}
	if (str[i] == '\0')
	{
		if ((str[i - 1] > 32 && str[i - 1] < 126) || str[i - 1] == '\n')
			c++;
	}
	return (c);
}
