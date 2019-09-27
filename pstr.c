#include "monty.h"

/**
 * pstr - function that prints the string
 * @inst: - node of stack
 * Return: 1 if succes or 0 if not
 */
int pstr(node_t *inst)
{
	stack_t *tmp = inst->head;

	if (tmp == NULL)
	{
		printf("\n");
		return (1);
	}
	while (tmp)
	{
		if (tmp->value <= 0 || tmp->value > 127)
			break;

		printf("%c", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");

	return (1);

}
