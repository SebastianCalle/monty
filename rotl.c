#include "monty.h"

/**
 * rotl - rotathes the stack to the top
 * @inst: node the stack
 * Return: 1 if is succes or 0 if not
 */
int rotl(node_t *inst)
{
	stack_t *top = inst->head;
	int num;

	if (!inst->head)
		return (0);

	num = inst->head->value;
	add_dnodeint_end(&top, num);
	stack_pop(inst);

	return (1);
}
