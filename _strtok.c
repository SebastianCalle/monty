#include "monty.h"
/**
 * _strtok - split the string in tokens
 * @buffer: string to split
 * @n: Number of arguments
 * Return: A multidimensional array
 */
char **_strtok(char *buffer, int *n)
{
	char **args = NULL;
	int a = 0, cl = 0, k = 0, in = 0, j = 0;
	int index = 0, i = 0;

	if (buffer[0] ==  '\n')
		return (NULL);
	a = count_arg(buffer);
	args = _calloc(a + 1, sizeof(char *));
	if (args == NULL)
		return (NULL);
	args[a] = NULL;
	for (j = *n; j < a; j++)
	{
		cl = count_letters(buffer, &index, &i);
		if (cl == 0)
			continue;
		args[j] = malloc(sizeof(char) * (cl + 1));
		if (args[j] == NULL)
			return (NULL);
		k = 0;
		in = index;
		while (k < cl)
		{
			if (buffer[in] == '\n')
				break;
			args[j][k] = buffer[in];
			k++;
			in++;
		}
		args[j][k] = '\0';
	}
	*n = j;
	return (args);
}
