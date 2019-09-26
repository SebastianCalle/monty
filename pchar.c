#include "monty.h"

/**
 * pchar - function that prints the char at the top of the stack
 * @inst: node of the stack
 * Return: 0 if succes or 1 if not
 */
int pchar(node_t *inst)
{
	int num1;


	if (inst->head == NULL || inst->head->next == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", inst->line_num);
		free_all(inst, 1);
	}

	num1 = inst->head->value;

	if (num1 < 0 || num1 > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", inst->line_num);
		free_all(inst, 1);
	}
	printf("%c\n", num1);
	return (1);
}
